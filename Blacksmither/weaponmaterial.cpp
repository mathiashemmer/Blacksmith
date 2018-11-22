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

QString WeaponMaterial::getMaterialName() const
{
    return materialName;
}

void WeaponMaterial::setMaterialName(const QString &value)
{
    materialName = value;
}

QString WeaponMaterial::getMaterialIconPath() const
{
    return materialIconPath;
}

void WeaponMaterial::setMaterialIconPath(const QString &value)
{
    materialIconPath = value;
}

WeaponMaterial::WeaponMaterial()
{
    
}

WeaponMaterial::WeaponMaterial(MaterialType type, MaterialQuality quality, int price, QString name){
    this->setMyType(type);
    this->setQuality(quality);
    this->setMyPrice(price);
    this->setMaterialName(name);
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
    }
    return "nullType";
}

QString WeaponMaterial::MapQualityToString(MaterialQuality q){
    // enum MaterialQuality {mixture = 1, impure, neutral, purified, pure};
    switch (q) {
    case 1: return "Mixture";
    case 2: return "Impure";
    case 3: return "Neutral";
    case 4: return "Purified";
    case 5: return "Pure";
    }
    return "nullQuality";
}

