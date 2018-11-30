#ifndef WEAPON_H
#define WEAPON_H

#include <serializavel.h>
#include <QVector>
#include <weaponmaterial.h>

enum WeaponQuality {bad = 1, usable, common, nice, epic, legendary, titleworthy};
enum WeaponType {oneHandedSword, twoHandedSword, oneHandedAxe, twoHandedAxe, club, polearm, spear, dagger, knife, oneHandedHammer, twoHandedHammer};

class Weapon : public Serializavel {
private:
    WeaponQuality weaponQuality;
    WeaponType weaponType;
    int basePrice;
    int sellPrice;
    QVector<int> materialsID;
public:
    Weapon(WeaponType weaponType, QVector<WeaponMaterial*> materials);
    ~Weapon();

    static QString MapWeaponTypeToString(WeaponType i);
    static int MapTypeToMaterialCount(WeaponType t);

    static WeaponQuality MapQuality(int perc);
    static QString MapQualityToString(WeaponQuality q);
    static QString MapQualityToStyleSheet(WeaponQuality q);

    // Getters and Setters
    WeaponQuality getWeaponQuality() const;
    void setWeaponQuality(const WeaponQuality &value);
    int getBasePrice() const;
    void setBasePrice(int value);
    int getSellPrice() const;
    void setSellPrice(int value);
    WeaponType getWeaponType() const;
    void setWeaponType(const WeaponType &value);

    bool Serializar(QTextStream *stream);
    bool Deserializar(QTextStream *stream);
};

#endif // WEAPON_H
