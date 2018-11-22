#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QVector>

#include <player.h>
#include <weapon.h>
#include <weaponmaterial.h>
#include <weapondesigner.h>
#include <inventorymanager.h>

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT
private:
   Player *mainPlayer;

public:
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();

   //Gatters and Setters

private slots:

    void on_pushButton_NewTool_clicked();
    void on_pushButton_GetterMaterials_clicked();
    void on_pushButton_Inventory_clicked();

private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
