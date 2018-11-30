#ifndef WEAPONMATERIAL_H
#define WEAPONMATERIAL_H

#include <serializavel.h>
#include <QString>
#include <QFile>

#define MAX_QUALITY 5 // Update this value if more qualitys are added

enum MaterialType {nullMaterialId, wood, copper, iron, bronze, steel, gold};
enum MaterialQuality {nullidMaterialQualityId, mixture, impure, neutral, purified, pure};

class WeaponMaterial : public Serializavel
{
private:
    int ID;
    int myPrice;

    QString materialIconPath;

    MaterialType myType;
    MaterialQuality quality;
public:
    WeaponMaterial();
    WeaponMaterial(MaterialType type, MaterialQuality quality, int price);


    static QString MapTypeToString(MaterialType t);
    static QString MapQualityToString(MaterialQuality q);
    static QString MapQualityToStyleSheet(MaterialQuality q);
    static int MapTypeToValue(MaterialType t);

    static int GetMaxQuality();

    // Getters and Setters
    MaterialType getMyType() const;
    void setMyType(const MaterialType &value);
    MaterialQuality getQuality() const;
    void setQuality(const MaterialQuality &value);
    int getMyPrice() const;
    void setMyPrice(int value);
    QString getMaterialIconPath() const;
    void setMaterialIconPath(const QString &value);

    //Serializable
    bool Serializar(QTextStream *dataStream);
    bool Deserializar(QTextStream *dataStream);
};

#endif // WEAPONMATERIAL_H
