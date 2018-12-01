#include "maingame.h"
#include "ui_maingame.h"

MainGame::MainGame(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainGame){
    ui->setupUi(this);
    MainGame::showMaximized();

    mainPlayer = new Player();
    mainSound = new SoundManager();

    buffAmmount = 0;
    debuffAmmount = 0;

    mainPlayer->setGold(100);

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));
}

MainGame::~MainGame(){
    delete ui;
}

void MainGame::EndDay(){
    int unusedAction = mainPlayer->getActionsLeft();
    bool soldSomething = false;
    int ammountEarned = 0;
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
        soldSomething = true;
        ammountEarned += w->getSellPrice();
        delete(w);
    }
    if(soldSomething)
        QMessageBox::warning(this, "You Sold Something!", "Today was a good day, and you sold stuff. Earnend " + QString::number(ammountEarned) + " gold.");
    else
        QMessageBox::warning(this, "A Sad Day...", "You sold nothing today... Maybe tomorrow?");

    int goldLost = rand() % 10 + rand() % 5 * rand() % 10;
    QMessageBox::warning(this, "Daily Payout", "You pay your rents, your living cost, and stuff for your family. Today you lost " + QString::number(goldLost) + " gold.");
    mainPlayer->addGold(-goldLost);

    //Reset stuff for the next day
    mainPlayer->setActionsLeft(6);
    buffAmmount = 0;
    debuffAmmount = 0;
    buffRange.clear();
    debuffRange.clear();
    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));

    if(mainPlayer->getGold() <= 0){
        ui->pushButton_EndDay->setDisabled(true);
        ui->pushButton_GetterMaterials->setDisabled(true);
        ui->pushButton_Inventory->setDisabled(true);
        ui->pushButton_NewTool->setDisabled(true);
        QMessageBox::warning(this, "You Lost", "No money, no food, no energy... Try reloading or starting a new game.");
    }
}

void MainGame::on_pushButton_NewTool_clicked(){
    if(mainPlayer->getActionsLeft() <= 0){
        QMessageBox::warning(this, "No Actions Left", "You ran out of actions for today, end this day and sleep...");
        return;
    }
    WeaponDesigner *DesignerWindow = new WeaponDesigner(this, mainPlayer);
    DesignerWindow->exec();
    delete DesignerWindow;

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));
}


// ========================================================================================== //
// Gathering events go here. Will change the logic later, for now its just the basics         //
// ========================================================================================== //
void MainGame::on_pushButton_GetterMaterials_clicked(){
    if(mainPlayer->getActionsLeft() <= 0){
        QMessageBox::warning(this, "No Actions Left", "You ran out of actions for today, end this day and sleep...");
        return;
    }
    expeditionmanager *man = new expeditionmanager(this, mainPlayer, mainSound);
    man->exec();
    delete man;

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));
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
    QFile playerItens("GameData/PlayerItens.txt");
    playerItens.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream dataStream(&playerItens);
    for(auto mat : *mainPlayer->getMaterialList()){
        mat->Serializar(&dataStream);
    }

    QFile playerWeapons("GameData/PlayerWeapons.txt");
    playerWeapons.open(QIODevice::ReadWrite | QIODevice::Truncate);
    dataStream.setDevice(&playerWeapons);
    for(auto weap : *mainPlayer->getWeaponList()){
        weap->Serializar(&dataStream);
    }

    QFile playerData("GameData/PlayerData.txt");
    playerData.open(QIODevice::ReadWrite | QIODevice::Truncate);
    dataStream.setDevice(&playerData);
    mainPlayer->Serializar(&dataStream);

    QMessageBox::warning(this, "Save Sucessfull", "Data Saved from device.");
}

void MainGame::on_pushButton_LoadGame_clicked(){
    QFile playerItens("GameData/PlayerItens.txt");
    playerItens.open(QIODevice::ReadOnly);
    QTextStream dataStream(&playerItens);
    while(!dataStream.atEnd()){
        WeaponMaterial *newMat = new WeaponMaterial();
        newMat->Deserializar(&dataStream);
        mainPlayer->getMaterialList()->append(newMat);
    }

    QFile playerWeapons("GameData/PlayerWeapons.txt");
    playerWeapons.open(QIODevice::ReadOnly);
    dataStream.setDevice(&playerWeapons);
    while(!dataStream.atEnd()){
        Weapon *newWeap = new Weapon();
        newWeap->Deserializar(&dataStream);
        mainPlayer->getWeaponList()->append(newWeap);
    }

    QFile playerData("GameData/PlayerData.txt");
    playerData.open(QIODevice::ReadOnly);
    dataStream.setDevice(&playerData);
    mainPlayer->Deserializar(&dataStream);

    ui->label->setText("Actions left: " + QString::number(mainPlayer->getActionsLeft()) + " / 6");
    ui->label_Gold->setText("Gold: " + QString::number(mainPlayer->getGold()));

    QMessageBox::warning(this, "Load Sucessfull", "Data loaded from device.");
}
