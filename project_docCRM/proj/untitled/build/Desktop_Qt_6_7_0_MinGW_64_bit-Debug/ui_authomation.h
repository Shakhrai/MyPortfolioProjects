/********************************************************************************
** Form generated from reading UI file 'authomation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHOMATION_H
#define UI_AUTHOMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Authomation
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_assetId;
    QComboBox *comboBox_expenseType;
    QComboBox *comboBox_depreciationMethod;
    QLineEdit *lineEdit_salvageValue;
    QDateEdit *dateEdit_depreciationTerm;

    void setupUi(QDialog *Authomation)
    {
        if (Authomation->objectName().isEmpty())
            Authomation->setObjectName("Authomation");
        Authomation->resize(497, 337);
        groupBox = new QGroupBox(Authomation);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 461, 311));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(240, 273, 211, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 441, 231));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        comboBox_assetId = new QComboBox(widget);
        comboBox_assetId->setObjectName("comboBox_assetId");

        verticalLayout->addWidget(comboBox_assetId);

        comboBox_expenseType = new QComboBox(widget);
        comboBox_expenseType->setObjectName("comboBox_expenseType");

        verticalLayout->addWidget(comboBox_expenseType);

        comboBox_depreciationMethod = new QComboBox(widget);
        comboBox_depreciationMethod->setObjectName("comboBox_depreciationMethod");

        verticalLayout->addWidget(comboBox_depreciationMethod);

        lineEdit_salvageValue = new QLineEdit(widget);
        lineEdit_salvageValue->setObjectName("lineEdit_salvageValue");

        verticalLayout->addWidget(lineEdit_salvageValue);

        dateEdit_depreciationTerm = new QDateEdit(widget);
        dateEdit_depreciationTerm->setObjectName("dateEdit_depreciationTerm");

        verticalLayout->addWidget(dateEdit_depreciationTerm);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Authomation);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Authomation, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Authomation, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Authomation);
    } // setupUi

    void retranslateUi(QDialog *Authomation)
    {
        Authomation->setWindowTitle(QCoreApplication::translate("Authomation", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217 \320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\227", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Authomation", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 - \320\261\321\203\321\205.\320\276\320\261\320\273\321\226\320\272", nullptr));
        label->setText(QCoreApplication::translate("Authomation", "\320\240\320\260\321\205\321\203\320\275\320\276\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("Authomation", "\320\222\320\270\320\264 \320\262\320\270\321\202\321\200\320\260\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("Authomation", "\320\234\320\265\321\202\320\276\320\264 \321\200\320\276\320\267\321\200\320\260\321\205\321\203\320\275\320\272\321\203 \320\267\320\275\320\276\321\201\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("Authomation", "\320\233\321\226\320\272\320\262\321\226\320\264\320\260\321\206\321\226\320\271\320\275\320\260 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("Authomation", "\320\242\320\265\321\200\320\274\321\226\320\275 \320\272\320\276\321\200\320\270\321\201\320\275\320\276\320\263\320\276 \320\262\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\260\320\275\320\275\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authomation: public Ui_Authomation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHOMATION_H
