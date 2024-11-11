#ifndef DBCREATE_H
#define DBCREATE_H

#include <tablepage.h>
#include <QDialog>

namespace Ui {
class dbcreate;
}

class dbcreate : public QDialog
{
    Q_OBJECT

public:
    explicit dbcreate(QWidget *parent = nullptr);
    ~dbcreate();
    QString getDatabaseName() const;


private slots:


    void on_buttonBox_accepted();

private:
    Ui::dbcreate *ui;

};

#endif // DBCREATE_H
