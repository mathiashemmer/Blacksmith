/********************************************************************************
** Form generated from reading UI file 'weapondesigner.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPONDESIGNER_H
#define UI_WEAPONDESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeaponDesigner
{
public:
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QPushButton *pushButton_Build;
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_BuildPrice;
    QLabel *label_Quality;
    QLabel *label_SellPrice;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Evaluate;

    void setupUi(QDialog *WeaponDesigner)
    {
        if (WeaponDesigner->objectName().isEmpty())
            WeaponDesigner->setObjectName(QStringLiteral("WeaponDesigner"));
        WeaponDesigner->resize(718, 459);
        comboBox = new QComboBox(WeaponDesigner);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ICO/oneHadedSword.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon, QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 370, 30));
        groupBox = new QGroupBox(WeaponDesigner);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(400, 20, 291, 381));
        pushButton_Build = new QPushButton(WeaponDesigner);
        pushButton_Build->setObjectName(QStringLiteral("pushButton_Build"));
        pushButton_Build->setGeometry(QRect(610, 410, 81, 30));
        frame = new QFrame(WeaponDesigner);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 90, 211, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 191, 66));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_BuildPrice = new QLabel(layoutWidget);
        label_BuildPrice->setObjectName(QStringLiteral("label_BuildPrice"));

        verticalLayout_2->addWidget(label_BuildPrice);

        label_Quality = new QLabel(layoutWidget);
        label_Quality->setObjectName(QStringLiteral("label_Quality"));

        verticalLayout_2->addWidget(label_Quality);

        label_SellPrice = new QLabel(layoutWidget);
        label_SellPrice->setObjectName(QStringLiteral("label_SellPrice"));

        verticalLayout_2->addWidget(label_SellPrice);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton_Cancel = new QPushButton(WeaponDesigner);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(400, 410, 81, 30));
        pushButton_Evaluate = new QPushButton(WeaponDesigner);
        pushButton_Evaluate->setObjectName(QStringLiteral("pushButton_Evaluate"));
        pushButton_Evaluate->setGeometry(QRect(500, 410, 90, 30));

        retranslateUi(WeaponDesigner);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WeaponDesigner);
    } // setupUi

    void retranslateUi(QDialog *WeaponDesigner)
    {
        WeaponDesigner->setWindowTitle(QApplication::translate("WeaponDesigner", "Dialog", nullptr));
        comboBox->setItemText(0, QApplication::translate("WeaponDesigner", "One Handed Sword", nullptr));
        comboBox->setItemText(1, QApplication::translate("WeaponDesigner", "Two Handed Sword", nullptr));
        comboBox->setItemText(2, QApplication::translate("WeaponDesigner", "One Handed Axe", nullptr));

        groupBox->setTitle(QApplication::translate("WeaponDesigner", "Materials", nullptr));
        pushButton_Build->setText(QApplication::translate("WeaponDesigner", "Build", nullptr));
        label->setText(QApplication::translate("WeaponDesigner", "Build price:", nullptr));
        label_2->setText(QApplication::translate("WeaponDesigner", "Quality:", nullptr));
        label_3->setText(QApplication::translate("WeaponDesigner", "Sell price:", nullptr));
        label_BuildPrice->setText(QApplication::translate("WeaponDesigner", "0", nullptr));
        label_Quality->setText(QApplication::translate("WeaponDesigner", "0", nullptr));
        label_SellPrice->setText(QApplication::translate("WeaponDesigner", "0", nullptr));
        pushButton_Cancel->setText(QApplication::translate("WeaponDesigner", "Cancel", nullptr));
        pushButton_Evaluate->setText(QApplication::translate("WeaponDesigner", "Evaluate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeaponDesigner: public Ui_WeaponDesigner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPONDESIGNER_H
