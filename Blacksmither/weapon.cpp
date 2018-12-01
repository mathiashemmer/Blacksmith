#include "weapon.h"

Weapon::Weapon(){

}

Weapon::Weapon(WeaponType weaponType, QVector<WeaponMaterial*> materials){
    this->basePrice = 0;
    this->sellPrice = 0;
    this->setWeaponType(weaponType); // Assign the weapon type
    int maxQuality = MapTypeToMaterialCount(this->weaponType) * WeaponMaterial::GetMaxQuality();    // Get maximum quality value (as of 1.0 this value is 5)
    int currMatQuality = 0;                                                                        // Holds the sum of the materials quality
    int currPrice = 0;

    for(auto mat : materials){                  //
        currMatQuality += mat->getQuality();    // Sum the quality values of the weapon material
        currPrice += mat->getQuality();         // Sum base price
    }                                           //
    int qualityPerc = currMatQuality * 100 / maxQuality;    // Gets the percentage of the materials in relation to the maximum value
    this->setWeaponQuality(MapQuality(qualityPerc));        // Map the quality based on the percentage

    this->setBasePrice(currPrice);
    this->sellPrice = this->basePrice * (2+(float)this->weaponQuality)/4;
    //
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

bool Weapon::Serializar(QTextStream *stream){
    *stream << QString::number(this->basePrice) << ";";
    *stream << QString::number(this->sellPrice) << ";";
    *stream << QString::number(this->weaponQuality) << ";";
    *stream << QString::number(this->weaponType) << ";\r\n";
    return true;
}

bool Weapon::Deserializar(QTextStream *stream){
    QString textData = stream->readLine();
    QStringList segmentedData = textData.split(";");

    this->setBasePrice(segmentedData[0].toInt());
    this->setSellPrice(segmentedData[1].toInt());
    this->setWeaponQuality((WeaponQuality)segmentedData[2].toInt());
    this->setWeaponType((WeaponType)segmentedData[2].toInt());
    return true;
}

QString Weapon::MapWeaponTypeToString(WeaponType i)
{
    switch (i) {
    case 0: return "oneHandedSword";
    case 1: return "twoHandedSword";
    case 2: return "oneHandedAxe";
    case 3: return "twoHandedAxe";
    case 4: return "club";
    case 5: return "polearm";
    case 6: return "spear";
    case 7: return "dagger";
    case 8: return "knife";
    case 9: return "oneHandedHammer";
    case 10: return "twoHandedHammer";
    }
    return "nullweapontype";
}

//Defines the ammount of material needed to craft the weapon
int Weapon::MapTypeToMaterialCount(WeaponType t){
    // enum WeaponType {oneHandedSword, twoHandedSword, oneHandedAxe, twoHandedAxe, club, polearm, spear, dagger, knife, oneHandedHammer, twoHandedHammer};
    switch (t) {
    case 0: return 3;
    case 1: return 4;
    case 2: return 2;
    case 3: return 3;
    case 4: return 1;
    case 5: return 2;
    case 6: return 2;
    case 7: return 1;
    case 8: return 1;
    case 9: return 2;
    case 10: return 3;
    }
    return 3;
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

QString Weapon::MapQualityToStyleSheet(WeaponQuality q){
    switch (q) {
    case 1: return "color: rgb(100,100,100)";
    case 2: return "color: rgb(150,150,150)";
    case 3: return "color: rgb(200,200,200)";
    case 4: return "color: rgb(35,100,255)";
    case 5: return "color: rgb(150,50,255)";
    case 6: return "color: rgb(255,50,150)";
    case 7: return "color: rgb(255,180,50)";
    }
    return "color: rgb(255,255,255)";
}
