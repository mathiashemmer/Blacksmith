#include "expeditionmanager.h"
#include "ui_expeditionmanager.h"

expeditionmanager::expeditionmanager(QWidget *parent) :QDialog(parent),ui(new Ui::expeditionmanager){
    ui->setupUi(this);

    connect(ui->option1, &QAbstractButton::pressed, this, [this]{ProcessAction(1);});
    connect(ui->option2, &QAbstractButton::pressed, this, [this]{ProcessAction(2);});
    connect(ui->option3, &QAbstractButton::pressed, this, [this]{ProcessAction(3);});
    connect(ui->option4, &QAbstractButton::pressed, this, [this]{ProcessAction(4);});
}

expeditionmanager::~expeditionmanager()
{
    delete ui;
}

void expeditionmanager::ProcessAction(int action){
    if(action == 4) // Search and Return
        EndExpedition();
    if(1 == 1){
        EndExpedition();
    }
    if(action == 1){
        QMessageBox::warning(this, "curEvent", "sadas");
        //myLocation = myLocation->nextLocalLeft;
    }else if(action == 2){
        //myLocation = myLocation->nextLocalRight;
    }
}

void expeditionmanager::EndExpedition(){
    this->close();
}
