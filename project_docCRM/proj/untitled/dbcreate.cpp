#include "dbcreate.h"
#include "ui_dbcreate.h"
#include "tablepage.h"
#include <QMessageBox>
dbcreate::dbcreate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dbcreate)
{
    ui->setupUi(this);

}

dbcreate::~dbcreate()
{
    delete ui;
}

QString dbcreate::getDatabaseName() const
{
    return ui->lineEdit->text();
}


void dbcreate::on_buttonBox_accepted()
{
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "The text field cannot be empty.");
        return;
    }
      accept(); // Закрыть диалоговое окно с принятием

}

