#include "maingame.h"
#include "ui_maingame.h"


WeaponMaterial* GatherMaterials(int);

MainGame::MainGame(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainGame){
    ui->setupUi(this);
    MainGame::showMaximized();

    mainPlayer = new Player();
    mainSound = new SoundManager();

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
}

MainGame::~MainGame(){
    delete ui;
}

void MainGame::on_pushButton_NewTool_clicked(){
    WeaponDesigner *DesignerWindow = new WeaponDesigner(this, mainPlayer);
    DesignerWindow->exec();
}


// ========================================================================================== //
// Gathering events go here. Will change the logic later, for now its just the basics         //
// ========================================================================================== //
void MainGame::on_pushButton_GetterMaterials_clicked(){
    WeaponMaterial *mat = GatherMaterials(1);
    if(mat != nullptr)
        mainPlayer->getMaterialList()->append(mat);
}

WeaponMaterial* GatherMaterials(int gatherSkill){
    WeaponMaterial *foundMaterial = nullptr;

    QMessageBox *mainEvent = new QMessageBox(nullptr);
    mainEvent->setText("As you leave your shop, you wander where should you look por resources...");
    mainEvent->addButton("Forest", QMessageBox::ButtonRole::ActionRole);
    mainEvent->addButton("Mines", QMessageBox::ButtonRole::ActionRole);
    mainEvent->addButton("Lake", QMessageBox::ButtonRole::ActionRole);
    mainEvent->addButton("Forget it, just leave...", QMessageBox::ButtonRole::ActionRole);
    int eventID = mainEvent->exec();
    switch (eventID) {
    case 0: // Forest
        foundMaterial = new WeaponMaterial(
                    (MaterialType)(rand() % 6 + 1),
                    (MaterialQuality)(rand() % 5 + 1),
                    25 * rand() % 6,
                    "Baga");
        foundMaterial->setMaterialIconPath(":/ICO/Hammer.png");
        QMessageBox::warning(nullptr, "Found!", "You found a <b>" +
                             WeaponMaterial::MapQualityToString(foundMaterial->getQuality()) + " " +
                             WeaponMaterial::MapTypeToString(foundMaterial->getMyType()) + "</b>!It is in your bag to use!");
        break;
    case 1: // Mines
        break;
    case 2: // Lake
        break;
    case 3: // Leave
        break;
    }
    return foundMaterial;
}
// ========================================================================================== //
// Inventory Manager code goes here                                                           //
// ========================================================================================== //

void MainGame::on_pushButton_Inventory_clicked(){
    InventoryManager *invManager = new InventoryManager(this, this->mainPlayer);
    invManager->exec();
}

void MainGame::on_horizontalSlider_sliderMoved(int position){
    mainSound->SetVolume(position);
}

void MainGame::on_pushButton_pauseMusic_clicked(){
    mainSound->PauseCurrent();
}

void MainGame::on_pushButton_nextMusic_clicked(){
    mainSound->NextSoundtrack();
}
