#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <weapon.h>
#include <weaponmaterial.h>

class Player : public Serializavel
{
private:
    int skillGatherer;
    int actionsLeft;
    int gold;

    QVector<Weapon*> weaponList;
    QVector<WeaponMaterial*> materialList;

    Weapon *equipedWeapon;
public:
    Player();
    ~Player();

    bool Serializar(QTextStream *stream);
    bool Deserializar(QTextStream *stream);

    int getSkillGatherer() const;
    void setSkillGatherer(int value);
    QVector<Weapon *>* getWeaponList();
    QVector<WeaponMaterial *>* getMaterialList();
    Weapon *getEquipedWeapon() const;
    void setEquipedWeapon(Weapon *value);
    int getActionsLeft() const;
    void addActionsLeft(int value);
    void setActionsLeft(int value);
    int getGold() const;
    void addGold(int value);
    void setGold(int value);
};

#endif // PLAYER_H
