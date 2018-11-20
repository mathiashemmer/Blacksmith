/********************************************************************************
** Form generated from reading UI file 'maingame.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGame
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_NewTool;
    QPushButton *pushButton_GetterMaterials;
    QPushButton *pushButton_Inventory;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainGame)
    {
        if (MainGame->objectName().isEmpty())
            MainGame->setObjectName(QStringLiteral("MainGame"));
        MainGame->resize(709, 282);
        centralWidget = new QWidget(MainGame);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 251, 191));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 230, 160));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_NewTool = new QPushButton(widget);
        pushButton_NewTool->setObjectName(QStringLiteral("pushButton_NewTool"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_NewTool->sizePolicy().hasHeightForWidth());
        pushButton_NewTool->setSizePolicy(sizePolicy);
        pushButton_NewTool->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ICO/Hammer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_NewTool->setIcon(icon);
        pushButton_NewTool->setIconSize(QSize(16, 16));
        pushButton_NewTool->setFlat(true);

        gridLayout->addWidget(pushButton_NewTool, 0, 0, 1, 1);

        pushButton_GetterMaterials = new QPushButton(widget);
        pushButton_GetterMaterials->setObjectName(QStringLiteral("pushButton_GetterMaterials"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_GetterMaterials->sizePolicy().hasHeightForWidth());
        pushButton_GetterMaterials->setSizePolicy(sizePolicy1);
        QFont font;
        font.setStrikeOut(false);
        pushButton_GetterMaterials->setFont(font);
        pushButton_GetterMaterials->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ICO/Gather.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GetterMaterials->setIcon(icon1);
        pushButton_GetterMaterials->setIconSize(QSize(16, 16));
        pushButton_GetterMaterials->setFlat(true);

        gridLayout->addWidget(pushButton_GetterMaterials, 1, 0, 1, 1);

        pushButton_Inventory = new QPushButton(widget);
        pushButton_Inventory->setObjectName(QStringLiteral("pushButton_Inventory"));
        sizePolicy1.setHeightForWidth(pushButton_Inventory->sizePolicy().hasHeightForWidth());
        pushButton_Inventory->setSizePolicy(sizePolicy1);
        pushButton_Inventory->setFont(font);
        pushButton_Inventory->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ICO/Bag.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Inventory->setIcon(icon2);
        pushButton_Inventory->setIconSize(QSize(16, 16));
        pushButton_Inventory->setFlat(true);

        gridLayout->addWidget(pushButton_Inventory, 2, 0, 1, 1);

        MainGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGame);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 26));
        MainGame->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainGame);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainGame->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainGame);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainGame->setStatusBar(statusBar);

        retranslateUi(MainGame);

        QMetaObject::connectSlotsByName(MainGame);
    } // setupUi

    void retranslateUi(QMainWindow *MainGame)
    {
        MainGame->setWindowTitle(QApplication::translate("MainGame", "MainGame", nullptr));
        groupBox->setTitle(QApplication::translate("MainGame", "Actions", nullptr));
        pushButton_NewTool->setText(QApplication::translate("MainGame", "New Tool", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_GetterMaterials->setToolTip(QApplication::translate("MainGame", "<html><head/><body><p>Goes out to getter some more materials for crafting. This options will cost some time in exchange off building goods. Affected by the <span style=\" font-weight:600;\">Gattering</span> ability.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_GetterMaterials->setText(QApplication::translate("MainGame", "Gather Materials", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Inventory->setToolTip(QApplication::translate("MainGame", "<html><head/><body><p>Goes out to getter some more materials for crafting. This options will cost some time in exchange off building goods. Affected by the <span style=\" font-weight:600;\">Gattering</span> ability.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Inventory->setText(QApplication::translate("MainGame", "Manage Inventory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGame: public Ui_MainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
