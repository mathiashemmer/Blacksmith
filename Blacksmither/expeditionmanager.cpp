#include "expeditionmanager.h"
#include "ui_expeditionmanager.h"

expeditionmanager::expeditionmanager(QWidget *parent, Player *mainPlayer, SoundManager *soundManager) :QDialog(parent),ui(new Ui::expeditionmanager){
    ui->setupUi(this);

    connect(ui->option1, &QAbstractButton::pressed, this, [this]{ProcessAction(1);});
    connect(ui->option2, &QAbstractButton::pressed, this, [this]{ProcessAction(2);});
    connect(ui->option3, &QAbstractButton::pressed, this, [this]{ProcessAction(3);});

    this->expeditionRange = 0;
    this->mainPlayer = mainPlayer;
    this->soundManager = soundManager;

    ReadFromFile();

    this->currentLocal = localMap.at(0);
    this->setWindowTitle(currentLocal->getLocalName());
    ui->eventLog->append(currentLocal->getLocalDescp());
    ui->option1->setText(currentLocal->getLocalIDLeft());
    ui->option2->setText(currentLocal->getLocalIDRight());

    soundManager->getMainPlayer()->setMedia(QUrl("qrc:/WAV/soulsplit-adventure-theme.mp3"));
    soundManager->getMainPlayer()->play();
}

expeditionmanager::~expeditionmanager()
{
    soundManager->ResetPlayList();
    delete ui;
}

void expeditionmanager::ProcessAction(int action){
    if(action == 3) // Search and Return
        EndExpedition();

    if((action == 1 && currentLocal->getLocalIDLeft() == "a") || (action == 2 && currentLocal->getLocalIDRight() == "a"))
        EndExpedition();
    if(Navigate(action)){
        if(currentLocal->getLocalName() == "Deep Shadows"){
            soundManager->getMainPlayer()->setMedia(QUrl("qrc:/WAV/creepy-forest.mp3"));
            soundManager->getMainPlayer()->play();
        }

        this->expeditionRange++;

        this->setWindowTitle(currentLocal->getLocalName());
        ui->eventLog->append(currentLocal->getLocalDescp() + "\r\n");

        ui->option1->setText(currentLocal->getLocalIDLeft());
        ui->option2->setText(currentLocal->getLocalIDRight());

        if(currentLocal->getLocalIDLeft() == "a"){
            ui->option1->setText("Gather and go back");
        }
        if(currentLocal->getLocalIDRight() == "a"){
            ui->option2->setText("Gather and go back");
        }
    }
}

void expeditionmanager::EndExpedition(){
    WeaponMaterial *foundMaterial = new WeaponMaterial(
    (MaterialType)(rand() % 6 + 1),
    (MaterialQuality)(rand() % 5 + 1),
    25 * rand() % 6);

    foundMaterial->setMaterialIconPath(":/ICO/Hammer.png");
    QMessageBox::warning(nullptr, "Found!", "You found a <b>" +
                         WeaponMaterial::MapQualityToString(foundMaterial->getQuality()) + " " +
                         WeaponMaterial::MapTypeToString(foundMaterial->getMyType()) + "</b>!It is in your bag to use!");

    mainPlayer->getMaterialList()->append(foundMaterial);
    mainPlayer->addActionsLeft(-1);
    this->close();
}

bool expeditionmanager::Navigate(int action){
    for(auto el : localMap){
        switch (action) {
            case 1:
                if(el->getLocalName() == currentLocal->getLocalIDLeft() && el->getLocalName() != currentLocal->getLocalName()){
                    currentLocal = el;
                    return true;
                }
            break;
            case 2:
                if(el->getLocalName() == currentLocal->getLocalIDRight() && el->getLocalName() != currentLocal->getLocalName()){
                    currentLocal = el;
                    return true;
                }
        }
    }
    return false;
}

void expeditionmanager::ReadFromFile(){
    this->localMap.clear();

    QFile file("ExpeditionLocals.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream data(&file);

    while(!data.atEnd()){
        ExpeditionLocal *newLocal = new ExpeditionLocal();
        newLocal->Deserializar(&data);
        localMap.append(newLocal);
    }
}
