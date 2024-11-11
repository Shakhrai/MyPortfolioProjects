#include "authomation.h"
#include "ui_authomation.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug> // для отладки

Authomation::Authomation(bool isIntangible, QSqlDatabase database, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Authomation)
    , db(database)
{
    ui->setupUi(this);
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Databaspe Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (isIntangible) {
        query.exec("SELECT code, name FROM intangible_assets");
        while (query.next()) {
            QString code = query.value(0).toString();
            QString name = query.value(1).toString();
            qDebug() << "Intangible Asset - Code:" << code << ", Name:" << name; // отладочное сообщение
            ui->comboBox_assetId->addItem(code, code);
        }
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Authomation::addIntangibleAssetDepreciation);
    } else {
        query.exec("SELECT code, name FROM tangible_assets");
        while (query.next()) {
            QString code = query.value(0).toString();
            QString name = query.value(1).toString();
            qDebug() << "Tangible Asset - Code:" << code << ", Name:" << name; // отладочное сообщение
            ui->comboBox_assetId->addItem(code, code);
        }
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Authomation::addTangibleAssetDepreciation);
    }


    ui->comboBox_expenseType->addItems({"Основні засоби", "Інші необоротні активи", "Нематеріальні активи", "Гудвіл", "Інші нематеріальні активи"});
    ui->comboBox_depreciationMethod->addItems({"Прямолінійний метод", "Зменшений залишок", "Виробничий метод"});
}

Authomation::~Authomation()
{
    delete ui;
}

void Authomation::addIntangibleAssetDepreciation() {
    int assetId = ui->comboBox_assetId->currentData().toInt();
    QString expenseType = ui->comboBox_expenseType->currentText();
    QString depreciationMethod = ui->comboBox_depreciationMethod->currentText();
    double salvageValue = ui->lineEdit_salvageValue->text().toDouble();
    QDate depreciationTerm = ui->dateEdit_depreciationTerm->date();

    QSqlQuery query;
    query.prepare("INSERT INTO intangible_assets_depreciation (asset_id, expense_type, depreciation_method, salvage_value, depreciation_term) "
                  "VALUES (:asset_id, :expense_type, :depreciation_method, :salvage_value, :depreciation_term)");
    query.bindValue(":asset_id", assetId);
    query.bindValue(":expense_type", expenseType);
    query.bindValue(":depreciation_method", depreciationMethod);
    query.bindValue(":salvage_value", salvageValue);
    query.bindValue(":depreciation_term", depreciationTerm);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to insert depreciation record: " + query.lastError().text());
        qDebug() << "Failed to insert depreciation record: " << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "Success", "Intangible asset depreciation record added successfully");
    accept(); // Закрыть диалоговое окно после успешного добавления
}

void Authomation::addTangibleAssetDepreciation() {
    int assetId = ui->comboBox_assetId->currentData().toInt();
    QString expenseType = ui->comboBox_expenseType->currentText();
    QString depreciationMethod = ui->comboBox_depreciationMethod->currentText();
    double salvageValue = ui->lineEdit_salvageValue->text().toDouble();
    QDate depreciationTerm = ui->dateEdit_depreciationTerm->date();

    QSqlQuery query;
    query.prepare("INSERT INTO tangible_assets_depreciation (asset_id, expense_type, depreciation_method, salvage_value, depreciation_term) "
                  "VALUES (:asset_id, :expense_type, :depreciation_method, :salvage_value, :depreciation_term)");
    query.bindValue(":asset_id", assetId);
    query.bindValue(":expense_type", expenseType);
    query.bindValue(":depreciation_method", depreciationMethod);
    query.bindValue(":salvage_value", salvageValue);
    query.bindValue(":depreciation_term", depreciationTerm);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to insert depreciation record: " + query.lastError().text());
        qDebug() << "Failed to insert depreciation record: " << query.lastError().text();
        return;
    }

    QMessageBox::information(this, "Success", "Tangible asset depreciation record added successfully");
    accept(); // Закрыть диалоговое окно после успешного добавления
}
