/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_new;
    QAction *action_open;
    QAction *action_print;
    QAction *action_quit;
    QAction *action_nmActives;
    QAction *action_amActive;
    QAction *action_fixedAss;
    QAction *action_amFixedAss;
    QAction *action_generalView;
    QAction *action_Wiki;
    QAction *action_aboutQt;
    QAction *action_aboutAuth;
    QAction *action_copy;
    QAction *action_cut;
    QAction *action_undo;
    QAction *action_redo;
    QAction *action_paste;
    QAction *action_saveAs;
    QAction *action_generateAssetsReport;
    QAction *action_generateDepreciationReport;
    QAction *action_generateMoveReport;
    QAction *action_generateInventoryReport;
    QAction *action_generateCategoryReport;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_createNewDb;
    QPushButton *pushButton_generalView;
    QGroupBox *groupBox_2;
    QTextEdit *commentSpace;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(783, 597);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action_new = new QAction(MainWindow);
        action_new->setObjectName("action_new");
        action_open = new QAction(MainWindow);
        action_open->setObjectName("action_open");
        action_print = new QAction(MainWindow);
        action_print->setObjectName("action_print");
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName("action_quit");
        action_nmActives = new QAction(MainWindow);
        action_nmActives->setObjectName("action_nmActives");
        action_amActive = new QAction(MainWindow);
        action_amActive->setObjectName("action_amActive");
        action_fixedAss = new QAction(MainWindow);
        action_fixedAss->setObjectName("action_fixedAss");
        action_amFixedAss = new QAction(MainWindow);
        action_amFixedAss->setObjectName("action_amFixedAss");
        action_generalView = new QAction(MainWindow);
        action_generalView->setObjectName("action_generalView");
        action_Wiki = new QAction(MainWindow);
        action_Wiki->setObjectName("action_Wiki");
        action_aboutQt = new QAction(MainWindow);
        action_aboutQt->setObjectName("action_aboutQt");
        action_aboutAuth = new QAction(MainWindow);
        action_aboutAuth->setObjectName("action_aboutAuth");
        action_copy = new QAction(MainWindow);
        action_copy->setObjectName("action_copy");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/copy_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_copy->setIcon(icon);
        action_cut = new QAction(MainWindow);
        action_cut->setObjectName("action_cut");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/cut_img.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action_cut->setIcon(icon1);
        action_undo = new QAction(MainWindow);
        action_undo->setObjectName("action_undo");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/undo_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_undo->setIcon(icon2);
        action_redo = new QAction(MainWindow);
        action_redo->setObjectName("action_redo");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/redo_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_redo->setIcon(icon3);
        action_paste = new QAction(MainWindow);
        action_paste->setObjectName("action_paste");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/paste_img.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_paste->setIcon(icon4);
        action_saveAs = new QAction(MainWindow);
        action_saveAs->setObjectName("action_saveAs");
        action_generateAssetsReport = new QAction(MainWindow);
        action_generateAssetsReport->setObjectName("action_generateAssetsReport");
        action_generateDepreciationReport = new QAction(MainWindow);
        action_generateDepreciationReport->setObjectName("action_generateDepreciationReport");
        action_generateMoveReport = new QAction(MainWindow);
        action_generateMoveReport->setObjectName("action_generateMoveReport");
        action_generateInventoryReport = new QAction(MainWindow);
        action_generateInventoryReport->setObjectName("action_generateInventoryReport");
        action_generateCategoryReport = new QAction(MainWindow);
        action_generateCategoryReport->setObjectName("action_generateCategoryReport");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 771, 501));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 351, 201));
        label->setMaximumSize(QSize(351, 201));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(450, 40, 258, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_createNewDb = new QPushButton(layoutWidget1);
        pushButton_createNewDb->setObjectName("pushButton_createNewDb");
        pushButton_createNewDb->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pushButton_createNewDb);

        pushButton_generalView = new QPushButton(layoutWidget1);
        pushButton_generalView->setObjectName("pushButton_generalView");

        verticalLayout_2->addWidget(pushButton_generalView);


        verticalLayout_3->addLayout(verticalLayout_2);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 400, 731, 91));
        groupBox_2->setMaximumSize(QSize(731, 16777215));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        commentSpace = new QTextEdit(groupBox_2);
        commentSpace->setObjectName("commentSpace");
        commentSpace->setGeometry(QRect(10, 30, 711, 61));
        commentSpace->setMaximumSize(QSize(731, 61));

        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 783, 21));
        menubar->setStyleSheet(QString::fromUtf8(""));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_2->menuAction());
        menuFile->addAction(action_new);
        menuFile->addAction(action_open);
        menuFile->addSeparator();
        menuFile->addAction(action_saveAs);
        menuFile->addAction(action_print);
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(action_quit);
        menu->addAction(action_nmActives);
        menu->addAction(action_amActive);
        menu->addSeparator();
        menu->addAction(action_fixedAss);
        menu->addAction(action_amFixedAss);
        menu->addSeparator();
        menu->addAction(action_generalView);
        menu->addSeparator();
        menu->addAction(action_Wiki);
        menu_2->addAction(action_aboutQt);
        menu_2->addSeparator();
        menu_2->addAction(action_aboutAuth);
        menu_3->addAction(action_copy);
        menu_3->addAction(action_cut);
        menu_3->addAction(action_paste);
        menu_3->addAction(action_undo);
        menu_3->addAction(action_redo);
        menu_3->addSeparator();
        menu_4->addAction(action_generateAssetsReport);
        menu_4->addAction(action_generateDepreciationReport);
        menu_4->addAction(action_generateMoveReport);
        menu_4->addAction(action_generateInventoryReport);
        menu_4->addAction(action_generateCategoryReport);
        toolBar->addAction(action_copy);
        toolBar->addSeparator();
        toolBar->addAction(action_paste);
        toolBar->addSeparator();
        toolBar->addAction(action_cut);
        toolBar->addSeparator();
        toolBar->addAction(action_undo);
        toolBar->addSeparator();
        toolBar->addAction(action_redo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\273\320\276\320\262\320\275\320\260 \321\201\321\202\320\276\321\200\321\226\320\275\320\272\320\260", nullptr));
        action_new->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270", nullptr));
        action_print->setText(QCoreApplication::translate("MainWindow", "\320\224\321\200\321\203\320\272", nullptr));
        action_quit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", nullptr));
        action_nmActives->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\320\274\320\260\321\202.\320\260\320\272\321\202\320\270\320\262\320\270", nullptr));
        action_amActive->setText(QCoreApplication::translate("MainWindow", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 \320\275\320\265\320\274\320\260\321\202. \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        action_fixedAss->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\321\226 \320\267\320\260\321\201\320\276\320\261\320\270", nullptr));
        action_amFixedAss->setText(QCoreApplication::translate("MainWindow", "\320\220\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\217 \320\276\321\201\320\275\320\276\320\262\320\275\320\270\321\205 \320\267\320\260\321\201\320\276\320\261\321\226\320\262", nullptr));
        action_generalView->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\260\320\273\321\214\320\275\320\270\320\271 \320\262\320\270\320\263\320\273\321\217\320\264 \320\276\320\261\320\273\321\226\320\272\321\203", nullptr));
        action_Wiki->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\275\320\270\320\272", nullptr));
        action_aboutQt->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276 Qt", nullptr));
        action_aboutAuth->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        action_copy->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\321\226\321\216\320\262\320\260\321\202\320\270", nullptr));
        action_cut->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\200\321\226\320\267\320\260\321\202\320\270", nullptr));
        action_undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        action_redo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        action_paste->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\320\270", nullptr));
        action_saveAs->setText(QCoreApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\217\320\272", nullptr));
        action_generateAssetsReport->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202 \320\277\321\200\320\276 \320\260\320\272\321\202\320\270\320\262\320\270", nullptr));
        action_generateDepreciationReport->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202 \320\277\321\200\320\276 \320\260\320\274\320\276\321\200\321\202\320\270\320\267\320\260\321\206\321\226\321\216", nullptr));
        action_generateMoveReport->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202 \320\277\321\200\320\276 \321\200\321\203\321\205 \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        action_generateInventoryReport->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202 \320\277\320\276 \321\226\320\275\320\262\320\265\320\275\321\202\320\260\320\275\320\276\320\274\321\203 \320\275\320\276\320\274\320\265\321\200\321\203", nullptr));
        action_generateCategoryReport->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202 \320\277\320\276 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\321\226\321\217\320\274 \320\260\320\272\321\202\320\270\320\262\321\226\320\262", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\207\320\260\321\202\320\270 \321\200\320\276\320\261\320\276\321\202\321\203", nullptr));
        label->setText(QString());
        pushButton_createNewDb->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\275\320\276\320\262\320\265 \320\277\321\226\320\264\320\277\321\200\320\270\321\224\320\274\321\201\321\202\320\262\320\276", nullptr));
        pushButton_generalView->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\260\320\273\321\214\320\275\320\270\320\271 \320\262\320\270\320\263\320\273\321\217\320\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\265 \320\264\320\273\321\217 \320\275\320\276\321\202\320\260\321\202\320\276\320\272", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\265\320\274\320\260\321\202.\320\260\320\272\321\202\320\270\320\262\320\270\\\320\276\321\201\320\275\320\276\320\262\320\275\321\226 \320\267\320\260\321\201.", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\275\320\260\321\201", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\321\217", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202\320\270", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
