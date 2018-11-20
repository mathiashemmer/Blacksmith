#ifndef MAINGAME_H
#define MAINGAME_H

#include <QMainWindow>
#include <QVector>

#include <player.h>
#include <weapon.h>
#include <weaponmaterial.h>
#include <weapondesigner.h>

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

private slots:

    void on_pushButton_NewTool_clicked();

    void on_pushButton_GetterMaterials_clicked();

private:
    Ui::MainGame *ui;
};

#endif // MAINGAME_H
