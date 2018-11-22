#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <QDialog>

#include <player.h>
#include <materialanalizer.h>

namespace Ui {
class InventoryManager;
}

class InventoryManager : public QDialog
{
    Q_OBJECT

private:
    Player *mainPlayer;

public:
    explicit InventoryManager(QWidget *parent = nullptr, Player *mainPlayer = nullptr);
    ~InventoryManager();

    void UpdateUI();

private slots:
    void on_tableWidget_Weapons_cellDoubleClicked(int row, int column);

    void on_pushButton_trash_clicked();

private:
    Ui::InventoryManager *ui;
};

#endif // INVENTORYMANAGER_H
