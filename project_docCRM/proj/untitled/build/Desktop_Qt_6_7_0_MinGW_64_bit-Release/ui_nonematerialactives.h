/********************************************************************************
** Form generated from reading UI file 'nonematerialactives.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NONEMATERIALACTIVES_H
#define UI_NONEMATERIALACTIVES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoneMaterialActives
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_kod;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_nazva;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_povna_nazva;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_vid_aktiva;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox_rakhunok_obliku;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_pochatkova_vartist;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_inventarnyy_nomer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_shifr;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *comboBox_odinitsya_vymiru;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDateEdit *dateEdit_data_vvodu;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QComboBox *comboBox_vid_diyalnosti;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *NoneMaterialActives)
    {
        if (NoneMaterialActives->objectName().isEmpty())
            NoneMaterialActives->setObjectName("NoneMaterialActives");
        NoneMaterialActives->resize(596, 459);
        groupBox = new QGroupBox(NoneMaterialActives);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 581, 451));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 50, 511, 341));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_kod = new QLineEdit(layoutWidget);
        lineEdit_kod->setObjectName("lineEdit_kod");
        lineEdit_kod->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEdit_kod);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_nazva = new QLineEdit(layoutWidget);
        lineEdit_nazva->setObjectName("lineEdit_nazva");

        horizontalLayout_2->addWidget(lineEdit_nazva);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit_povna_nazva = new QLineEdit(layoutWidget);
        lineEdit_povna_nazva->setObjectName("lineEdit_povna_nazva");

        horizontalLayout_3->addWidget(lineEdit_povna_nazva);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        comboBox_vid_aktiva = new QComboBox(layoutWidget);
        comboBox_vid_aktiva->setObjectName("comboBox_vid_aktiva");

        horizontalLayout_4->addWidget(comboBox_vid_aktiva);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        comboBox_rakhunok_obliku = new QComboBox(layoutWidget);
        comboBox_rakhunok_obliku->setObjectName("comboBox_rakhunok_obliku");

        horizontalLayout_5->addWidget(comboBox_rakhunok_obliku);


        horizontalLayout_12->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBox_pochatkova_vartist = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_pochatkova_vartist->setObjectName("doubleSpinBox_pochatkova_vartist");
        doubleSpinBox_pochatkova_vartist->setMaximum(99999999.989999994635582);

        horizontalLayout_6->addWidget(doubleSpinBox_pochatkova_vartist);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        lineEdit_inventarnyy_nomer = new QLineEdit(layoutWidget);
        lineEdit_inventarnyy_nomer->setObjectName("lineEdit_inventarnyy_nomer");

        horizontalLayout_7->addWidget(lineEdit_inventarnyy_nomer);


        horizontalLayout_13->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);

        lineEdit_shifr = new QLineEdit(layoutWidget);
        lineEdit_shifr->setObjectName("lineEdit_shifr");

        horizontalLayout_8->addWidget(lineEdit_shifr);


        horizontalLayout_13->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);

        horizontalSpacer_6 = new QSpacerItem(16, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);

        comboBox_odinitsya_vymiru = new QComboBox(layoutWidget);
        comboBox_odinitsya_vymiru->setObjectName("comboBox_odinitsya_vymiru");

        horizontalLayout_9->addWidget(comboBox_odinitsya_vymiru);


        horizontalLayout_14->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_10->addWidget(label_10);

        dateEdit_data_vvodu = new QDateEdit(layoutWidget);
        dateEdit_data_vvodu->setObjectName("dateEdit_data_vvodu");

        horizontalLayout_10->addWidget(dateEdit_data_vvodu);


        horizontalLayout_14->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_11->addWidget(label_11);

        comboBox_vid_diyalnosti = new QComboBox(layoutWidget);
        comboBox_vid_diyalnosti->setObjectName("comboBox_vid_diyalnosti");

        horizontalLayout_11->addWidget(comboBox_vid_diyalnosti);


        verticalLayout_3->addLayout(horizontalLayout_11);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 400, 211, 41));
        horizontalLayout_15 = new QHBoxLayout(widget);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout_6->addWidget(pushButton);


        horizontalLayout_15->addLayout(verticalLayout_6);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_15->addWidget(pushButton_2);


        retranslateUi(NoneMaterialActives);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NoneMaterialActives, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NoneMaterialActives, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NoneMaterialActives);
    } // setupUi

    void retranslateUi(QDialog *NoneMaterialActives)
    {
        NoneMaterialActives->setWindowTitle(QCoreApplication::translate("NoneMaterialActives", "\320\235\320\265\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\214\320\275\321\226 \320\260\320\272\321\202\320\270\320\262\320\270 \\ \320\276\321\201\320\275\320\276\320\262\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NoneMaterialActives", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217", nullptr));
        label->setText(QCoreApplication::translate("NoneMaterialActives", "\320\232\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("NoneMaterialActives", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("NoneMaterialActives", "\320\237\320\276\320\262\320\275\320\260 \320\275\320\260\320\267\320\262\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("NoneMaterialActives", "\320\222\320\270\320\264 \320\275\320\265\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\260\320\272\321\202\320\270\320\262\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("NoneMaterialActives", "\320\240\320\260\321\205\321\203\320\275\320\276\320\272 \320\276\320\261\320\273\321\226\320\272\321\203", nullptr));
        label_6->setText(QCoreApplication::translate("NoneMaterialActives", "\320\237\320\276\321\207\320\260\321\202\320\272\320\276\320\262\320\260 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("NoneMaterialActives", "\320\206\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\320\270\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        label_8->setText(QCoreApplication::translate("NoneMaterialActives", "\320\250\320\270\321\204\321\200", nullptr));
        label_9->setText(QCoreApplication::translate("NoneMaterialActives", "\320\236\320\264\320\270\320\275\320\270\321\206\321\217 \320\262\320\270\320\274\321\226\321\200\321\203", nullptr));
        label_10->setText(QCoreApplication::translate("NoneMaterialActives", "\320\224\320\260\321\202\320\260 \320\262\320\262\320\276\320\264\321\203 \320\262 \320\265\320\272\321\201\320\277\320\273\320\260\321\202\320\260\321\206\321\226\321\216", nullptr));
        label_11->setText(QCoreApplication::translate("NoneMaterialActives", "\320\222\320\270\320\264 \320\264\321\226\321\217\320\273\321\214\320\275\320\276\321\201\321\202\321\226", nullptr));
        pushButton->setText(QCoreApplication::translate("NoneMaterialActives", "\320\224\320\276\320\262\321\226\320\264\320\275\320\270\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NoneMaterialActives", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoneMaterialActives: public Ui_NoneMaterialActives {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NONEMATERIALACTIVES_H
