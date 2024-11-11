#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nonematerialactives.h"
#include "generatereport.h"
#include "dbcreate.h"
#include "tablepage.h"
#include "editactive.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QStandardItemModel>
#include <QTextDocument>
#include <QPrinter>
#include <QInputDialog>
#include <QDateEdit>
#include <QProcess>
#include <QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/image_blr_backgr.jpg");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");


    // Load the stylesheet



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTables()
{
    if (!db.isOpen()) {
        ui->statusbar->showMessage("Database is not open!");

        return;
    }

    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS intangible_assets ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "code TEXT, "
                    "name TEXT, "
                    "full_name TEXT, "
                    "asset_type TEXT, "
                    "account TEXT, "
                    "initial_cost REAL, "
                    "inventory_number TEXT, "
                    "cipher TEXT, "
                    "unit TEXT, "
                    "entry_date DATE, "
                    "activity_type TEXT)")) {
        QMessageBox::critical(this, "Error", "Failed to create table: " + query.lastError().text());
        qDebug() << "Failed to create table: " << query.lastError().text();
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS tangible_assets ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "code TEXT, "
                    "name TEXT, "
                    "full_name TEXT, "
                    "asset_type TEXT, "
                    "account TEXT, "
                    "initial_cost REAL, "
                    "inventory_number TEXT, "
                    "cipher TEXT, "
                    "unit TEXT, "
                    "entry_date DATE, "
                    "activity_type TEXT)")) {
        QMessageBox::critical(this, "Error", "Failed to create table: " + query.lastError().text());
        qDebug() << "Failed to create table: " << query.lastError().text();
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS intangible_assets_depreciation ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "asset_id INTEGER, "
                    "expense_type TEXT, "
                    "depreciation_method TEXT, "
                    "salvage_value REAL, "
                    "depreciation_term DATE, "
                    "FOREIGN KEY(asset_id) REFERENCES intangible_assets(id))")) {
        QMessageBox::critical(this, "Error", "Failed to create table 'intangible_assets_depreciation': " + query.lastError().text());
        // qDebug() << "Failed to create table 'intangible_assets_depreciation': " << query.lastError().text();
        ui->statusbar->showMessage("Failed to create table 'intangible_assets_depreciation': " + query.lastError().text());
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS tangible_assets_depreciation ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "asset_id INTEGER, "
                    "expense_type TEXT, "
                    "depreciation_method TEXT, "
                    "salvage_value REAL, "
                    "depreciation_term DATE, "
                    "FOREIGN KEY(asset_id) REFERENCES tangible_assets(id))")) {
        QMessageBox::critical(this, "Error", "Failed to create table 'tangible_assets_depreciation': " + query.lastError().text());
        //qDebug() << "Failed to create table 'tangible_assets_depreciation': " << query.lastError().text();
        ui->statusbar->showMessage("Failed to create table 'tangible_assets_depreciation': "+ query.lastError().text());
    }
}

void MainWindow::on_action_cut_triggered()
{
    ui->commentSpace->cut();
}

void MainWindow::on_action_copy_triggered()
{
    ui->commentSpace->copy();
}

void MainWindow::on_action_paste_triggered()
{
    ui->commentSpace->paste();
}

void MainWindow::on_action_redo_triggered()
{
    ui->commentSpace->redo();
}

void MainWindow::on_action_undo_triggered()
{
    ui->commentSpace->undo();
}

void MainWindow::on_pushButton_createNewDb_clicked()
{
    dbcreate dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        dbName = dialog.getDatabaseName();
        db.setDatabaseName(dbName);

        if (!db.open()) {
            QMessageBox::critical(this, "Error", "Failed to open database: " + db.lastError().text());
            //qDebug() << "Failed to open database: " << db.lastError().text();
            ui->statusbar->showMessage("Failed to open database: " + db.lastError().text());
            return;
        }

        createTables();

        tablepage *tbl_p = new tablepage(dbName, this);
        tbl_p->show();
    }
}

void MainWindow::on_action_new_triggered()
{
    dbcreate dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        dbName = dialog.getDatabaseName();
        db.setDatabaseName(dbName);

        if (!db.open()) {
            QMessageBox::critical(this, "Error", "Failed to open database: " + db.lastError().text());
            //qDebug() << "Failed to open database: " << db.lastError().text();
            ui->statusbar->showMessage("Failed to open database: " + db.lastError().text());
            return;
        }

        createTables();

        tablepage *tbl_p = new tablepage(dbName, this);
        tbl_p->show();
    }
}

void MainWindow::on_pushButton_generalView_clicked()
{
    tablepage *tbl_p = new tablepage(dbName, this);
    tbl_p->setAttribute(Qt::WA_DeleteOnClose);
    tbl_p->show();
}

void MainWindow::on_action_quit_triggered()
{
    close();
}

void MainWindow::on_action_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Database"), "", tr("Database Files (*.db *.sqlite *.sqlite3);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }

    db.setDatabaseName(fileName);

    if (!db.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open database"));
        return;
    }

    dbName = fileName;
    //qDebug() << "Database opened: " << dbName;
    ui->statusbar->showMessage( "Database opened: " + dbName);
    ui->pushButton_generalView->setEnabled(true);
    ui->pushButton_createNewDb->setEnabled(false);
}

void MainWindow::on_action_nmActives_triggered()
{
    NoneMaterialActives *nmActives = new NoneMaterialActives(true, db, this);
    nmActives->exec();
}

void MainWindow::on_action_saveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Database"), "", tr("Database Files (*.db *.sqlite *.sqlite3)"));
    if (fileName.isEmpty()) {
        return;
    }

    db.setDatabaseName(fileName);

    if (!db.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to create database"));
        return;
    }

    createTables();

    QMessageBox::information(this, tr("Success"), tr("Database created and saved successfully"));
}

void MainWindow::on_action_fixedAss_triggered()
{
    NoneMaterialActives *nmActives = new NoneMaterialActives(false, db, this);
    nmActives->exec();
}

void MainWindow::on_action_amActive_triggered()
{
    bool isIntangible = true;
    Authomation *form = new Authomation(isIntangible, db, this);
    form->exec();
}

void MainWindow::on_action_amFixedAss_triggered()
{
    bool isIntangible = false;
    Authomation *form = new Authomation(isIntangible, db, this);
    form->exec();
}

void MainWindow::on_action_generalView_triggered()
{
    on_pushButton_generalView_clicked();
}

void MainWindow::on_action_generateAssetsReport_triggered()
{
    generateReport *generateRep = new generateReport("assets_report", db, this);
    generateRep->exec();
}

void MainWindow::on_action_generateDepreciationReport_triggered()
{
    generateReport *generateRep = new generateReport("depreciation_report", db, this);
    generateRep->exec();
}

void MainWindow::on_action_generateMoveReport_triggered()
{
    generateReport *generateRep = new generateReport("move_report", db, this);
    generateRep->exec();
}

void MainWindow::on_action_generateInventoryReport_triggered()
{
    generateReport *generateRep = new generateReport("inventory_report", db, this);
    generateRep->exec();
}

void MainWindow::on_action_generateCategoryReport_triggered()
{
    generateReport *generateRep = new generateReport("category_report", db, this);
    generateRep->exec();
}

void MainWindow::on_action_aboutQt_triggered()
{
    QString aboutText = "Qt – це кросплатформовий фреймворк для розробки програмного забезпечення. "
                        "Він дозволяє створювати високопродуктивні та сучасні застосунки для різних "
                        "платформ, включаючи Windows, macOS, Linux, Android та iOS.\n\n"
                        "Qt включає в себе широкий набір інструментів і бібліотек, які забезпечують багато "
                        "можливостей для створення графічного інтерфейсу, роботи з мережею, базами даних, "
                        "мультимедіа та багато іншого.\n\n"
                        "Завдяки своїй кросплатформенності та потужним функціональним можливостям, Qt "
                        "широко використовується для розробки як настільних, так і мобільних застосунків, а також "
                        "для вбудованих систем та Інтернету речей.";

    QMessageBox::about(this, "Про Qt", aboutText);
}


void MainWindow::on_action_aboutAuth_triggered()
{
    QMessageBox::information(this, "Author", "Программа розроблена Студентом Ін-403,\nРозробник: Шахрай Дмитро Ігорович\n Для розробки був використанний open-source QT\n Not for comercial uses");
}

void MainWindow::on_action_print_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Виберіть PDF файл", "", "PDF Files (*.pdf)");

    if (!fileName.isEmpty())
    {
        QPrinter printer(QPrinter::HighResolution);
        printer.setPrinterName("Printer Name");

        QPrintDialog dialog(&printer, this);
        if (dialog.exec() == QDialog::Accepted)
        {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::critical(this, "Помилка", "Не вдалося відкрити файл для друку");
                return;
            }

            QTextDocument document;
            document.setHtml(file.readAll());

            document.print(&printer);
            file.close();
        }
    }
}

void MainWindow::on_action_Wiki_triggered()
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





