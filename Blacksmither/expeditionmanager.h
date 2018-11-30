#ifndef EXPEDITIONMANAGER_H
#define EXPEDITIONMANAGER_H

#include <QDialog>
#include <QVector>
#include <QMessageBox>

namespace Ui {
class expeditionmanager;
}

class expeditionmanager : public QDialog
{
    Q_OBJECT
private:
    int expeditionRange;
public:
    explicit expeditionmanager(QWidget *parent = nullptr);
    ~expeditionmanager();

    void ProcessAction(int action);
    void EndExpedition();

private:
    Ui::expeditionmanager *ui;
};

#endif // EXPEDITIONMANAGER_H
