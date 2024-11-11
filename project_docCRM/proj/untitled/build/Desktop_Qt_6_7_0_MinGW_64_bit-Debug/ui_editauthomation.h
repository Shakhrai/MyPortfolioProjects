/********************************************************************************
** Form generated from reading UI file 'editauthomation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITAUTHOMATION_H
#define UI_EDITAUTHOMATION_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editAuthomation
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_assetId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_expenseType;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_depreciationMethod;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_salvageValue;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *dateEdit_depreciationTerm;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_delete;

    void setupUi(QDialog *editAuthomation)
    {
        if (editAuthomation->objectName().isEmpty())
            editAuthomation->setObjectName("editAuthomation");
        editAuthomation->resize(489, 351);
        groupBox = new QGroupBox(editAuthomation);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 461, 311));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox_assetId = new QComboBox(groupBox);
        comboBox_assetId->setObjectName("comboBox_assetId");

        horizontalLayout->addWidget(comboBox_assetId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        comboBox_expenseType = new QComboBox(groupBox);
        comboBox_expenseType->setObjectName("comboBox_expenseType");

        horizontalLayout_2->addWidget(comboBox_expenseType);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        comboBox_depreciationMethod = new QComboBox(groupBox);
        comboBox_depreciationMethod->setObjectName("comboBox_depreciationMethod");

        horizontalLayout_3->addWidget(comboBox_depreciationMethod);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        horizontalLayout_6->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        lineEdit_salvageValue = new QLineEdit(groupBox);
        lineEdit_salvageValue->setObjectName("lineEdit_salvageValue");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_salvageValue->sizePolicy().hasHeightForWidth());
        lineEdit_salvageValue->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_salvageValue);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        dateEdit_depreciationTerm = new QDateEdit(groupBox);
        dateEdit_depreciationTerm->setObjectName("dateEdit_depreciationTerm");

        horizontalLayout_5->addWidget(dateEdit_depreciationTerm);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        pushButton_delete = new QPushButton(editAuthomation);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(10, 320, 171, 24));

        retranslateUi(editAuthomation);

        QMetaObject::connectSlotsByName(editAuthomation);
    } // setupUi

    void retranslateUi(QDialog *editAuthomation)
    {
        editAuthomation->setWindowTitle(QCoreApplication::translate("editAuthomation", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("editAuthomation", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 - \320\261\321\203\321\205.\320\276\320\261\320\273\321\226\320\272 \\ \320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        label->setText(QCoreApplication::translate("editAuthomation", "\320\240\320\260\321\205\321\203\320\275\320\276\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("editAuthomation", "\320\222\320\270\320\264 \320\262\320\270\321\202\321\200\320\260\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("editAuthomation", "\320\234\320\265\321\202\320\276\320\264 \321\200\320\276\320\267\321\200\320\260\321\205\321\203\320\275\320\272\321\203 \320\267\320\275\320\276\321\201\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("editAuthomation", "\320\233\321\226\320\272\320\262\321\226\320\264\320\260\321\206\321\226\320\271\320\275\320\260 \320\262\320\260\321\200\321\202\321\226\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("editAuthomation", "\320\242\320\265\321\200\320\274\321\226\320\275 \320\272\320\276\321\200\320\270\321\201\320\275\320\276\320\263\320\276 \320\262\320\270\320\272\320\276\321\200\320\270\321\201\321\202\320\260\320\275\320\275\321\217", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("editAuthomation", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\320\267\320\260\321\206\321\226\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editAuthomation: public Ui_editAuthomation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAUTHOMATION_H
