#include "nonematerialactives.h"
#include "ui_nonematerialactives.h"
#include <authomation.h>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

NoneMaterialActives::NoneMaterialActives(const bool isNMA, QSqlDatabase database,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoneMaterialActives)
    , db(database)
{
    ui->setupUi(this);
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to open the database: " + db.lastError().text());
        return;
    }

    // Заполнение виджетов списка (ComboBox)
    ui->comboBox_vid_aktiva->addItems({"основні засоби", "інші необоротні активи", "нематеріальні активи", "гудвіл", "інші нематеріальні активи"});
    ui->comboBox_rakhunok_obliku->addItems({"10 - Основні засоби 10","100 - Інвестиційна нерухомість 100", "101 - Земельні ділянки 101", "102 - Капітальні витрати на поліпшення земель 102", "103 - Будинки та споруди 103", "104 - Машини та обладнання 104", "105 - Транспорті засоби 105", "106 - Інструменти ,прилади та інвентар 106", "107 - Тварини 107", "108 - Багаторічні насадження 108", "109 - Інші основні засоби 109", "11 - Необоротні матеріальні активи 11", "111 - Бібліотечні фонди 111", "112 - Малоцінні необоротні матеріальні активи 112", "113 - Тимчасові (нетитульні) споруди 113", "114 - Природні ресурси 114", "115 - Інвентарна тара 115", "116 - Предмет прокату 116", "117 - Інші необоротні активи 117", "12 - Нематеріальні активи 12", "121 - Права користування природними ресурсами 121","122 - Права користування майном 122","123 - Права на комерційні позначення 123","124 - Права на об'єкти промислової власності 124","125 - Авторське право та суміжні з ним права 125","127 - Інші нематеріальні активи 127"});
    ui->comboBox_odinitsya_vymiru->addItems({"шт", "кг", "л", "м", "м²", "м³", "г", "т"});
    ui->comboBox_vid_diyalnosti->addItems({"основна", "додаткова"});
    if (isNMA)
    {
        ui->comboBox_vid_aktiva->setCurrentIndex(2);
        ui->comboBox_rakhunok_obliku->setCurrentIndex(11);
        connect(ui->pushButton_2, &QPushButton::clicked, this, &NoneMaterialActives::IntangibleAssetDepreciation);
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &NoneMaterialActives::buttonBox_accepted_for_InTangibleAsset);

    }
    else
    {
        ui->comboBox_vid_aktiva->setCurrentIndex(0);
        ui->comboBox_rakhunok_obliku->setCurrentIndex(0);
        connect(ui->pushButton_2, &QPushButton::clicked, this, &NoneMaterialActives::TangibleAssetDepreciation);
        connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &NoneMaterialActives::buttonBox_accepted_for_TangibleAsset);
    }
}

NoneMaterialActives::~NoneMaterialActives()
{
    delete ui;
}

void NoneMaterialActives::TangibleAssetDepreciation()
{
    // Определите, для какого типа активов вы хотите добавить амортизацию
    bool isIntangible = false; // или false, в зависимости от вашего выбора

    Authomation *form = new Authomation(isIntangible, db,this);
    form->exec(); // Покажите форму как модальное диалоговое окно

}
void NoneMaterialActives::IntangibleAssetDepreciation()
{
    // Определите, для какого типа активов вы хотите добавить амортизацию
    bool isIntangible = true; // или false, в зависимости от вашего выбора

    Authomation *form = new Authomation(isIntangible,db, this);
    form->exec(); // Покажите форму как модальное диалоговое окно
}

void NoneMaterialActives::buttonBox_accepted_for_InTangibleAsset()
{

    QString code = ui->lineEdit_kod->text();
    QString name = ui->lineEdit_nazva->text();
    QString fullName = ui->lineEdit_povna_nazva->text();
    QString assetType = ui->comboBox_vid_aktiva->currentText();
    QString account = ui->comboBox_rakhunok_obliku->currentText().split(" - ").first();
    double initialCost = ui->doubleSpinBox_pochatkova_vartist->value();
    QString inventoryNumber = ui->lineEdit_inventarnyy_nomer->text();
    QString cipher = ui->lineEdit_shifr->text();
    QString unit = ui->comboBox_odinitsya_vymiru->currentText();
    QDate entryDate = ui->dateEdit_data_vvodu->date();
    QString activityType = ui->comboBox_vid_diyalnosti->currentText();

    if (code.isEmpty() || name.isEmpty() || fullName.isEmpty() || inventoryNumber.isEmpty() || cipher.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO intangible_assets (code, name, full_name, asset_type, account, initial_cost, inventory_number, cipher, unit, entry_date, activity_type) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(code);
    query.addBindValue(name);
    query.addBindValue(fullName);
    query.addBindValue(assetType);
    query.addBindValue(account);
    query.addBindValue(initialCost);
    query.addBindValue(inventoryNumber);
    query.addBindValue(cipher);
    query.addBindValue(unit);
    query.addBindValue(entryDate);
    query.addBindValue(activityType);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to insert data into database.");
    } else {
        QMessageBox::information(this, "Success", "Data has been successfully added to the database.");
        this->accept(); // Закрыть окно при успешном добавлении данных
    }

}
void NoneMaterialActives::buttonBox_accepted_for_TangibleAsset()
{

    QString code = ui->lineEdit_kod->text();
    QString name = ui->lineEdit_nazva->text();
    QString fullName = ui->lineEdit_povna_nazva->text();
    QString assetType = ui->comboBox_vid_aktiva->currentText();
    QString account = ui->comboBox_rakhunok_obliku->currentText().split(" - ").first();
    double initialCost = ui->doubleSpinBox_pochatkova_vartist->value();
    QString inventoryNumber = ui->lineEdit_inventarnyy_nomer->text();
    QString cipher = ui->lineEdit_shifr->text();
    QString unit = ui->comboBox_odinitsya_vymiru->currentText();
    QDate entryDate = ui->dateEdit_data_vvodu->date();
    QString activityType = ui->comboBox_vid_diyalnosti->currentText();

    if (code.isEmpty() || name.isEmpty() || fullName.isEmpty() || inventoryNumber.isEmpty() || cipher.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO tangible_assets (code, name, full_name, asset_type, account, initial_cost, inventory_number, cipher, unit, entry_date, activity_type) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(code);
    query.addBindValue(name);
    query.addBindValue(fullName);
    query.addBindValue(assetType);
    query.addBindValue(account);
    query.addBindValue(initialCost);
    query.addBindValue(inventoryNumber);
    query.addBindValue(cipher);
    query.addBindValue(unit);
    query.addBindValue(entryDate);
    query.addBindValue(activityType);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to insert data into database.");
    } else {
        QMessageBox::information(this, "Success", "Data has been successfully added to the database.");
        this->accept(); // Закрыть окно при успешном добавлении данных
    }

}



void NoneMaterialActives::on_pushButton_clicked()
{
    QString aboutText = "Нематеріальні активи\n"
                        "Нематеріальні активи - це активи, які не мають фізичної форми, але мають цінність для підприємства. Вони включають інтелектуальну власність та інші активи, які можуть приносити дохід або забезпечувати конкурентні переваги.\n"
                        "Приклади нематеріальних активів:\n"
                        "\n"
                        "Патенти — права на винаходи, які забезпечують ексклюзивне використання та захист від копіювання іншими.\n"
                        "Авторські права - права на літературні, музичні та інші художні твори, що забезпечують захист від несанкціонованого використання.\n"
                        "Торгові марки — це символи, назви або логотипи, які відрізняють товари або послуги однієї компанії від інших.\n"
                        "Франшизи - права на використання бізнес-моделі або бренду іншої компанії.\n"
                        "Ділова репутація (гудвілл) — нематеріальна цінність компанії, пов'язана з її репутацією, клієнтською базою та іншими нематеріальними факторами, які можуть підвищити її ринкову вартість.\n"
                        "Програмне забезпечення — ліцензії на використання певних програмних продуктів.\n"
                        "\n"
                        "Основні засоби\n"
                        "Основні кошти - це матеріальні активи, які використовуються у виробничій діяльності компанії та мають тривалий термін служби. Вони включають фізичні об'єкти, які необхідні для функціонування підприємства.\n"
                        "Приклади основних засобів:\n"
                        "\n"
                        "Земля — ділянки землі, що використовуються для розміщення будівель, сільськогосподарських потреб чи інших цілей.\n"
                        "Будівлі та споруди — офісні будівлі, фабрики, склади та інші будівлі, що використовуються для ведення бізнесу.\n"
                        "Машини та обладнання — виробничі машини, інструменти, транспортні засоби та інші пристрої, що використовуються у виробничому процесі.\n"
                        "Комп'ютери та офісна техніка — комп'ютери, принтери, сканери та інші пристрої, необхідні для адміністративної діяльності.\n"
                        "Меблі та офісне обладнання - столи, стільці, шафи та інші предмети, що використовуються в офісах та інших робочих місцях.\n"
                        "\n"
                        "Відмінність нематеріальних активів від основних засобів:\n"
                        "Фізична форма:\n"
                        "Нематеріальні активи: Не мають фізичної форми.\n"
                        "Основні засоби: Мають фізичну форму.\n"
                        "\n"
                        "Природа використання:\n"
                        "Нематеріальні активи: В основному пов'язані з правами, інтелектуальною власністю та іншими нематеріальними перевагами.\n"
                        "Основні засоби: Використовуються у виробничій та адміністративній діяльності підприємства, забезпечуючи фізичну інфраструктуру.\n"
                        "\n"
                        "Спосіб амортизації:\n"
                        "Нематеріальні активи: Амортизація зазвичай розраховується на основі терміну корисного використання активів, який може бути обмежений або необмежений.\n"
                        "Основні засоби: Амортизація розраховується на основі фізичного зносу та терміну служби активів.\n";

    QMessageBox::about(this, "Про Нематеріальні активи і основні засоби", aboutText);

}

