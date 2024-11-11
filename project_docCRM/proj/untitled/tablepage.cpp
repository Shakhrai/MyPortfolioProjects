
#include "tablepage.h"
#include "ui_tablepage.h"
#include "editactive.h"
#include "editauthomation.h"
#include "dbcreate.cpp"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlError>
tablepage::tablepage(const QString &dbName,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tablepage)

{
    ui->setupUi(this);
    openDatabase(dbName);
    setupModels();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }
}

tablepage::~tablepage()
{
    delete ui;
}
void tablepage::openDatabase(const QString &dbName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database.");
    }
}

void tablepage::setupModels()
{



    intangibleModel = new QSqlTableModel(this, db);
    intangibleModel->setTable("intangible_assets");
    intangibleModel->select();
    ui->tableView->setModel(intangibleModel);

    tangibleModel = new QSqlTableModel(this, db);
    tangibleModel->setTable("tangible_assets");
    tangibleModel->select();
    ui->tableView_2->setModel(tangibleModel);

    // Исправляем ошибку здесь
    intangible_assets_depreciation = new QSqlTableModel(this, db);
    intangible_assets_depreciation->setTable("intangible_assets_depreciation");
    intangible_assets_depreciation->select();
    ui->tableView_3->setModel(intangible_assets_depreciation);

    tangible_assets_depreciation = new QSqlTableModel(this, db);
    tangible_assets_depreciation->setTable("tangible_assets_depreciation");
    tangible_assets_depreciation->select();
    ui->tableView_4->setModel(tangible_assets_depreciation);

}

void tablepage::on_tableView_doubleClicked(const QModelIndex &index)
{

    if (!index.isValid()) {
        return;
    }

    int assetId = intangibleModel->data(intangibleModel->index(index.row(), 0)).toInt(); // Получаем id актива из модели
    if (assetId != -1) {
        QSqlDatabase db = QSqlDatabase::database(); // Получаем подключение к БД

        editActive editDialog(db, assetId,false, this);
        if (editDialog.exec() == QDialog::Accepted) {
            // Обновить таблицу после успешного редактирования
            intangibleModel->select();
        }
    }
}


void tablepage::on_tableView_2_doubleClicked(const QModelIndex &index)
{

    if (!index.isValid()) {
        return;
    }

    int assetId = tangibleModel->data(tangibleModel->index(index.row(), 0)).toInt(); // Получаем id актива из модели
    if (assetId != -1) {
        QSqlDatabase db = QSqlDatabase::database(); // Получаем подключение к БД

        editActive editDialog(db, assetId,true, this);
        if (editDialog.exec() == QDialog::Accepted) {
            // Обновить таблицу после успешного редактирования
            tangibleModel->select();
        }
    }
}


void tablepage::on_tableView_3_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }

    int assetId = intangible_assets_depreciation->data(intangible_assets_depreciation->index(index.row(), 1)).toInt(); // Получаем id актива из модели
    if (assetId != -1) {
        QSqlDatabase db = QSqlDatabase::database(); // Получаем подключение к БД

        editAuthomation editDialogAuth(db, assetId,false, this);
        if (editDialogAuth.exec() == QDialog::Accepted) {
            // Обновить таблицу после успешного редактирования
            intangible_assets_depreciation->select();
        }
    }
}


void tablepage::on_tableView_4_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }

    int assetId = tangible_assets_depreciation->data(tangible_assets_depreciation->index(index.row(), 1)).toInt(); // Получаем id актива из модели
    if (assetId != -1) {
        QSqlDatabase db = QSqlDatabase::database(); // Получаем подключение к БД

        editAuthomation editDialogAuth(db, assetId,true, this);
        if (editDialogAuth.exec() == QDialog::Accepted) {
            // Обновить таблицу после успешного редактирования
            tangible_assets_depreciation->select();
        }
    }
}

/*
void tablepage::loadAssets()
{
    // Реализация загрузки активов в QTableView
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, code, name, full_name, asset_type, account, initial_cost, inventory_number, cipher, unit, entry_date, activity_type FROM intangible_assets", QSqlDatabase::database());

    ui->tableView->setModel(model);

    // Настройка представления для отображения id актива в роли Qt::UserRole
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0); // 0 - колонка id
        int assetId = model->data(index).toInt();
        model->setData(index, assetId, Qt::UserRole);
    }
}*/
