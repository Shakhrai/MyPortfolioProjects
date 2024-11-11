#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <nonematerialactives.h>
#include <authomation.h>
#include <dbcreate.h>
#include <tablepage.h>
#include <generatereport.h>
#include <QMainWindow>
#include <QTabWidget>
#include <QSqlDatabase>
#include <QPrinter>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_action_cut_triggered();

    void on_action_copy_triggered();

    void on_action_paste_triggered();

    void on_action_redo_triggered();

    void on_action_undo_triggered();

    void on_pushButton_createNewDb_clicked();

    void on_action_new_triggered();

    void on_pushButton_generalView_clicked();

    void on_action_quit_triggered();

    void on_action_open_triggered();

    void on_action_nmActives_triggered();

    void on_action_saveAs_triggered();

    void on_action_fixedAss_triggered();

    void on_action_amActive_triggered();

    void on_action_amFixedAss_triggered();



    void on_action_generalView_triggered();

    void on_action_generateAssetsReport_triggered();

    void on_action_generateDepreciationReport_triggered();

    void on_action_generateMoveReport_triggered();

    void on_action_generateInventoryReport_triggered();

    void on_action_generateCategoryReport_triggered();

    void on_action_aboutQt_triggered();

   void on_action_aboutAuth_triggered();

    void on_action_print_triggered();

   void on_action_Wiki_triggered();




   private:
    Ui::MainWindow *ui;

    NoneMaterialActives *nmActives;
    dbcreate *dbCWindow;
    tablepage *tbl_p;

    QSqlDatabase db;
    QString dbName;
    void createTables();

};
#endif // MAINWINDOW_H
