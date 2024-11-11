#ifndef NONEMATERIALACTIVES_H
#define NONEMATERIALACTIVES_H

#include "authomation.h"
#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class NoneMaterialActives;
}

class NoneMaterialActives : public QDialog
{
    Q_OBJECT

public:
    explicit NoneMaterialActives(const bool isNMA, QSqlDatabase database,QWidget *parent = nullptr);
    ~NoneMaterialActives();

private slots:


    void buttonBox_accepted_for_InTangibleAsset();
    void buttonBox_accepted_for_TangibleAsset();
    void on_pushButton_clicked();

public slots:

    void TangibleAssetDepreciation();
    void IntangibleAssetDepreciation();
private:
    Ui::NoneMaterialActives *ui;
    Authomation *authomation;
    QSqlDatabase db;

};

#endif // NONEMATERIALACTIVES_H
