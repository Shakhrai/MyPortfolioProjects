#include "editauthomation.h"
#include "ui_editauthomation.h"

editAuthomation::editAuthomation(QSqlDatabase database, int assetId, bool tangibleStatus, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editAuthomation)
    , db(database)
    , currentAssetId(assetId)

{
    ui->setupUi(this);
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    if (!tangibleStatus) {
        loadDepreciationCodesForIntangible();
        if (currentAssetId != -1) {
            loadDepreciationDataForIntangible(assetId);}
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editAuthomation::saveDepreciationDataForIntangible);
        connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &editAuthomation::cancelButton_clicked);
        connect(ui->pushButton_delete, &QPushButton::clicked, this, &editAuthomation::deleteDepreciationForIntangible);
    } else {
        loadDepreciationCodesForTangible();
        if (currentAssetId != -1) {
            loadDepreciationDataForTangible(assetId);}
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editAuthomation::saveDepreciationDataForTangible);
        connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &editAuthomation::cancelButton_clicked);
        connect(ui->pushButton_delete, &QPushButton::clicked, this, &editAuthomation::deleteDepreciationForTangible);
    }

    ui->comboBox_expenseType->addItems({"Основні засоби", "Інші необоротні активи", "Нематеріальні активи", "Гудвіл", "Інші нематеріальні активи"});
    ui->comboBox_depreciationMethod->addItems({"Прямолінійний метод", "Зменшений залишок", "Виробничий метод"});
}

editAuthomation::~editAuthomation()
{
    delete ui;
}

void editAuthomation::loadDepreciationCodesForIntangible()
{
    QSqlQuery query(db);
    query.prepare("SELECT id, asset_id FROM intangible_assets_depreciation");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load asset codes: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value("id").toInt();
        QString code = query.value("asset_id").toString();
        ui->comboBox_assetId->addItem(code, id);
    }

    ui->comboBox_assetId->setEnabled(false); // Блокируем возможность изменения кода актива
}
void editAuthomation::loadDepreciationDataForIntangible(int assetId)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM intangible_assets_depreciation WHERE asset_id = ?");
    query.addBindValue(assetId);


    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to load depreciation data: " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        qDebug() << "No data found for asset ID:" << assetId;
        QMessageBox::critical(this, "Error", "No data found for asset ID: " + QString::number(assetId));
        return;
    }

    ui->comboBox_expenseType->setCurrentText(query.value("expense_type").toString());
    ui->comboBox_depreciationMethod->setCurrentText(query.value("depreciation_method").toString());
    ui->lineEdit_salvageValue->setText(query.value("salvage_value").toString());
    ui->dateEdit_depreciationTerm->setDate(query.value("depreciation_term").toDate());
    int index = ui->comboBox_assetId->findData(assetId);
    if (index != -1) {
        ui->comboBox_assetId->setCurrentIndex(index);
    }
}
void editAuthomation::saveDepreciationDataForIntangible()
{


    QSqlQuery query(db);
    query.prepare("UPDATE intangible_assets_depreciation SET expense_type = ?, depreciation_method = ?, salvage_value = ?, depreciation_term = ? WHERE asset_id = ?");
    query.addBindValue(ui->comboBox_expenseType->currentText());
    query.addBindValue(ui->comboBox_depreciationMethod->currentText());
    query.addBindValue( ui->lineEdit_salvageValue->text().toDouble());
    query.addBindValue(ui->dateEdit_depreciationTerm->date());
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save depreciation data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Depreciation data saved successfully.");
        accept(); // Закрыть диалоговое окно после сохранения
    }

}
void editAuthomation::deleteDepreciationForIntangible()
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM intangible_assets_depreciation WHERE asset_id = ?");
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete depreciation data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Depreciation data deleted successfully.");
        // Обновить список данных об амортизации для нематериальных активов
        loadDepreciationCodesForIntangible();
        ui->comboBox_assetId->setCurrentIndex(-1); // Сбросить выбор
    }
}
void editAuthomation::loadDepreciationCodesForTangible()
{
    QSqlQuery query(db);
    query.prepare("SELECT id, asset_id FROM tangible_assets_depreciation");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load asset codes: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value("id").toInt();
        QString code = query.value("asset_id").toString();
        ui->comboBox_assetId->addItem(code, id);
    }

    ui->comboBox_assetId->setEnabled(false); // Блокируем возможность изменения кода актива
}


void editAuthomation::loadDepreciationDataForTangible(int assetId)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM tangible_assets_depreciation WHERE asset_id = ?");
    query.addBindValue(assetId);


    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to load depreciation data: " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        qDebug() << "No data found for asset ID:" << assetId;
        QMessageBox::critical(this, "Error", "No data found for asset ID: " + QString::number(assetId));
        return;
    }

    ui->comboBox_expenseType->setCurrentText(query.value("expense_type").toString());
    ui->comboBox_depreciationMethod->setCurrentText(query.value("depreciation_method").toString());
    ui->lineEdit_salvageValue->setText(query.value("salvage_value").toString());
    ui->dateEdit_depreciationTerm->setDate(query.value("depreciation_term").toDate());

    int index = ui->comboBox_assetId->findData(assetId);
    if (index != -1) {
        ui->comboBox_assetId->setCurrentIndex(index);
    }
}

void editAuthomation::saveDepreciationDataForTangible()
{

    QSqlQuery query(db);
    query.prepare("UPDATE tangible_assets_depreciation SET expense_type = ?, depreciation_method = ?, salvage_value = ?, depreciation_term = ? WHERE asset_id = ?");
    query.addBindValue(ui->comboBox_expenseType->currentText());
    query.addBindValue( ui->comboBox_depreciationMethod->currentText());
    query.addBindValue(ui->lineEdit_salvageValue->text().toDouble());
    query.addBindValue(ui->dateEdit_depreciationTerm->date());
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save depreciation data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Depreciation data saved successfully.");
        accept(); // Закрыть диалоговое окно после сохранения
    }
}

void editAuthomation::deleteDepreciationForTangible()
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM tangible_assets_depreciation WHERE asset_id = ?");
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete depreciation data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Depreciation data deleted successfully.");
        // Обновить список данных об амортизации для материальных активов
        loadDepreciationCodesForTangible();
        ui->comboBox_assetId->setCurrentIndex(-1); // Сбросить выбор
    }
}
void editAuthomation::saveButton_clicked()
{
    if (!tangibleStatus) {
        saveDepreciationDataForIntangible();
    } else {
        saveDepreciationDataForTangible();
    }
}

void editAuthomation::deleteButton_clicked()
{
    if (!tangibleStatus) {
        deleteDepreciationForIntangible();
    } else {
        deleteDepreciationForTangible();
    }
}
void editAuthomation::comboBox_code_currentIndexChanged(int index)
{
    int assetId = ui->comboBox_assetId->itemData(index).toInt();
    if (assetId != -1 && assetId != currentAssetId) {
        if (!tangibleStatus) {
            loadDepreciationDataForIntangible(assetId);
        } else {
            loadDepreciationDataForTangible(assetId);
        }
    }
}
void editAuthomation::cancelButton_clicked()
{
    reject(); // Закрыть диалоговое окно без сохранения
}
