#include "maingame.h"
#include "ui_maingame.h"


WeaponMaterial* GatherMaterials(int);

MainGame::MainGame(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainGame){
    ui->setupUi(this);
    MainGame::showMaximized();

    mainPlayer = new Player();
    mainSound = new SoundManager();

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold : 0");

    buffAmmount = 0;
    debuffAmmount = 0;
}

MainGame::~MainGame(){
    delete ui;
}

void MainGame::EndDay(){
    int unusedAction = mainPlayer->getActionsLeft();
    float baseSellChance = 20;

    auto playerWeaponList = mainPlayer->getWeaponList();
    QVector<Weapon*> soldWeapons;
    soldWeapons.clear();

    for(int i = unusedAction; i > 0; i--){
        for(auto w : *playerWeaponList){
            // Add buff and debuff to sell chance
            // Base chance = 20 +- (0~10)
            baseSellChance += (rand() % 20 - 10);
            if(buffRange.contains(w->getWeaponType()))
                baseSellChance += buffAmmount;
            if(debuffRange.contains(w->getWeaponType()))
                baseSellChance -= debuffAmmount;
            // Base graph = -4 + x² - (x³/8)
            float weaponQuality = (float)w->getWeaponQuality();
            float bonusFromQuality = -4 + (weaponQuality*weaponQuality) -(weaponQuality*weaponQuality*weaponQuality/8);
            baseSellChance += bonusFromQuality;

            float RNG = rand() % 100;
            if(RNG <= baseSellChance){
                playerWeaponList->removeOne(w);
                soldWeapons.append(w);
            }
        }
    }

    // Sell select weapons
    for(auto w : soldWeapons){
        mainPlayer->addGold(w->getSellPrice());
        delete(w);
    }

    //Reset stuff for the next day
    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));
    mainPlayer->setActionsLeft(6);
    buffAmmount = 0;
    debuffAmmount = 0;
    buffRange.clear();
    debuffRange.clear();
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
    expeditionmanager *man = new expeditionmanager();
    man->exec();

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
                    25 * rand() % 6);
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

void MainGame::on_pushButton_EndDay_clicked(){
    EndDay();
}

void MainGame::on_pushButton_SaveGame_clicked()
{
    QFile baga("teste.txt");
    baga.open(QIODevice::ReadWrite);

    QTextStream *dataStream = new QTextStream(&baga);
    for(auto mat : *mainPlayer->getMaterialList()){
        mat->Serializar(dataStream);
    }
}
