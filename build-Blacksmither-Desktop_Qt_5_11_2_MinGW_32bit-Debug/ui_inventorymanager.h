/********************************************************************************
** Form generated from reading UI file 'inventorymanager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYMANAGER_H
#define UI_INVENTORYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryManager
{
public:
    QTableWidget *tableWidget_Weapons;
    QPushButton *pushButton_trash;

    void setupUi(QDialog *InventoryManager)
    {
        if (InventoryManager->objectName().isEmpty())
            InventoryManager->setObjectName(QStringLiteral("InventoryManager"));
        InventoryManager->resize(494, 400);
        tableWidget_Weapons = new QTableWidget(InventoryManager);
        if (tableWidget_Weapons->columnCount() < 3)
            tableWidget_Weapons->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Weapons->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Weapons->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Weapons->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_Weapons->rowCount() < 2)
            tableWidget_Weapons->setRowCount(2);
        tableWidget_Weapons->setObjectName(QStringLiteral("tableWidget_Weapons"));
        tableWidget_Weapons->setGeometry(QRect(20, 10, 451, 311));
        tableWidget_Weapons->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Weapons->setShowGrid(true);
        tableWidget_Weapons->setGridStyle(Qt::DotLine);
        tableWidget_Weapons->setCornerButtonEnabled(false);
        tableWidget_Weapons->setRowCount(2);
        tableWidget_Weapons->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Weapons->horizontalHeader()->setHighlightSections(true);
        tableWidget_Weapons->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Weapons->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Weapons->verticalHeader()->setVisible(false);
        tableWidget_Weapons->verticalHeader()->setDefaultSectionSize(25);
        tableWidget_Weapons->verticalHeader()->setHighlightSections(false);
        tableWidget_Weapons->verticalHeader()->setMinimumSectionSize(25);
        pushButton_trash = new QPushButton(InventoryManager);
        pushButton_trash->setObjectName(QStringLiteral("pushButton_trash"));
        pushButton_trash->setGeometry(QRect(20, 340, 110, 28));

        retranslateUi(InventoryManager);

        QMetaObject::connectSlotsByName(InventoryManager);
    } // setupUi

    void retranslateUi(QDialog *InventoryManager)
    {
        InventoryManager->setWindowTitle(QApplication::translate("InventoryManager", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Weapons->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryManager", "Sell Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Weapons->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryManager", "Quality", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Weapons->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryManager", "Item", nullptr));
        pushButton_trash->setText(QApplication::translate("InventoryManager", "Trash It", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryManager: public Ui_InventoryManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYMANAGER_H
