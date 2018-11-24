#include "player.h"

Weapon *Player::getEquipedWeapon() const
{
    return equipedWeapon;
}

void Player::setEquipedWeapon(Weapon *value)
{
    equipedWeapon = value;
}

int Player::getActionsLeft() const
{
    return actionsLeft;
}

void Player::setActionsLeft(int value)
{
    actionsLeft = value;
}

int Player::getPlayerMoney() const
{
    return playerMoney;
}

void Player::setPlayerMoney(int value)
{
    playerMoney = value;
}

int Player::getSkillGatherer() const
{
    return skillGatherer;
}

void Player::setSkillGatherer(int value)
{
    skillGatherer = value;
}

QVector<Weapon *> *Player::getWeaponList()
{
    return &weaponList;
}

QVector<WeaponMaterial *> *Player::getMaterialList()
{
    return &materialList;
}

Player::Player(){
    this->setPlayerMoney(0);
    this->setSkillGatherer(1);
    this->setActionsLeft(6);
    this->getMaterialList()->clear();
    this->getWeaponList()->clear();
}


