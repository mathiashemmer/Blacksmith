#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>

#include <player.h>
#include <soundmanager.h>
#include <weapon.h>
#include <weaponmaterial.h>
#include <weapondesigner.h>
#include <inventorymanager.h>
#include <expeditionmanager.h>

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT
private:
    Player *mainPlayer;
    SoundManager *mainSound;

    QVector<int> buffRange;
    int buffAmmount;

    QVector<int> debuffRange;
    int debuffAmmount;
public:
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();

    void EndDay();

   //Gatters and Setters

private slots:
    void on_pushButton_NewTool_clicked();
    void on_pushButton_GetterMaterials_clicked();
    void on_pushButton_Inventory_clicked();
    void on_horizontalSlider_sliderMoved(int position);
    void on_pushButton_pauseMusic_clicked();
    void on_pushButton_nextMusic_clicked();

    void on_pushButton_EndDay_clicked();

    void on_pushButton_SaveGame_clicked();

private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
