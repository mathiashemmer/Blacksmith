#ifndef WEAPONMATERIAL_H
#define WEAPONMATERIAL_H

#include <QString>
#include <QFile>

#define MAX_QUALITY 5 // Update this value if more qualitys are added

enum MaterialType {wood = 1, copper, iron, bronze, steel, gold};
enum MaterialQuality {mixture = 1, impure, neutral, purified, pure};

class WeaponMaterial
{
private:
    int myPrice;

    MaterialType myType;
    MaterialQuality quality;

    QString materialName;
    QString materialIconPath;
public:
    WeaponMaterial();
    WeaponMaterial(MaterialType type, MaterialQuality quality, int price, QString name);

    static QString MapTypeToString(MaterialType t);
    static QString MapQualityToString(MaterialQuality q);
    static int MapTypeToValue(MaterialType t);

    // Getters and Setters
    MaterialType getMyType() const;
    void setMyType(const MaterialType &value);
    MaterialQuality getQuality() const;
    void setQuality(const MaterialQuality &value);
    int getMyPrice() const;
    void setMyPrice(int value);
    QString getMaterialName() const;
    void setMaterialName(const QString &value);
    QString getMaterialIconPath() const;
    void setMaterialIconPath(const QString &value);
};

#endif // WEAPONMATERIAL_H
