/********************************************************************************
** Form generated from reading UI file 'generatereport.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEREPORT_H
#define UI_GENERATEREPORT_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generateReport
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_chosed_report;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QComboBox *comboBox_active_type;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QComboBox *comboBox_active_code;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QComboBox *comboBox_active_category;
    QLabel *label_8;
    QComboBox *comboBox_operation_type;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QDateEdit *dateEdit_from;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateEdit *dateEdit_to;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QComboBox *comboBox_depreciation_method;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *generateReport)
    {
        if (generateReport->objectName().isEmpty())
            generateReport->setObjectName("generateReport");
        generateReport->resize(525, 378);
        groupBox = new QGroupBox(generateReport);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 511, 361));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 341, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_chosed_report = new QLineEdit(layoutWidget);
        lineEdit_chosed_report->setObjectName("lineEdit_chosed_report");
        lineEdit_chosed_report->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_chosed_report);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 80, 341, 196));
        verticalLayout_7 = new QVBoxLayout(layoutWidget1);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        comboBox_active_type = new QComboBox(layoutWidget1);
        comboBox_active_type->setObjectName("comboBox_active_type");

        verticalLayout_2->addWidget(comboBox_active_type);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        verticalLayout_3->addWidget(label_6);

        comboBox_active_code = new QComboBox(layoutWidget1);
        comboBox_active_code->setObjectName("comboBox_active_code");

        verticalLayout_3->addWidget(comboBox_active_code);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");

        verticalLayout_4->addWidget(label_7);

        comboBox_active_category = new QComboBox(layoutWidget1);
        comboBox_active_category->setObjectName("comboBox_active_category");

        verticalLayout_4->addWidget(comboBox_active_category);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");

        verticalLayout_5->addWidget(label_8);

        comboBox_operation_type = new QComboBox(layoutWidget1);
        comboBox_operation_type->setObjectName("comboBox_operation_type");

        verticalLayout_5->addWidget(comboBox_operation_type);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        dateEdit_from = new QDateEdit(layoutWidget1);
        dateEdit_from->setObjectName("dateEdit_from");

        horizontalLayout_2->addWidget(dateEdit_from);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        dateEdit_to = new QDateEdit(layoutWidget1);
        dateEdit_to->setObjectName("dateEdit_to");

        horizontalLayout_3->addWidget(dateEdit_to);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 280, 481, 61));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        verticalLayout_8->addWidget(label_9);

        comboBox_depreciation_method = new QComboBox(widget);
        comboBox_depreciation_method->setObjectName("comboBox_depreciation_method");

        verticalLayout_8->addWidget(comboBox_depreciation_method);


        horizontalLayout_6->addLayout(verticalLayout_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_6->addWidget(buttonBox);


        retranslateUi(generateReport);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, generateReport, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, generateReport, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(generateReport);
    } // setupUi

    void retranslateUi(QDialog *generateReport)
    {
        generateReport->setWindowTitle(QCoreApplication::translate("generateReport", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\321\226\321\217 \320\267\320\262\321\226\321\202\321\226\320\262", nullptr));
        groupBox->setTitle(QCoreApplication::translate("generateReport", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\321\226\321\217 \320\267\320\262\321\226\321\202\321\226\320\262", nullptr));
        label->setText(QCoreApplication::translate("generateReport", "\320\236\320\261\321\200\320\260\320\275\320\275\320\270\320\271 \320\267\320\262\321\226\321\202", nullptr));
        label_5->setText(QCoreApplication::translate("generateReport", "\320\242\320\270\320\277 \320\260\320\272\321\202\320\270\320\262\321\203", nullptr));
        label_6->setText(QCoreApplication::translate("generateReport", "\320\232\320\276\320\264 \320\260\320\272\321\202\320\270\320\262\321\203", nullptr));
        label_7->setText(QCoreApplication::translate("generateReport", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\321\226\321\227 \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        label_8->setText(QCoreApplication::translate("generateReport", " \320\242\320\270\320\277 \320\276\320\277\320\265\321\200\320\260\321\206\321\226\321\227", nullptr));
        label_2->setText(QCoreApplication::translate("generateReport", "\320\237\320\265\321\200\321\226\320\276\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("generateReport", "\320\222\321\226\320\264", nullptr));
        label_4->setText(QCoreApplication::translate("generateReport", "\320\224\320\276", nullptr));
        label_9->setText(QCoreApplication::translate("generateReport", "\320\234\320\265\321\202\320\276\320\264 \321\200\320\276\320\267\321\200\320\260\321\205\321\203\320\275\320\272\321\203 \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generateReport: public Ui_generateReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEREPORT_H
