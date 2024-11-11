#ifndef EDITAUTHOMATION_H
#define EDITAUTHOMATION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class editAuthomation;
}

class editAuthomation : public QDialog
{
    Q_OBJECT

public:
    explicit editAuthomation(QSqlDatabase database, int assetId, bool tangibleStatus, QWidget *parent = nullptr);
    ~editAuthomation();

private slots:
    void saveButton_clicked();
    void deleteButton_clicked();
    void cancelButton_clicked();
     void comboBox_code_currentIndexChanged(int index);
private:
    void loadDepreciationDataForIntangible(int assetId);
    void saveDepreciationDataForIntangible();
    void deleteDepreciationForIntangible();
    void loadDepreciationCodesForIntangible();

    void loadDepreciationDataForTangible(int assetId);
    void saveDepreciationDataForTangible();
    void deleteDepreciationForTangible();
    void loadDepreciationCodesForTangible();

    Ui::editAuthomation *ui;
    QSqlDatabase db;
    int currentAssetId;
    bool tangibleStatus;
};

#endif // EDITAUTHOMATION_H
