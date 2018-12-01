#include "weapondesigner.h"
#include "ui_weapondesigner.h"

#include <weapon.h>

WeaponDesigner::WeaponDesigner(QWidget *parent, Player *p) : QDialog(parent), ui(new Ui::WeaponDesigner)
{
    ui->setupUi(this);
    this->mainPlayer = p;
    int currWeaponType = ui->comboBox->currentIndex();
    FillFormWithMaterialSelection(Weapon::MapTypeToMaterialCount((WeaponType)currWeaponType));
}

WeaponDesigner::~WeaponDesigner()
{
    delete ui;
}

void WeaponDesigner::FillFormWithMaterialSelection(int size){
    for(auto cb : materialsCB){
        delete cb;
    }
    materialsCB.clear();
    for(int i = 0; i < size; i++){
        QComboBox *newCombo = new QComboBox(this);
        for(auto m : *mainPlayer->getMaterialList()){ newCombo->addItem(WeaponMaterial::MapTypeToString(m->getMyType()) + "-" + WeaponMaterial::MapQualityToString(m->getQuality()));};
        newCombo->setGeometry(500, 40+i*30, 140, 20);
        newCombo->show();
        materialsCB.append(newCombo);
    }
}

bool WeaponDesigner::ValidateSelectedMaterials(){
    int matLenght = materialsCB.length();
    if(matLenght <= 0)
        return false;
    for(int i = 0; i < matLenght; i++){
        QComboBox *curCB = materialsCB.at(i);
        for(int j = i+1; j < matLenght; j++){
            if(curCB->currentIndex() == materialsCB.at(j)->currentIndex())
                return false;
        }
    }
    return true;
}

void WeaponDesigner::on_comboBox_currentIndexChanged(const QString &arg1)
{
    int currWeaponType = ui->comboBox->currentIndex();
    FillFormWithMaterialSelection(Weapon::MapTypeToMaterialCount((WeaponType)currWeaponType));
}

void WeaponDesigner::on_pushButton_Evaluate_clicked()
{
    if(mainPlayer->getMaterialList()->length() <= 0)
        return;                         // No materials on Player Inventory
    if(!ValidateSelectedMaterials()){
        QMessageBox::warning(this, "Invalid material choice!", "You selected the same material for one or more material slots, please change one of the to another!");
        return;
    }

    int buildPrice = 0, sellPrice = 0;
    int currWeaponType = ui->comboBox->currentIndex();
    float qualityPerc = 0;

    for(auto cb : materialsCB){
        int materialIndex = cb->currentIndex();
        buildPrice += mainPlayer->getMaterialList()->at(materialIndex)->getMyPrice();
        qualityPerc += mainPlayer->getMaterialList()->at(materialIndex)->getQuality();
    }

    qualityPerc = qualityPerc * 100 / (Weapon::MapTypeToMaterialCount((WeaponType)currWeaponType)*MAX_QUALITY);
    WeaponQuality thisQuality = Weapon::MapQuality(qualityPerc);
    sellPrice = buildPrice * (2+(float)thisQuality)/4;

    ui->label_BuildPrice->setText(QString::number(buildPrice));
    ui->label_BuildPrice->setStyleSheet("color: rgb(190, 190, 0)");
    ui->label_Quality->setText(Weapon::MapQualityToString(thisQuality));
    ui->label_Quality->setStyleSheet(Weapon::MapQualityToStyleSheet(thisQuality));
    ui->label_SellPrice->setText(QString::number(sellPrice));
    ui->label_SellPrice->setStyleSheet("color: rgb(190, 190, 0)");

    QSoundEffect *soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/WAV/hammering2.wav"));
    soundEffect->play();
    QTimer::singleShot(500 + (rand()%200 - 100), soundEffect, SLOT(play()));
    QTimer::singleShot(1000 + (rand()%200 - 100), soundEffect, SLOT(play()));
}

void WeaponDesigner::on_pushButton_Cancel_clicked()
{
    this->close();
}


void WeaponDesigner::on_pushButton_Build_clicked(){
    if(!ValidateSelectedMaterials()){
        QMessageBox::warning(this, "Invalid material choice!", "You selected the same material for one or more material slots, please change one of the to another!");
        return;
    }

    //Scan the selected materials from the list and add them to a pre-delete list. This needs to be done like this, since the material selection is index based
    //So, removing while scanning changes the index.

    QVector<WeaponMaterial*> selectedMat;
    for(auto cb : materialsCB){
        WeaponMaterial *cur = mainPlayer->getMaterialList()->at(cb->currentIndex());
        selectedMat.append(cur);
    }
    for(auto mat : selectedMat){
        mainPlayer->getMaterialList()->removeOne(mat);
    }

    //Refresh the weapon material UI
    FillFormWithMaterialSelection(Weapon::MapTypeToMaterialCount((WeaponType)ui->comboBox->currentIndex()));

    QSoundEffect *soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/WAV/hammering1.wav"));
    soundEffect->play();
    QTimer::singleShot(500 + (rand()%200 - 100), soundEffect, SLOT(play()));
    QTimer::singleShot(1000 + (rand()%200 - 100), soundEffect, SLOT(play()));

    int currWeaponType = ui->comboBox->currentIndex();
    Weapon *newWeapon = new Weapon((WeaponType)currWeaponType, selectedMat);
    mainPlayer->getWeaponList()->append(newWeapon);
    mainPlayer->addActionsLeft(-1);
}
