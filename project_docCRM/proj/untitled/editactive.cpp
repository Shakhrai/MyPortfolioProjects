#include "editactive.h"
#include "ui_editactive.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

editActive::editActive(QSqlDatabase database, int assetId, bool tangibleStatus, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editActive)
    , db(database)
    , currentAssetId(assetId) // Инициализация переменной currentAssetId
{
    ui->setupUi(this);
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    if (!tangibleStatus) {
        loadAssetCodesForIntangible();
        if (currentAssetId != -1) {
            loadAssetDataForIntangible(currentAssetId);
        }
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editActive::saveAssetDataForIntangible);
        connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &editActive::cancelButton_clicked);
        connect(ui->pushButton_delete, &QPushButton::clicked, this, &editActive::deleteAssetForIntangible);
    } else {
        loadAssetCodesForTangible();
        if (currentAssetId != -1) {
            loadAssetDataForTangible(currentAssetId);
        }
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editActive::saveAssetDataForTangible);
        connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &editActive::cancelButton_clicked);
        connect(ui->pushButton_delete, &QPushButton::clicked, this, &editActive::deleteAssetForTangible);
    }
    ui->comboBox_vid_aktiva_2->addItems({"основні засоби", "інші необоротні активи", "нематеріальні активи", "гудвіл", "інші нематеріальні активи"});
    ui->comboBox_rakhunok_obliku_2->addItems({"10 - Основні засоби 10","100 - Інвестиційна нерухомість 100", "101 - Земельні ділянки 101", "102 - Капітальні витрати на поліпшення земель 102", "103 - Будинки та споруди 103", "104 - Машини та обладнання 104", "105 - Транспорті засоби 105", "106 - Інструменти ,прилади та інвентар 106", "107 - Тварини 107", "108 - Багаторічні насадження 108", "109 - Інші основні засоби 109", "11 - Необоротні матеріальні активи 11", "111 - Бібліотечні фонди 111", "112 - Малоцінні необоротні матеріальні активи 112", "113 - Тимчасові (нетитульні) споруди 113", "114 - Природні ресурси 114", "115 - Інвентарна тара 115", "116 - Предмет прокату 116", "117 - Інші необоротні активи 117", "12 - Нематеріальні активи 12", "121 - Права користування природними ресурсами 121","122 - Права користування майном 122","123 - Права на комерційні позначення 123","124 - Права на об'єкти промислової власності 124","125 - Авторське право та суміжні з ним права 125","127 - Інші нематеріальні активи 127"});
    ui->comboBox_odinitsya_vymiru_2->addItems({"шт", "кг", "л", "м", "м²", "м³", "г", "т"});
    ui->comboBox_vid_diyalnosti_2->addItems({"основна", "додаткова"});
}

editActive::~editActive()
{
    delete ui;
}

void editActive::loadAssetCodesForIntangible()
{
    QSqlQuery query(db);
    query.prepare("SELECT id, code FROM intangible_assets");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load asset codes: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value("id").toInt();
        QString code = query.value("code").toString();
        ui->comboBox_code->addItem(code, id);
    }

    ui->comboBox_code->setEnabled(false); // Блокируем возможность изменения кода актива
}

void editActive::loadAssetDataForIntangible(int assetId)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM intangible_assets WHERE id = ?");
    query.addBindValue(assetId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load asset data: " + query.lastError().text());
        return;
    }

    ui->lineEdit_nazva_2->setText(query.value("name").toString());
    ui->lineEdit_povna_nazva_2->setText(query.value("full_name").toString());
    ui->comboBox_vid_aktiva_2->setCurrentText(query.value("asset_type").toString());
    ui->comboBox_rakhunok_obliku_2->setCurrentText(query.value("account").toString());
    ui->doubleSpinBox_pochatkova_vartist_2->setValue(query.value("initial_cost").toDouble());
    ui->lineEdit_inventarnyy_nomer_2->setText(query.value("inventory_number").toString());
    ui->lineEdit_shifr_2->setText(query.value("cipher").toString());
    ui->comboBox_odinitsya_vymiru_2->setCurrentText(query.value("unit").toString());
    ui->dateEdit_data_vvodu_2->setDate(query.value("entry_date").toDate());
    ui->comboBox_vid_diyalnosti_2->setCurrentText(query.value("activity_type").toString());

    int index = ui->comboBox_code->findData(assetId);
    if (index != -1) {
        ui->comboBox_code->setCurrentIndex(index);
    }
}

void editActive::saveAssetDataForIntangible()
{
    QSqlQuery query(db);
    query.prepare("UPDATE intangible_assets SET name = ?, full_name = ?, asset_type = ?, account = ?, initial_cost = ?, inventory_number = ?, cipher = ?, unit = ?, entry_date = ?, activity_type = ? WHERE id = ?");
    query.addBindValue(ui->lineEdit_nazva_2->text());
    query.addBindValue(ui->lineEdit_povna_nazva_2->text());
    query.addBindValue(ui->comboBox_vid_aktiva_2->currentText());
    query.addBindValue(ui->comboBox_rakhunok_obliku_2->currentText().split(" - ").first());
    query.addBindValue(ui->doubleSpinBox_pochatkova_vartist_2->value());
    query.addBindValue(ui->lineEdit_inventarnyy_nomer_2->text());
    query.addBindValue(ui->lineEdit_shifr_2->text());
    query.addBindValue(ui->comboBox_odinitsya_vymiru_2->currentText());
    query.addBindValue(ui->dateEdit_data_vvodu_2->date());
    query.addBindValue(ui->comboBox_vid_diyalnosti_2->currentText());
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save asset data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Asset data saved successfully.");
        accept(); // Закрыть диалоговое окно после сохранения
    }
}

void editActive::deleteAssetForIntangible()
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM intangible_assets WHERE id = ?");
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete asset: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Asset deleted successfully.");
        // Обновить список кодов активов
        loadAssetCodesForIntangible();
        ui->comboBox_code->setCurrentIndex(-1); // Сбросить выбор
    }
}

void editActive::loadAssetCodesForTangible()
{
    QSqlQuery query(db);
    query.prepare("SELECT id, code FROM tangible_assets");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to load asset codes: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value("id").toInt();
        QString code = query.value("code").toString();
        ui->comboBox_code->addItem(code, id);
    }

    ui->comboBox_code->setEnabled(false); // Блокируем возможность изменения кода актива
}

void editActive::loadAssetDataForTangible(int assetId)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM tangible_assets WHERE id = ?");
    query.addBindValue(assetId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Failed to load asset data: " + query.lastError().text());
        return;
    }

    ui->lineEdit_nazva_2->setText(query.value("name").toString());
    ui->lineEdit_povna_nazva_2->setText(query.value("full_name").toString());
    ui->comboBox_vid_aktiva_2->setCurrentText(query.value("asset_type").toString());
    ui->comboBox_rakhunok_obliku_2->setCurrentText(query.value("account").toString());
    ui->doubleSpinBox_pochatkova_vartist_2->setValue(query.value("initial_cost").toDouble());
    ui->lineEdit_inventarnyy_nomer_2->setText(query.value("inventory_number").toString());
    ui->lineEdit_shifr_2->setText(query.value("cipher").toString());
    ui->comboBox_odinitsya_vymiru_2->setCurrentText(query.value("unit").toString());
    ui->dateEdit_data_vvodu_2->setDate(query.value("entry_date").toDate());
    ui->comboBox_vid_diyalnosti_2->setCurrentText(query.value("activity_type").toString());

    int index = ui->comboBox_code->findData(assetId);
    if (index != -1) {
        ui->comboBox_code->setCurrentIndex(index);
    }
}

void editActive::saveAssetDataForTangible()
{
    QSqlQuery query(db);
    query.prepare("UPDATE tangible_assets SET name = ?, full_name = ?, asset_type = ?, account = ?, initial_cost = ?, inventory_number = ?, cipher = ?, unit = ?, entry_date = ?, activity_type = ? WHERE id = ?");
    query.addBindValue(ui->lineEdit_nazva_2->text());
    query.addBindValue(ui->lineEdit_povna_nazva_2->text());
    query.addBindValue(ui->comboBox_vid_aktiva_2->currentText());
    query.addBindValue(ui->comboBox_rakhunok_obliku_2->currentText().split(" - ").first());
    query.addBindValue(ui->doubleSpinBox_pochatkova_vartist_2->value());
    query.addBindValue(ui->lineEdit_inventarnyy_nomer_2->text());
    query.addBindValue(ui->lineEdit_shifr_2->text());
    query.addBindValue(ui->comboBox_odinitsya_vymiru_2->currentText());
    query.addBindValue(ui->dateEdit_data_vvodu_2->date());
    query.addBindValue(ui->comboBox_vid_diyalnosti_2->currentText());
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to save asset data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Asset data saved successfully.");
        accept(); // Закрыть диалоговое окно после сохранения
    }
}

void editActive::deleteAssetForTangible()
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM tangible_assets WHERE id = ?");
    query.addBindValue(currentAssetId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete asset: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Asset deleted successfully.");
        // Обновить список кодов активов
        loadAssetCodesForTangible();
        ui->comboBox_code->setCurrentIndex(-1); // Сбросить выбор
    }
}

void editActive::saveButton_clicked()
{
    if (!tangibleStatus) {
        saveAssetDataForIntangible();
    } else {
        saveAssetDataForTangible();
    }
}

void editActive::deleteButton_clicked()
{
    if (!tangibleStatus) {
        deleteAssetForIntangible();
    } else {
        deleteAssetForTangible();
    }
}

void editActive::on_comboBox_code_currentIndexChanged(int index)
{
    int assetId = ui->comboBox_code->itemData(index).toInt();
    if (assetId != -1 && assetId != currentAssetId) {
        if (!tangibleStatus) {
            loadAssetDataForIntangible(assetId);
        } else {
            loadAssetDataForTangible(assetId);
        }
    }
}
void editActive::cancelButton_clicked()
{
    reject(); // Закрыть диалоговое окно без сохранения
}



