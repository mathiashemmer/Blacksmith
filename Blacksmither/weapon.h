#ifndef WEAPON_H
#define WEAPON_H

#include <QVector>
#include <weaponmaterial.h>

enum WeaponQuality {bad = 1, usable, common, nice, epic, legendary, titleworthy};
// Map material ammount to weapon type
enum WeaponType {oneHandedSword = 3, twoHandedSword = 4, oneHandedAxe = 2};

class Weapon {
private:
    WeaponQuality weaponQuality;
    WeaponType weaponType;
    int basePrice;
    int sellPrice;

    QVector<WeaponMaterial*> mainMaterials;
public:
    Weapon(int weaponType, QVector<WeaponMaterial*> materials);
    ~Weapon();

    void CalculateQuality();
    void CalculateBasePrice();

    static WeaponType IndexToWeaponType(int i);

    static WeaponQuality MapQuality(int perc);
    static QString MapQualityToString(WeaponQuality q);

    // Getters and Setters
    WeaponQuality getWeaponQuality() const;
    void setWeaponQuality(const WeaponQuality &value);
    int getBasePrice() const;
    void setBasePrice(int value);
    int getSellPrice() const;
    void setSellPrice(int value);
    WeaponType getWeaponType() const;
    void setWeaponType(const WeaponType &value);
    QVector<WeaponMaterial*> getMainMaterials() const;
    void setMainMaterials(const QVector<WeaponMaterial*> &value);
};

#endif // WEAPON_H
