/********************************************************************************
** Form generated from reading UI file 'tablepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEPAGE_H
#define UI_TABLEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tablepage
{
public:
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab_nmActives;
    QTableView *tableView;
    QWidget *tab_tangibleAsset;
    QTableView *tableView_2;
    QWidget *tab_nmActives_amorth;
    QTableView *tableView_3;
    QWidget *tab4_tangible_assets_amorth;
    QTableView *tableView_4;

    void setupUi(QDialog *tablepage)
    {
        if (tablepage->objectName().isEmpty())
            tablepage->setObjectName("tablepage");
        tablepage->resize(915, 627);
        groupBox = new QGroupBox(tablepage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 891, 611));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 30, 841, 561));
        tab_nmActives = new QWidget();
        tab_nmActives->setObjectName("tab_nmActives");
        tableView = new QTableView(tab_nmActives);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 841, 561));
        tabWidget->addTab(tab_nmActives, QString());
        tab_tangibleAsset = new QWidget();
        tab_tangibleAsset->setObjectName("tab_tangibleAsset");
        tableView_2 = new QTableView(tab_tangibleAsset);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(0, 0, 841, 561));
        tabWidget->addTab(tab_tangibleAsset, QString());
        tab_nmActives_amorth = new QWidget();
        tab_nmActives_amorth->setObjectName("tab_nmActives_amorth");
        tableView_3 = new QTableView(tab_nmActives_amorth);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(0, 0, 841, 561));
        tabWidget->addTab(tab_nmActives_amorth, QString());
        tab4_tangible_assets_amorth = new QWidget();
        tab4_tangible_assets_amorth->setObjectName("tab4_tangible_assets_amorth");
        tableView_4 = new QTableView(tab4_tangible_assets_amorth);
        tableView_4->setObjectName("tableView_4");
        tableView_4->setGeometry(QRect(0, 0, 841, 561));
        tabWidget->addTab(tab4_tangible_assets_amorth, QString());

        retranslateUi(tablepage);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(tablepage);
    } // setupUi

    void retranslateUi(QDialog *tablepage)
    {
        tablepage->setWindowTitle(QCoreApplication::translate("tablepage", "\320\236\320\261\320\273\321\226\320\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("tablepage", "\320\227\320\260\320\263\320\260\320\273\321\214\320\275\320\270\320\271 \320\262\320\270\320\263\320\273\321\217\320\264 \320\276\320\261\320\273\321\226\320\272\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_nmActives), QCoreApplication::translate("tablepage", "\320\235\320\265\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\214\320\275\321\226 \320\260\320\272\321\202\320\270\320\262\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_tangibleAsset), QCoreApplication::translate("tablepage", "\320\236\321\201\320\275\320\276\320\262\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_nmActives_amorth), QCoreApplication::translate("tablepage", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 \320\275\320\265\320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\321\214\320\275\320\270\321\205 \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4_tangible_assets_amorth), QCoreApplication::translate("tablepage", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 \320\276\321\201\320\275\320\276\320\262\320\275\320\270\321\205 \320\267\320\260\321\201\320\276\320\261\321\226\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tablepage: public Ui_tablepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEPAGE_H
