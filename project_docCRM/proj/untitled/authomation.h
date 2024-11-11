#ifndef AUTHOMATION_H
#define AUTHOMATION_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class Authomation;
}

class Authomation : public QDialog
{
    Q_OBJECT

public:
    explicit Authomation(bool isIntangible,QSqlDatabase database,QWidget *parent = nullptr);
    ~Authomation();

private slots:

public slots:
    void addIntangibleAssetDepreciation();
    void addTangibleAssetDepreciation();
private:
    Ui::Authomation *ui;
    QSqlDatabase db;
};

#endif // AUTHOMATION_H
