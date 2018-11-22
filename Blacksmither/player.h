#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <weapon.h>
#include <weaponmaterial.h>

class Player
{
private:
    int skillGatherer;
    int playerMoney;

    QVector<Weapon*> weaponList;
    QVector<WeaponMaterial*> materialList;

    Weapon *equipedWeapon;
public:
    Player();
    int getPlayerMoney() const;
    void setPlayerMoney(int value);
    int getSkillGatherer() const;
    void setSkillGatherer(int value);
    QVector<Weapon *>* getWeaponList();
    QVector<WeaponMaterial *>* getMaterialList();
    Weapon *getEquipedWeapon() const;
    void setEquipedWeapon(Weapon *value);
};

#endif // PLAYER_H
