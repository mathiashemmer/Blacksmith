#ifndef WEAPONDESIGNER_H
#define WEAPONDESIGNER_H

#include <QDialog>
#include <QVector>
#include <QComboBox>

#include <player.h>
#include <weaponmaterial.h>

namespace Ui {
class WeaponDesigner;
}

class WeaponDesigner : public QDialog
{
    Q_OBJECT

public:
    QVector<QComboBox*> materialsCB;
    Player *mainPlayer;

    explicit WeaponDesigner(QWidget *parent = nullptr, Player *p = nullptr);
    ~WeaponDesigner();

    void FillFormWithMaterialSelection(int size);

private slots:
    void on_pushButton_Evaluate_clicked();
    void on_pushButton_Cancel_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::WeaponDesigner *ui;
};

#endif // WEAPONDESIGNER_H
