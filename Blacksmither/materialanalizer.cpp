#include "materialanalizer.h"
#include "ui_materialanalizer.h"

WeaponMaterial *MaterialAnalizer::getCurrMaterial() const
{
    return currMaterial;
}

void MaterialAnalizer::setCurrMaterial(WeaponMaterial *value)
{
    currMaterial = value;
}

MaterialAnalizer::MaterialAnalizer(QWidget *parent, WeaponMaterial *mat) : QDialog(parent), ui(new Ui::MaterialAnalizer){
    ui->setupUi(this);
    this->setCurrMaterial(mat);
    UpdateUI();
}

MaterialAnalizer::~MaterialAnalizer()
{
    delete ui;
}

void MaterialAnalizer::UpdateUI(){
    if(currMaterial == nullptr)
        return;
    ui->label_image->setPixmap(QPixmap(currMaterial->getMaterialIconPath()));
    ui->label_Type_2->setText(WeaponMaterial::MapTypeToString(currMaterial->getMyType()));
    ui->label_Quality_2->setText(WeaponMaterial::MapQualityToString(currMaterial->getQuality()));
    ui->label_baseCost->setText(QString::number(currMaterial->getMyPrice()));
}
