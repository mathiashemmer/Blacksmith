#include "weapondesigner.h"
#include "ui_weapondesigner.h"

#include <weapon.h>

WeaponDesigner::WeaponDesigner(QWidget *parent, Player *p) : QDialog(parent), ui(new Ui::WeaponDesigner)
{
    ui->setupUi(this);
    this->mainPlayer = p;
    int currWeaponType = ui->comboBox->currentIndex();
    FillFormWithMaterialSelection(Weapon::IndexToWeaponType(currWeaponType));
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

void WeaponDesigner::on_comboBox_currentIndexChanged(const QString &arg1)
{
    int currWeaponType = ui->comboBox->currentIndex();
    FillFormWithMaterialSelection(Weapon::IndexToWeaponType(currWeaponType));
}

void WeaponDesigner::on_pushButton_Evaluate_clicked()
{
    if(mainPlayer->getMaterialList()->length() <= 0){   //
        return;                         // No materials on Player Inventory
    }                                   //

    int buildPrice = 0, sellPrice = 0;
    int currWeaponType = ui->comboBox->currentIndex();
    float qualityPerc = 0;

    for(auto cb : materialsCB){
        int materialIndex = cb->currentIndex();
        buildPrice += mainPlayer->getMaterialList()->at(materialIndex)->getMyPrice();
        qualityPerc += mainPlayer->getMaterialList()->at(materialIndex)->getQuality();
    }

    qualityPerc = qualityPerc * 100 / (Weapon::IndexToWeaponType(currWeaponType)*MAX_QUALITY);
    WeaponQuality thisQuality = Weapon::MapQuality(qualityPerc);
    sellPrice = buildPrice * (2+(float)thisQuality)/4;

    ui->label_BuildPrice->setText(QString::number(buildPrice));
    ui->label_Quality->setText(Weapon::MapQualityToString(thisQuality));
    ui->label_SellPrice->setText(QString::number(sellPrice));
}

void WeaponDesigner::on_pushButton_Cancel_clicked()
{
    this->close();
}


