#include "generatereport.h"
#include "ui_generatereport.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDate>
#include <QFontMetrics>
generateReport::generateReport(QString reportType, QSqlDatabase database, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::generateReport)
    , db(database)
{
    ui->setupUi(this);

    if (reportType == " ")
    {
        QMessageBox::critical(this, "Report Error", "Failed to open the report: ");
        return;
    }
    else
    {
        if (reportType == "assets_report")
        {
            ui->lineEdit_chosed_report->setText("Звіт з активів");
            setFieldsForAssetsReport();
            connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &generateReport::generateAssetsReport);
        }
        else if (reportType == "depreciation_report")
        {
            ui->lineEdit_chosed_report->setText("Звіт з амортизації");
            setFieldsForDepreciationReport();
            connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &generateReport::generateDepreciationReport);
        }
        else if (reportType == "move_report")
        {
            ui->lineEdit_chosed_report->setText("Звіт руху активів");
            setFieldsForMoveReport();
            connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &generateReport::generateMoveReport);
        }
        else if (reportType == "inventory_report")
        {
            ui->lineEdit_chosed_report->setText("Інвентарна картка");
            setFieldsForInventoryReport();
            connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &generateReport::generateInventoryReport);
        }
        else if (reportType == "category_report")
        {
            ui->lineEdit_chosed_report->setText("Звіт з категорій активів");
            setFieldsForCategoryReport();
            connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &generateReport::generateCategoryReport);
        }

        ui->comboBox_active_type->addItems({"основні засоби", "інші необоротні активи", "нематеріальні активи","інші нематеріальні активи"});
        ui->comboBox_operation_type->addItems({"придбання", "вибуття", "зміна вартості", "амортизація", "ремонт/обслуговування", "модернізація", "оренда", "повернення з оренди", "зміна місцезнаходження", "зміна відповідальної особи", "злиття", "поділ"});
        ui->comboBox_depreciation_method->addItems({"Прямолінійний метод", "Зменшений залишок", "Виробничий метод"});


        connect(ui->comboBox_active_type, &QComboBox::currentTextChanged, this, &generateReport::on_activeTypeChanged);
        connect(ui->comboBox_active_code, &QComboBox::currentTextChanged, this, &generateReport::on_activeCodeChanged);
    }
}

generateReport::~generateReport()
{
    delete ui;
}

void generateReport::on_activeTypeChanged(const QString &type)
{
    populateActiveCodes(type);
}

void generateReport::on_activeCodeChanged(const QString &code)
{
    QString type = ui->comboBox_active_type->currentText();
    populateActiveCategory(code, type);
    populateDateRange(code, type);
}

void generateReport::populateActiveCodes(const QString &type)
{
    ui->comboBox_active_code->clear();

    QString queryStr;
    if (type == "нематеріальні активи" || type == "інші нематеріальні активи")
    {
        queryStr = "SELECT code FROM intangible_assets";
    }
    else if (type == "основні засоби")
    {
        queryStr = "SELECT code FROM tangible_assets";
    }
    else
    {
        return; // Для других типов активов не обновляем список кодов
    }

    QSqlQuery query(db);
    if (!query.exec(queryStr))
    {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve asset codes: " + query.lastError().text());
        return;
    }

    while (query.next())
    {
        ui->comboBox_active_code->addItem(query.value(0).toString());
    }
}

void generateReport::populateActiveCategory(const QString &code, const QString &type)
{
    QString queryStr;
    if (type == "нематеріальні активи" || type == "інші нематеріальні активи")
    {
        queryStr = "SELECT account FROM intangible_assets WHERE code = ?";
    }
    else if (type == "основні засоби")
    {
        queryStr = "SELECT account FROM tangible_assets WHERE code = ?";
    }
    else
    {
        return; // Для других типов активов не обновляем категорию
    }

    QSqlQuery query(db);
    query.prepare(queryStr);
    query.addBindValue(code);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve asset account: " + query.lastError().text());
        return;
    }

    if (query.next())
    {
        ui->comboBox_active_category->clear();
        ui->comboBox_active_category->addItem(query.value(0).toString());
    }
}

void generateReport::populateDateRange(const QString &code, const QString &type)
{
    QString queryStr;
    if (type == "нематеріальні активи" || type == "інші нематеріальні активи")
    {
        queryStr = "SELECT MIN(entry_date) AS start_date, MAX(entry_date) AS end_date FROM intangible_assets WHERE code = ?";
    }
    else if (type == "основні засоби")
    {
        queryStr = "SELECT MIN(entry_date) AS start_date, MAX(entry_date) AS end_date FROM tangible_assets WHERE code = ?";
    }
    else
    {
        return; // Для других типов активов не обновляем диапазон дат
    }

    QSqlQuery query(db);
    query.prepare(queryStr);
    query.addBindValue(code);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve date range: " + query.lastError().text());
        return;
    }

    if (query.next())
    {
        QDate startDate = query.value("start_date").toDate();
        QDate endDate = query.value("end_date").toDate();
        ui->dateEdit_from->setDate(startDate);
        ui->dateEdit_to->setDate(endDate);
    }
}

void generateReport::setFieldsForAssetsReport()
{
    // Активируем только те поля, которые нужны для отчета об активах
    ui->comboBox_operation_type->setEnabled(false);
    ui->dateEdit_from->setEnabled(true);
    ui->dateEdit_to->setEnabled(true);
    ui->comboBox_depreciation_method->setEnabled(false);
    // и т.д.
}

void generateReport::setFieldsForDepreciationReport()
{
    // Активируем только те поля, которые нужны для отчета об амортизации
    ui->comboBox_operation_type->setEnabled(false);
    ui->dateEdit_from->setEnabled(true);
    ui->dateEdit_to->setEnabled(true);
    ui->comboBox_depreciation_method->setEnabled(true);
    // и т.д.
}

void generateReport::setFieldsForMoveReport()
{
    // Активируем только те поля, которые нужны для отчета о движении активов
    ui->comboBox_operation_type->setEnabled(true);
    ui->dateEdit_from->setEnabled(true);
    ui->dateEdit_to->setEnabled(true);
    ui->comboBox_depreciation_method->setEnabled(false);
    // и т.д.
}

void generateReport::setFieldsForInventoryReport()
{
    // Активируем только те поля, которые нужны для отчета по инвентарному номеру
    ui->comboBox_operation_type->setEnabled(false);
    ui->dateEdit_from->setEnabled(false);
    ui->dateEdit_to->setEnabled(false);
    ui->comboBox_depreciation_method->setEnabled(false);
    // и т.д.
}

void generateReport::setFieldsForCategoryReport()
{
    // Активируем только те поля, которые нужны для отчета по категориям активов
    ui->comboBox_operation_type->setEnabled(false);
    ui->dateEdit_from->setEnabled(false);
    ui->dateEdit_to->setEnabled(false);
    ui->comboBox_depreciation_method->setEnabled(false);
    // и т.д.
}

void generateReport::generateAssetsReport()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти звіт"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // User canceled saving
    }

    // Prepare the SQL query
    QSqlQuery query(db);
    QString selectedCode = ui->comboBox_active_code->currentText();
    QString selectedCategory = ui->comboBox_active_category->currentText();
    QString startDate = ui->dateEdit_from->date().toString("yyyy-MM-dd");
    QString endDate = ui->dateEdit_to->date().toString("yyyy-MM-dd");

    QString queryStr = "SELECT * FROM intangible_assets WHERE code = ? AND account = ? AND entry_date BETWEEN ? AND ?";
    query.prepare(queryStr);
    query.addBindValue(selectedCode);
    query.addBindValue(selectedCategory);
    query.addBindValue(startDate);
    query.addBindValue(endDate);

    // Check for query execution error
    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося виконати запит: " + query.lastError().text());
        return;
    }

    // Create PDF writer
    QPdfWriter writer(fileName);

    // Set page size based on Qt version (adjust as needed)
    writer.setPageSize(QPageSize(QPageSize::A4)); // Use setPageSize for Qt 5.6+

    // Create painter object for drawing on the PDF
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // Define margins for better readability
    const int marginX = 250;
    const int marginY = 250;
    int y = marginY; // Starting position with margin

    // Draw report header with dynamic centering
    int textWidth = painter.fontMetrics().horizontalAdvance("Звіт про активи\n");
    painter.drawText((writer.width() - textWidth) / 2, y, "Звіт про активи\n");
    y += 520;




    // Draw table header (optional)
    QStringList headers = {"Код", "Назва", "Повна назва", "Тип актива", "Рахунок", "Початкова вартість", "Інвентарний номер", "Шифр", "Одиниця виміру", "Дата вводу", "Тип активності"};
    QVector<int> columnWidths = {400, 1050, 2000, 2000, 2000, 1050, 3050, 2000, 3000, 3400, 3000};
    int tableX = marginX;
    int tableY = y;
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(tableX, tableY, headers[i]);
        tableX += columnWidths[i];
    }
    tableY += 520;

    // Loop through query results and draw asset information
    while (query.next()) {
        tableX = marginX;
        for (int i = 0; i < headers.size(); ++i) {
            QString data = query.value(i).toString();
            painter.drawText(tableX, tableY, data);
            tableX += columnWidths[i];
        }
        tableY += 520;
    }

                                            textWidth = painter.fontMetrics().horizontalAdvance("Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    painter.drawText(((writer.width() - textWidth) / 2)+3500, y+4000, "Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    y += 620;

    // Draw signature line (optional)
    textWidth = painter.fontMetrics().horizontalAdvance("Підпис: _____________________\n");
    painter.drawText(((writer.width() - textWidth) / 2)+3500, y+4000, "Підпис: _____________________\n");
    y += 620; // Move down for table data
    // Show success message after saving the report
    QMessageBox::information(this, "Успішно", "Звіт про активи збережено у файлі " + fileName);
}

void generateReport::generateMoveReport()
{
    // Get filename for saving the report
    QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти звіт"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // User canceled saving
    }

    // Prepare the SQL query
    QSqlQuery query(db);
    QString selectedCode = ui->comboBox_active_code->currentText();
    QString selectedCategory = ui->comboBox_active_category->currentText();
    QString startDate = ui->dateEdit_from->date().toString("yyyy-MM-dd");
    QString endDate = ui->dateEdit_to->date().toString("yyyy-MM-dd");

    QString tableName;
    if (selectedCategory == "нематеріальні активи" || selectedCategory == "інші нематеріальні активи") {
        tableName = "intangible_assets";
    } else if (selectedCategory == "основні засоби") {
        tableName = "tangible_assets";
    } else {
        QMessageBox::critical(this, "Error", "Invalid asset category selected.");
        return;
    }

    QString queryStr = "SELECT * FROM " + tableName + " WHERE code = ? AND account = ? AND entry_date BETWEEN ? AND ?";
    query.prepare(queryStr);
    query.addBindValue(selectedCode);
    query.addBindValue(selectedCategory);
    query.addBindValue(startDate);
    query.addBindValue(endDate);

    // Check for query execution error
    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося виконати запит: " + query.lastError().text());
        return;
    }

    // Create PDF writer
    QPdfWriter writer(fileName);

    // Set page size based on Qt version (adjust as needed)
    writer.setPageSize(QPageSize(QPageSize::A4)); // Use setPageSize for Qt 5.6+

    // Create painter object for drawing on the PDF
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // Define margins for better readability
    const int marginX = 50;
    const int marginY = 50;
    int y = marginY; // Starting position with margin

    // Draw report header with dynamic centering
    int textWidth = painter.fontMetrics().horizontalAdvance("Звіт про переміщення активів\n");
    painter.drawText((writer.width() - textWidth) / 2, y, "Звіт про переміщення активів\n");
    y += 20;

    // Draw table header
    painter.drawText(marginX, y, "Назва активу");
    painter.drawText(marginX + 200, y, "Код активу");
    // Add more headers as needed

    // Move to next line
    y += 20;

    // Loop through query results and draw asset information
    while (query.next()) {
        QString assetName = query.value("name").toString();
        QString assetCode = query.value("code").toString();
        // Retrieve more information as needed from the query result

        // Draw asset information
        painter.drawText(marginX, y, assetName);
        painter.drawText(marginX + 200, y, assetCode);
        // Draw more information as needed

        // Move to next line
        y += 20;
    }

    // Show success message after saving the report
    QMessageBox::information(this, "Успішно", "Звіт про переміщення активів збережено у файлі " + fileName);
}

void generateReport::generateInventoryReport()
{

        QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти звіт"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // Пользователь отменил сохранение
    }

    QSqlQuery query(db);
    QString assetID = ui->comboBox_active_code->currentText(); // Получаем ID актива из интерфейса
    QString queryStr = "SELECT * FROM intangible_assets WHERE id = ?";
    query.prepare(queryStr);
    query.addBindValue(assetID);

    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка", "Не вдалось виконати запит: " + query.lastError().text());
        return;
    }

    // Создаем PDF-писателя
    QPdfWriter writer(fileName);

    // Устанавливаем размер страницы (можно настроить по желанию)
    writer.setPageSize(QPageSize(QPageSize::A4));

    // Создаем рисовальщика для работы с PDF
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));


    const int marginX = 50;
    const int marginY = 50;
    int y = marginY; // Начальная позиция с отступом

    // Рисуем заголовок отчета
    int textWidth = painter.fontMetrics().horizontalAdvance("Інвентарна карточка актива\n");
    painter.drawText((writer.width() - textWidth) / 2, y, "Інвентарна карточка актива\n");
    y += 620;

    // Получаем данные об активе из запроса
    if (query.next()) {
        QString assetName = query.value("name").toString();
        QString assetCode = query.value("code").toString();
        QString assetType = query.value("asset_type").toString();
        QString entryDate = query.value("entry_date").toDate().toString("dd.MM.yyyy");
        QString initialCost = query.value("initial_cost").toString();
        QString inventoryNumber = query.value("inventory_number").toString();
        QString account = query.value("account").toString();
        QString unit = query.value("unit").toString();


        // Выводим информацию об активе на карточку
        painter.drawText(marginX, y, "Назва актива: " + assetName);
        y += 620;
        painter.drawText(marginX, y, "Код актива: " + assetCode);
        y += 620;
        painter.drawText(marginX, y, "Тип актива: " + assetType);
        y += 620;
        painter.drawText(marginX, y, "Дата вступу: " + entryDate);
        y += 620;
        painter.drawText(marginX, y, "Початкова вартість: " + initialCost);
        y += 620;
        painter.drawText(marginX, y, "Інвентарний номер: " + inventoryNumber);
        y += 620;
        painter.drawText(marginX, y, "Рахунок: " + account);
        y += 620;
        painter.drawText(marginX, y, "Одиниця міри: " + unit);
        y += 620;

    } else {
        QMessageBox::warning(this, "Попердження", "Актив с ID " + assetID + " не знайден.");
        return;
    }

    // Заголовок таблицы
    int tableHeaderY = y + 620;
    painter.drawText(marginX, tableHeaderY, "Додаткова информация об активе:");
    y += 640;

    // Заголовки столбцов таблицы
    painter.drawText(marginX, y +1000, "Дата");
    painter.drawText(marginX + 500+3000, y+1000, "Тип операції");
    painter.drawText(marginX + 750+5000, y+1000, "Опис");


    y += 620;
    painter.drawText(marginX, y+1000, "01.01.2023");
    painter.drawText(marginX + 500+3000, y+1000, "Покупка");
    painter.drawText(marginX + 750+5000, y+1000, "Купленний комп'ютер для відділу бухгалтерії");
    // Добавьте данные для других строк, если это необходимо
    // Добавьте данные для других строк, если это необходимо
    textWidth = painter.fontMetrics().horizontalAdvance("Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    painter.drawText(((writer.width() - textWidth) / 2)+3500, y+4000, "Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    y += 620;

    // Draw signature line (optional)
    textWidth = painter.fontMetrics().horizontalAdvance("Підпис: _____________________\n");
    painter.drawText(((writer.width() - textWidth) / 2)+3500, y+4000, "Підпис: _____________________\n");
    y += 620; // Move down for table data




    // Завершаем отчет
    painter.end();

    // Показываем сообщение об успешном сохранении отчета
    QMessageBox::information(this, "Успішно", "Інвентарна карточка актива збережена в файле: " + fileName);

}

void generateReport::generateCategoryReport()
{
    // Get filename for saving the report
    QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти звіт"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // User canceled saving
    }

    // Prepare the SQL query
    QSqlQuery query(db);
    QString selectedCategory = ui->comboBox_active_category->currentText();
    QString startDate = ui->dateEdit_from->date().toString("yyyy-MM-dd");
    QString endDate = ui->dateEdit_to->date().toString("yyyy-MM-dd");

    QString tableName;
    if (selectedCategory == "нематеріальні активи" || selectedCategory == "інші нематеріальні активи") {
        tableName = "intangible_assets";
    } else if (selectedCategory == "основні засоби") {
        tableName = "tangible_assets";
    } else {
        QMessageBox::critical(this, "Error", "Invalid asset category selected.");
        return;
    }

    QString queryStr = "SELECT * FROM " + tableName + " WHERE entry_date BETWEEN ? AND ?";
    query.prepare(queryStr);
    query.addBindValue(startDate);
    query.addBindValue(endDate);

    // Check for query execution error
    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося виконати запит: " + query.lastError().text());
        return;
    }

    // Create PDF writer
    QPdfWriter writer(fileName);

    // Set page size based on Qt version (adjust as needed)
    writer.setPageSize(QPageSize(QPageSize::A4)); // Use setPageSize for Qt 5.6+

    // Create painter object for drawing on the PDF
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // Define margins for better readability
    const int marginX = 50;
    const int marginY = 50;
    int y = marginY; // Starting position with margin

    // Draw report header with dynamic centering
    int textWidth = painter.fontMetrics().horizontalAdvance("Звіт по категорії активів\n");
    painter.drawText((writer.width() - textWidth) / 2, y, "Звіт по категорії активів\n");
    y += 20;


    // Draw table header
    QStringList headers = {"Назва активу", "Код активу", "Тип актива", "Рахунок", "Початкова вартість", "Інвентарний номер", "Шифр", "Одиниця виміру", "Дата вводу", "Тип активності"};
    QVector<int> columnWidths = {300, 150, 200, 150, 150, 150, 150, 150, 150, 150};
    int tableX = marginX;
    int tableY = y;
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(tableX, tableY, headers[i]);
        tableX += columnWidths[i];
    }
    tableY += 20;

    // Loop through query results and draw asset information
    while (query.next()) {
        tableX = marginX;
        for (int i = 0; i < headers.size(); ++i) {
            QString data = query.value(i).toString();
            painter.drawText(tableX, tableY, data);
            tableX += columnWidths[i];
        }
        tableY += 20;
    }

    // Add footer with date and signature
    textWidth = painter.fontMetrics().horizontalAdvance("Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    painter.drawText(((writer.width() - textWidth) / 2) + 3500, tableY + 4000, "Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n");
    tableY += 20;
    textWidth = painter.fontMetrics().horizontalAdvance("Підпис: _____________________\n");
    painter.drawText(((writer.width() - textWidth) / 2) + 3500, tableY + 4000, "Підпис: _____________________\n");

    // Finalize the report
    painter.end();

    // Show success message after saving the report
    QMessageBox::information(this, "Успішно", "Звіт по категорії активів збережено у файлі " + fileName);
}

void generateReport::generateDepreciationReport()
{


            QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти звіт"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // Пользователь отменил сохранение
    }

    // Подготавливаем SQL-запрос для получения информации об амортизации
    QSqlQuery query(db);
    QString selectedCode = ui->comboBox_active_code->currentText();
    QString selectedCategory = ui->comboBox_active_type->currentText();
    QString depreciationMethod = ui->comboBox_depreciation_method->currentText();
    QString startDate = ui->dateEdit_from->date().toString("yyyy-MM-dd");
    QString endDate = ui->dateEdit_to->date().toString("yyyy-MM-dd");

    QString queryStr;
    if (selectedCategory == "нематеріальні активи" || selectedCategory == "інші нематеріальні активи") {
        queryStr = "SELECT * FROM intangible_assets WHERE code = ? AND account = ? AND entry_date BETWEEN ? AND ?";
    } else if (selectedCategory == "основні засоби") {
        queryStr = "SELECT * FROM tangible_assets WHERE code = ? AND account = ? AND entry_date BETWEEN ? AND ?";
    } else {
        QMessageBox::critical(this, "Error", "Invalid asset category selected.");
        return;
    }

    query.prepare(queryStr);
    query.addBindValue(selectedCode);
    query.addBindValue(selectedCategory);
    query.addBindValue(startDate);
    query.addBindValue(endDate);

    // Проверяем ошибки выполнения запроса
    if (!query.exec()) {
        QMessageBox::critical(this, "Помилка", "Не вдалося виконати запит: " + query.lastError().text());
        return;
    }

    // Создаем объект для записи PDF
    QPdfWriter writer(fileName);

    // Устанавливаем размер страницы
    writer.setPageSize(QPageSize(QPageSize::A4));

    // Создаем объект рисования на PDF
    QPainter painter(&writer);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // Определяем отступы
    const int marginX = 1050;
    const int marginY = 1050;
    int y = marginY;

    // Рисуем заголовок отчета
    int textWidth = painter.fontMetrics().horizontalAdvance("Звіт про амортизацію\n");
    painter.drawText((writer.width() - textWidth) / 2, y, "Звіт про амортизацію\n");
    y += 820;

    // Рисуем заголовок таблицы
    QStringList headers = {"Назва", "Код", "Тип активу", "Дата вступу", "Початкова вартість", "Остаточна вартість", "Строк служби", "Метод амортизації", "Величина амортизації"};
    QVector<int> columnWidths = {500, 500, 500, 500, 500, 800, 900, 600, 800};
    int tableX = marginX;
    int tableY = y;
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(tableX, tableY, headers[i]);
        tableX += columnWidths[i];
    }
    tableY += 720;

    // Цикл по результатам запроса и рисование информации об амортизации
    while (query.next()) {
        QString assetName = query.value("name").toString();
        QString assetCode = query.value("code").toString();
        QString assetType = query.value("asset_type").toString();
        QString entryDate = query.value("entry_date").toDate().toString("dd.MM.yyyy");
        QString initialCost = query.value("initial_cost").toString();
        QString salvageValue = query.value("salvage_value").toString();
        QString usefulLife = query.value("useful_life").toString();
        QString depreciationMethod = ui->comboBox_depreciation_method->currentText();

        // Рассчитываем сумму амортизации в зависимости от выбранного метода
        double depreciationAmount = calculateDepreciation(query.value("id").toInt(), selectedCategory, depreciationMethod);

        // Рисуем информацию об активе и амортизации
        tableX = marginX;
        painter.drawText(tableX, tableY, assetName);
        tableX += columnWidths[0];
        painter.drawText(tableX, tableY, assetCode);
        tableX += columnWidths[1];
        painter.drawText(tableX, tableY, assetType);
        tableX += columnWidths[2];
        painter.drawText(tableX, tableY, entryDate);
        tableX += columnWidths[3];
        painter.drawText(tableX, tableY, initialCost);
        tableX += columnWidths[4];
        painter.drawText(tableX, tableY, salvageValue);
        tableX += columnWidths[5];
        painter.drawText(tableX, tableY, usefulLife);
        tableX += columnWidths[6];
        painter.drawText(tableX, tableY, depreciationMethod);
        tableX += columnWidths[7];
        painter.drawText(tableX, tableY, QString::number(depreciationAmount));
        tableY += 720;
    }

    // Завершаем рисование
    painter.end();

    // Сообщаем пользователю, что отчет сгенерирован
    QMessageBox::information(this, "Успішно", "Звіт про амортизацію збережено: " + fileName);

}


double generateReport::calculateDepreciation(int assetId, const QString& category, const QString& depreciationMethod)
{
    // Инициализация суммы амортизации
    double depreciationAmount = 0.0;

    // Определение расчета амортизации на основе выбранного метода
    if (depreciationMethod == "Прямолінійний метод") {
        // Расчет амортизации с использованием прямолинейного метода
        QSqlQuery straightLineQuery(db);
        QString queryStr;
        if (category == "нематеріальні активи" || category == "інші нематеріальні активи") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM intangible_assets WHERE id = ?";
        } else if (category == "основні засоби") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM tangible_assets WHERE id = ?";
        } else {
            QMessageBox::critical(this, "Error", "Invalid asset category selected.");
            return 0.0;
        }

        straightLineQuery.prepare(queryStr);
        straightLineQuery.addBindValue(assetId);
        if (!straightLineQuery.exec()) {
            QMessageBox::critical(this, "Error", "Failed to execute query: " + straightLineQuery.lastError().text());
            return 0.0;
        }

        if (straightLineQuery.next()) {
            double initialCost = straightLineQuery.value("initial_cost").toDouble();
            double salvageValue = straightLineQuery.value("salvage_value").toDouble();
            int usefulLife = straightLineQuery.value("useful_life").toInt();

            depreciationAmount = (initialCost - salvageValue) / usefulLife;
        }
    } else if (depreciationMethod == "Виробничий метод") {
        // Расчет амортизации с использованием виробничого метода
        QSqlQuery unitsOfProductionQuery(db);
        QString queryStr;

        if (category == "нематеріальні активи" || category == "інші нематеріальні активи") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM intangible_assets WHERE id = ?";
        } else if (category == "основні засоби") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM tangible_assets WHERE id = ?";
        } else {
            QMessageBox::critical(this, "Error", "Invalid asset category selected.");
            return 0.0;
        }

        unitsOfProductionQuery.prepare(queryStr);
        unitsOfProductionQuery.addBindValue(assetId);
        if (!unitsOfProductionQuery.exec()) {
            QMessageBox::critical(this, "Error", "Failed to execute query: " + unitsOfProductionQuery.lastError().text());
            return 0.0;
        }

        if (unitsOfProductionQuery.next()) {
            double initialCost = unitsOfProductionQuery.value("initial_cost").toDouble();
            double salvageValue = unitsOfProductionQuery.value("salvage_value").toDouble();
            int usefulLife = unitsOfProductionQuery.value("useful_life").toInt();

            // Предположим, что амортизация рассчитывается на основе времени использования актива
            // и что стоимость актива уменьшается пропорционально с увеличением времени
            if (usefulLife > 0) {
                depreciationAmount = (initialCost - salvageValue) / usefulLife;
            } else {
                depreciationAmount = 0.0;
            }
        }
    } else if (depreciationMethod == "Зменшений залишок") {
        // Расчет амортизации с использованием метода зменшеного залишку
        QSqlQuery diminishingBalanceQuery(db);
        QString queryStr;

        if (category == "нематеріальні активи" || category == "інші нематеріальні активи") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM intangible_assets WHERE id = ?";
        } else if (category == "основні засоби") {
            queryStr = "SELECT initial_cost, salvage_value, useful_life FROM tangible_assets WHERE id = ?";
        } else {
            QMessageBox::critical(this, "Error", "Invalid asset category selected.");
            return 0.0;
        }

        diminishingBalanceQuery.prepare(queryStr);
        diminishingBalanceQuery.addBindValue(assetId);
        if (!diminishingBalanceQuery.exec()) {
            QMessageBox::critical(this, "Error", "Failed to execute query: " + diminishingBalanceQuery.lastError().text());
            return 0.0;
        }

        if (diminishingBalanceQuery.next()) {
            double initialCost = diminishingBalanceQuery.value("initial_cost").toDouble();
            double salvageValue = diminishingBalanceQuery.value("salvage_value").toDouble();
            int usefulLife = diminishingBalanceQuery.value("useful_life").toInt();

            // Рассчитываем амортизацию на основе метода зменшеного залишку
            double remainingValue = initialCost;
            for (int i = 0; i < usefulLife; ++i) {
                // Уменьшаем остаточную стоимость актива каждый год
                remainingValue -= (initialCost - salvageValue) / usefulLife;
            }
            // Амортизация - это разница между начальной стоимостью и оставшейся стоимостью
            depreciationAmount = initialCost - remainingValue;
        }
    } else {
        QMessageBox::critical(this, "Error", "Invalid depreciation method selected.");
        return 0.0;
    }

    return depreciationAmount;
}


