#ifndef EXPEDITIONMANAGER_H
#define EXPEDITIONMANAGER_H

#include <QDialog>
#include <QVector>
#include <QMessageBox>

#include <expeditionlocal.h>
#include <player.h>
#include <soundmanager.h>

namespace Ui {
class expeditionmanager;
}

class expeditionmanager : public QDialog
{
    Q_OBJECT
private:
    Player *mainPlayer;
    SoundManager *soundManager;
    int expeditionRange;
    ExpeditionLocal *currentLocal;
    QVector<ExpeditionLocal*> localMap;
public:
    explicit expeditionmanager(QWidget *parent = nullptr, Player *mainPlayer = nullptr, SoundManager *soundManager = nullptr);
    ~expeditionmanager();

    void ProcessAction(int action);
    void EndExpedition();
    bool Navigate(int action);

    void ReadFromFile();

private:
    Ui::expeditionmanager *ui;
};

#endif // EXPEDITIONMANAGER_H
