#include "weaponmaterial.h"

MaterialType WeaponMaterial::getMyType() const
{
    return myType;
}

void WeaponMaterial::setMyType(const MaterialType &value)
{
    myType = value;
}

MaterialQuality WeaponMaterial::getQuality() const
{
    return quality;
}

void WeaponMaterial::setQuality(const MaterialQuality &value)
{
    quality = value;
}

int WeaponMaterial::getMyPrice() const
{
    return myPrice;
}

void WeaponMaterial::setMyPrice(int value)
{
    myPrice = value;
}

QString WeaponMaterial::getMaterialIconPath() const
{
    return materialIconPath;
}

void WeaponMaterial::setMaterialIconPath(const QString &value)
{
    materialIconPath = value;
}

bool WeaponMaterial::Serializar(QTextStream *dataStream){
    *dataStream << QString::number(this->getMyPrice()) << ";";
    *dataStream << QString::number(this->getMyType()) << ";";
    *dataStream << QString::number(this->getQuality()) << ";";
    *dataStream << this->getMaterialIconPath() << ";\r\n";
    return true;
}

bool WeaponMaterial::Deserializar(QTextStream *dataStream){
    QString textData = dataStream->readLine();
    QStringList segmentedData = textData.split(";");

    this->setMyPrice(segmentedData[0].toInt());
    this->setMyType((MaterialType)segmentedData[1].toInt());
    this->setQuality((MaterialQuality)segmentedData[2].toInt());
    this->setMaterialIconPath(segmentedData[3]);
    return true;

}



WeaponMaterial::WeaponMaterial()
{
    
}

WeaponMaterial::WeaponMaterial(MaterialType type, MaterialQuality quality, int price)
{
    this->setMyType(type);
    this->setQuality(quality);
    this->setMyPrice(price);
}

QString WeaponMaterial::MapTypeToString(MaterialType t){
    //enum MaterialType {wood = 1, copper, iron, bronze, steel, gold};
    switch (t) {
    case 1: return "Wood";
    case 2: return "Copper";
    case 3: return "Iron";
    case 4: return "Bronze";
    case 5: return "Steel";
    case 6: return "Gold";
    default: return "NullType";
    }
}

QString WeaponMaterial::MapQualityToString(MaterialQuality q){
    // enum MaterialQuality {mixture = 1, impure, neutral, purified, pure};
    switch (q) {
    case 1: return "Mixture";
    case 2: return "Impure";
    case 3: return "Neutral";
    case 4: return "Purified";
    case 5: return "Pure";
    default: return "nullQuality";
    }
}

QString WeaponMaterial::MapQualityToStyleSheet(MaterialQuality q){
    switch (q) {
    case 1: return "color: rgb(200,200,200)";
    case 2: return "color: rgb(255,255,255)";
    case 3: return "color: rgb(35,100,255)";
    case 4: return "color: rgb(150,50,255)";
    case 5: return "color: rgb(255,180,50)";
    default: return "";
    }
}

int WeaponMaterial::GetMaxQuality(){
    return 5;
}

