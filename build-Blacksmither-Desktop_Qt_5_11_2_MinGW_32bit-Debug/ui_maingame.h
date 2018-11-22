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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGame
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_GetterMaterials;
    QPushButton *pushButton_NewTool;
    QPushButton *pushButton_EndDay;
    QPushButton *pushButton_Inventory;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainGame)
    {
        if (MainGame->objectName().isEmpty())
            MainGame->setObjectName(QStringLiteral("MainGame"));
        MainGame->resize(1020, 639);
        centralWidget = new QWidget(MainGame);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(200, 300));
        groupBox->setMaximumSize(QSize(300, 400));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_GetterMaterials = new QPushButton(groupBox);
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/ICO/Gather.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GetterMaterials->setIcon(icon);
        pushButton_GetterMaterials->setIconSize(QSize(16, 16));
        pushButton_GetterMaterials->setFlat(true);

        gridLayout->addWidget(pushButton_GetterMaterials, 2, 0, 1, 1);

        pushButton_NewTool = new QPushButton(groupBox);
        pushButton_NewTool->setObjectName(QStringLiteral("pushButton_NewTool"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_NewTool->sizePolicy().hasHeightForWidth());
        pushButton_NewTool->setSizePolicy(sizePolicy2);
        pushButton_NewTool->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ICO/Hammer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_NewTool->setIcon(icon1);
        pushButton_NewTool->setIconSize(QSize(16, 16));
        pushButton_NewTool->setFlat(true);

        gridLayout->addWidget(pushButton_NewTool, 0, 0, 1, 1);

        pushButton_EndDay = new QPushButton(groupBox);
        pushButton_EndDay->setObjectName(QStringLiteral("pushButton_EndDay"));
        sizePolicy1.setHeightForWidth(pushButton_EndDay->sizePolicy().hasHeightForWidth());
        pushButton_EndDay->setSizePolicy(sizePolicy1);
        pushButton_EndDay->setFont(font);
        pushButton_EndDay->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ICO/Bag.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EndDay->setIcon(icon2);
        pushButton_EndDay->setIconSize(QSize(16, 16));
        pushButton_EndDay->setFlat(true);

        gridLayout->addWidget(pushButton_EndDay, 4, 0, 1, 1);

        pushButton_Inventory = new QPushButton(groupBox);
        pushButton_Inventory->setObjectName(QStringLiteral("pushButton_Inventory"));
        sizePolicy1.setHeightForWidth(pushButton_Inventory->sizePolicy().hasHeightForWidth());
        pushButton_Inventory->setSizePolicy(sizePolicy1);
        pushButton_Inventory->setFont(font);
        pushButton_Inventory->setLayoutDirection(Qt::LeftToRight);
        pushButton_Inventory->setIcon(icon2);
        pushButton_Inventory->setIconSize(QSize(16, 16));
        pushButton_Inventory->setFlat(true);

        gridLayout->addWidget(pushButton_Inventory, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        gridLayout_3->addWidget(groupBox, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(200, 20));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 2, 1, 1, 1);

        MainGame->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGame);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1020, 26));
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
#ifndef QT_NO_TOOLTIP
        pushButton_GetterMaterials->setToolTip(QApplication::translate("MainGame", "<html><head/><body><p>Goes out to getter some more materials for crafting. This options will cost some time in exchange off building goods. Affected by the <span style=\" font-weight:600;\">Gattering</span> ability.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_GetterMaterials->setText(QApplication::translate("MainGame", "Gather Materials", nullptr));
        pushButton_NewTool->setText(QApplication::translate("MainGame", "New Tool", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_EndDay->setToolTip(QApplication::translate("MainGame", "<html><head/><body><p>Goes out to getter some more materials for crafting. This options will cost some time in exchange off building goods. Affected by the <span style=\" font-weight:600;\">Gattering</span> ability.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_EndDay->setText(QApplication::translate("MainGame", "End Day", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Inventory->setToolTip(QApplication::translate("MainGame", "<html><head/><body><p>Goes out to getter some more materials for crafting. This options will cost some time in exchange off building goods. Affected by the <span style=\" font-weight:600;\">Gattering</span> ability.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Inventory->setText(QApplication::translate("MainGame", "Manage Inventory", nullptr));
        label->setText(QApplication::translate("MainGame", "Texte de texo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGame: public Ui_MainGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
