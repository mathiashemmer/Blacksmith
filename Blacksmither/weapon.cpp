#include "weapon.h"

Weapon::Weapon(int weaponType, QVector<WeaponMaterial*> materials){
    this->setWeaponType(Weapon::IndexToWeaponType(weaponType)); // Assign the weapon type
    if(materials.length() > this->weaponType){
        // If the passed material list is greater than the accepted by the weapon, this should throw some kind of error
        materials.resize(this->weaponType); // For now, it just ignores the excess materials, discarding them
    }
    this->setMainMaterials(materials);
    this->CalculateQuality();
    this->CalculateBasePrice();
}

Weapon::~Weapon()
{

}

WeaponQuality Weapon::getWeaponQuality() const
{
    return weaponQuality;
}

void Weapon::setWeaponQuality(const WeaponQuality &value)
{
    weaponQuality = value;
}

int Weapon::getBasePrice() const
{
    return basePrice;
}

void Weapon::setBasePrice(int value)
{
    basePrice = value;
}

int Weapon::getSellPrice() const
{
    return sellPrice;
}

void Weapon::setSellPrice(int value)
{
    sellPrice = value;
}

WeaponType Weapon::getWeaponType() const
{
    return weaponType;
}

void Weapon::setWeaponType(const WeaponType &value)
{
    weaponType = value;
}

QVector<WeaponMaterial*> Weapon::getMainMaterials() const
{
    return mainMaterials;
}

void Weapon::setMainMaterials(const QVector<WeaponMaterial*> &value)
{
    mainMaterials = value;
}

void Weapon::CalculateQuality(){
    // Materials quality: {mixture = 1, impure, neutral, purified, pure};
    int matAmmout = this->getWeaponType();      // Get maximum material ammout
    int maxQuality = matAmmout * MAX_QUALITY;   // Get maximum quality value (as of 1.0 this value is 5)
    int currMatQuality = 0;                     //Holds the sum of the materials quality

    for(auto mat : this->getMainMaterials()){   //
        currMatQuality += mat->getQuality();    // Sum the quality values of the weapon material
    }                                           //
    int qualityPerc = currMatQuality * 100 / maxQuality;    // Gets the percentage of the materials in relation to the maximum value
    this->setWeaponQuality(MapQuality(qualityPerc));        // Map the quality based on the percentage
}

void Weapon::CalculateBasePrice(){
    int currPrice = 0;
    for(auto mat : this->getMainMaterials()){
        currPrice += mat->getQuality();
    }
    this->setBasePrice(currPrice);
}

WeaponType Weapon::IndexToWeaponType(int i)
{
    switch (i) {
    case 0: return WeaponType::oneHandedSword;
    case 1: return WeaponType::twoHandedSword;
    case 2: return WeaponType::oneHandedAxe;
    }
    return WeaponType::oneHandedSword;
}

WeaponQuality Weapon::MapQuality(int perc)
{
    if(perc < 30)
        return WeaponQuality::bad;
    else if(perc >= 30 && perc <= 39)
        return WeaponQuality::usable;
    else if(perc >= 40 && perc <= 59)
        return  WeaponQuality::common;
    else if(perc >= 60 && perc <= 79)
        return WeaponQuality::nice;
    else if(perc >= 80 && perc <= 89)
        return WeaponQuality::epic;
    else if(perc >= 90 && perc <= 95)
        return WeaponQuality::legendary;
    else
        return  WeaponQuality::titleworthy;
}

QString Weapon::MapQualityToString(WeaponQuality q)
{
    // enum WeaponQuality {bad = 1, usable, common, nice, epic, legendary, titleworthy};
    switch (q) {
        case 1: return "Bad";
        case 2: return "Usable";
        case 3: return "Common";
        case 4: return "Nice";
        case 5: return "Epic";
        case 6: return "Legendary";
        case 7: return "Titleworthy";
    }
    return "Bad";
}
