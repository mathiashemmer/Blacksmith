#include "inventorymanager.h"
#include "ui_inventorymanager.h"

InventoryManager::InventoryManager(QWidget *parent, Player *mainPlayer) :QDialog(parent), ui(new Ui::InventoryManager){
    ui->setupUi(this);
    this->mainPlayer = mainPlayer;
    ui->tableWidget_Weapons->setSelectionBehavior(QAbstractItemView::SelectRows);
    UpdateUI();
}

InventoryManager::~InventoryManager()
{
    delete ui;
}

void InventoryManager::UpdateUI(){
    int rowIndex = 0;
    ui->tableWidget_Weapons->clear();
    for(auto w : *mainPlayer->getMaterialList()){
        QTableWidgetItem *c1 = new QTableWidgetItem(WeaponMaterial::MapQualityToString(w->getQuality()), 1);
        QTableWidgetItem *c2 = new QTableWidgetItem(QString::number(w->getMyPrice()), 1);
        QTableWidgetItem *c3 = new QTableWidgetItem(WeaponMaterial::MapTypeToString(w->getMyType()), 1);
        ui->tableWidget_Weapons->setRowCount(mainPlayer->getMaterialList()->length());
        ui->tableWidget_Weapons->setItem(rowIndex, 0, c2);
        ui->tableWidget_Weapons->setItem(rowIndex, 1, c1);
        ui->tableWidget_Weapons->setItem(rowIndex, 2, c3);
        rowIndex++;
    }
}

void InventoryManager::on_tableWidget_Weapons_cellDoubleClicked(int row, int column){
    WeaponMaterial *selectedMaterial = mainPlayer->getMaterialList()->at(row);
    MaterialAnalizer *matAnalizer = new MaterialAnalizer(this, selectedMaterial);
    matAnalizer->setWindowTitle("Material Inspector");
    matAnalizer->exec();
}

void InventoryManager::on_pushButton_trash_clicked(){
    int selectedIndex = ui->tableWidget_Weapons->selectionModel()->selectedIndexes().at(0).row();
    mainPlayer->getMaterialList()->removeAt(selectedIndex);
    UpdateUI();
}
