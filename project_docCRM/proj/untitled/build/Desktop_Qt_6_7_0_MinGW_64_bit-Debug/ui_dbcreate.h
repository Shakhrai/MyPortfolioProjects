/********************************************************************************
** Form generated from reading UI file 'dbcreate.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBCREATE_H
#define UI_DBCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dbcreate
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dbcreate)
    {
        if (dbcreate->objectName().isEmpty())
            dbcreate->setObjectName("dbcreate");
        dbcreate->resize(351, 279);
        groupBox = new QGroupBox(dbcreate);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 341, 261));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 100, 291, 67));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(250, 190, 80, 65));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(dbcreate);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, dbcreate, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, dbcreate, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(dbcreate);
    } // setupUi

    void retranslateUi(QDialog *dbcreate)
    {
        dbcreate->setWindowTitle(QCoreApplication::translate("dbcreate", "\320\235\320\276\320\262\320\265 \320\277\321\226\320\264\320\277\321\200\320\270\321\224\320\274\321\201\321\202\320\262\320\276", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dbcreate", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217 \320\275\320\276\320\262\320\276\321\227 \320\261\320\260\320\267\320\270", nullptr));
        label->setText(QCoreApplication::translate("dbcreate", "\320\235\320\260\320\267\320\262\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbcreate: public Ui_dbcreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBCREATE_H
