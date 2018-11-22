#ifndef MATERIALANALIZER_H
#define MATERIALANALIZER_H

#include <QDialog>

#include <weaponmaterial.h>

namespace Ui {
class MaterialAnalizer;
}

class MaterialAnalizer : public QDialog
{
    Q_OBJECT
private:
    WeaponMaterial *currMaterial;
public:
    explicit MaterialAnalizer(QWidget *parent = nullptr, WeaponMaterial *currMaterial = nullptr);
    ~MaterialAnalizer();

    void UpdateUI();

    WeaponMaterial *getCurrMaterial() const;
    void setCurrMaterial(WeaponMaterial *value);

private:
    Ui::MaterialAnalizer *ui;
};

#endif // MATERIALANALIZER_H
