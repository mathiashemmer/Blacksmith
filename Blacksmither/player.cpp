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

void Player::addActionsLeft(int value)
{
    actionsLeft += value;
}

void Player::setActionsLeft(int value)
{
    actionsLeft = value;
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

int Player::getGold() const
{
    return gold;
}

void Player::addGold(int value)
{
    gold += value;
}

void Player::setGold(int value)
{
    gold = value;
}

Player::Player(){
    materialList.clear();
    weaponList.clear();
    this->setGold(0);
    this->setSkillGatherer(1);
    this->setActionsLeft(6);
    this->getMaterialList()->clear();
    this->getWeaponList()->clear();
}

Player::~Player(){

}

bool Player::Serializar(QTextStream *stream){
    *stream << QString::number(skillGatherer) << ";";
    *stream << QString::number(actionsLeft) << ";";
    *stream << QString::number(gold) << "\r\n";
    return true;
}

bool Player::Deserializar(QTextStream *stream){
    QString textData = stream->readLine();
    QStringList segmentedData = textData.split(";");

    this->skillGatherer = segmentedData[0].toInt();
    this->actionsLeft = segmentedData[1].toInt();
    this->gold = segmentedData[2].toInt();

    return true;
}


