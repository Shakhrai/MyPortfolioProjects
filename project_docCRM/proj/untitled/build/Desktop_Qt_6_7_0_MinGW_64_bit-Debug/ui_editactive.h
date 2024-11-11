/********************************************************************************
** Form generated from reading UI file 'editactive.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITACTIVE_H
#define UI_EDITACTIVE_H

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

class Ui_editActive
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton_delete;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_code;
    QLineEdit *lineEdit_nazva_2;
    QLineEdit *lineEdit_povna_nazva_2;
    QComboBox *comboBox_vid_aktiva_2;
    QComboBox *comboBox_rakhunok_obliku_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *doubleSpinBox_pochatkova_vartist_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_18;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_inventarnyy_nomer_2;
    QComboBox *comboBox_odinitsya_vymiru_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_19;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_shifr_2;
    QDateEdit *dateEdit_data_vvodu_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_22;
    QComboBox *comboBox_vid_diyalnosti_2;

    void setupUi(QDialog *editActive)
    {
        if (editActive->objectName().isEmpty())
            editActive->setObjectName("editActive");
        editActive->resize(613, 522);
        groupBox = new QGroupBox(editActive);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 591, 501));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        pushButton_delete = new QPushButton(groupBox);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(0, 470, 151, 24));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(420, 470, 166, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 50, 571, 331));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_12 = new QLabel(widget);
        label_12->setObjectName("label_12");

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(widget);
        label_13->setObjectName("label_13");

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(widget);
        label_14->setObjectName("label_14");

        verticalLayout_2->addWidget(label_14);

        label_15 = new QLabel(widget);
        label_15->setObjectName("label_15");

        verticalLayout_2->addWidget(label_15);

        label_16 = new QLabel(widget);
        label_16->setObjectName("label_16");

        verticalLayout_2->addWidget(label_16);

        label_17 = new QLabel(widget);
        label_17->setObjectName("label_17");

        verticalLayout_2->addWidget(label_17);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(118, 18, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox_code = new QComboBox(widget);
        comboBox_code->setObjectName("comboBox_code");

        horizontalLayout->addWidget(comboBox_code);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_nazva_2 = new QLineEdit(widget);
        lineEdit_nazva_2->setObjectName("lineEdit_nazva_2");

        verticalLayout->addWidget(lineEdit_nazva_2);

        lineEdit_povna_nazva_2 = new QLineEdit(widget);
        lineEdit_povna_nazva_2->setObjectName("lineEdit_povna_nazva_2");

        verticalLayout->addWidget(lineEdit_povna_nazva_2);

        comboBox_vid_aktiva_2 = new QComboBox(widget);
        comboBox_vid_aktiva_2->setObjectName("comboBox_vid_aktiva_2");

        verticalLayout->addWidget(comboBox_vid_aktiva_2);

        comboBox_rakhunok_obliku_2 = new QComboBox(widget);
        comboBox_rakhunok_obliku_2->setObjectName("comboBox_rakhunok_obliku_2");

        verticalLayout->addWidget(comboBox_rakhunok_obliku_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(118, 17, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        doubleSpinBox_pochatkova_vartist_2 = new QDoubleSpinBox(widget);
        doubleSpinBox_pochatkova_vartist_2->setObjectName("doubleSpinBox_pochatkova_vartist_2");
        doubleSpinBox_pochatkova_vartist_2->setMaximum(99999999.989999994635582);

        horizontalLayout_2->addWidget(doubleSpinBox_pochatkova_vartist_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_8->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_18 = new QLabel(widget);
        label_18->setObjectName("label_18");

        verticalLayout_6->addWidget(label_18);

        label_20 = new QLabel(widget);
        label_20->setObjectName("label_20");

        verticalLayout_6->addWidget(label_20);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEdit_inventarnyy_nomer_2 = new QLineEdit(widget);
        lineEdit_inventarnyy_nomer_2->setObjectName("lineEdit_inventarnyy_nomer_2");

        verticalLayout_3->addWidget(lineEdit_inventarnyy_nomer_2);

        comboBox_odinitsya_vymiru_2 = new QComboBox(widget);
        comboBox_odinitsya_vymiru_2->setObjectName("comboBox_odinitsya_vymiru_2");

        verticalLayout_3->addWidget(comboBox_odinitsya_vymiru_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_19 = new QLabel(widget);
        label_19->setObjectName("label_19");

        verticalLayout_5->addWidget(label_19);

        label_21 = new QLabel(widget);
        label_21->setObjectName("label_21");

        verticalLayout_5->addWidget(label_21);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lineEdit_shifr_2 = new QLineEdit(widget);
        lineEdit_shifr_2->setObjectName("lineEdit_shifr_2");

        verticalLayout_4->addWidget(lineEdit_shifr_2);

        dateEdit_data_vvodu_2 = new QDateEdit(widget);
        dateEdit_data_vvodu_2->setObjectName("dateEdit_data_vvodu_2");

        verticalLayout_4->addWidget(dateEdit_data_vvodu_2);


        horizontalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_22 = new QLabel(widget);
        label_22->setObjectName("label_22");

        horizontalLayout_3->addWidget(label_22);

        comboBox_vid_diyalnosti_2 = new QComboBox(widget);
        comboBox_vid_diyalnosti_2->setObjectName("comboBox_vid_diyalnosti_2");

        horizontalLayout_3->addWidget(comboBox_vid_diyalnosti_2);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(editActive);

        QMetaObject::connectSlotsByName(editActive);
    } // setupUi

    void retranslateUi(QDialog *editActive)
    {
        editActive->setWindowTitle(QCoreApplication::translate("editActive", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("editActive", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217 \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("editActive", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\260\320\272\321\202\320\270\320\262", nullptr));
        label_12->setText(QCoreApplication::translate("editActive", "\320\232\320\276\320\264", nullptr));
        label_13->setText(QCoreApplication::translate("editActive", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        label_14->setText(QCoreApplication::translate("editActive", "\320\237\320\276\320\262\320\275\320\260 \320\275\320\260\320\267\320\262\320\260", nullptr));
        label_15->setText(QCoreApplication::translate("editActive", "\320\222\320\270\320\264 \320\275\320\265\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\260\320\272\321\202\320\270\320\262\320\260", nullptr));
        label_16->setText(QCoreApplication::translate("editActive", "\320\240\320\260\321\205\321\203\320\275\320\276\320\272 \320\276\320\261\320\273\321\226\320\272\321\203", nullptr));
        label_17->setText(QCoreApplication::translate("editActive", "\320\237\320\276\321\207\320\260\321\202\320\272\320\276\320\262\320\260 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214", nullptr));
        label_18->setText(QCoreApplication::translate("editActive", "\320\206\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\320\270\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        label_20->setText(QCoreApplication::translate("editActive", "\320\236\320\264\320\270\320\275\320\270\321\206\321\217 \320\262\320\270\320\274\321\226\321\200\321\203", nullptr));
        label_19->setText(QCoreApplication::translate("editActive", "\320\250\320\270\321\204\321\200", nullptr));
        label_21->setText(QCoreApplication::translate("editActive", "\320\224\320\260\321\202\320\260 \320\262\320\262\320\276\320\264\321\203 \320\262 \320\265\320\272\321\201\320\277\320\273\320\260\321\202\320\260\321\206\321\226\321\216", nullptr));
        label_22->setText(QCoreApplication::translate("editActive", "\320\222\320\270\320\264 \320\264\321\226\321\217\320\273\321\214\320\275\320\276\321\201\321\202\321\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editActive: public Ui_editActive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITACTIVE_H
