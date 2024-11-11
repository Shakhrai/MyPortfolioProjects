#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include <QDialog>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
namespace Ui {
class tablepage;
}

class tablepage : public QDialog
{
    Q_OBJECT

public:
    explicit tablepage(const QString &dbName, QWidget *parent = nullptr);
    ~tablepage();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_tableView_3_doubleClicked(const QModelIndex &index);

    void on_tableView_4_doubleClicked(const QModelIndex &index);

private:
    Ui::tablepage *ui;
    QSqlDatabase db;
    QSqlTableModel *intangibleModel;
    QSqlTableModel *tangibleModel;
    QSqlTableModel *intangible_assets_depreciation;
    QSqlTableModel *tangible_assets_depreciation;
    void setupModels();
    void openDatabase(const QString &dbName);
    void loadAssets();
};

#endif // TABLEPAGE_H
