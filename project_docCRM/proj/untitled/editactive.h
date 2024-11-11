#ifndef EDITACTIVE_H
#define EDITACTIVE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class editActive;
}

class editActive : public QDialog
{
    Q_OBJECT

public:
    explicit editActive(QSqlDatabase database, int assetId, bool tangibleStatus, QWidget *parent = nullptr);
    ~editActive();

private slots:
    void saveButton_clicked();
    void cancelButton_clicked();
    void deleteButton_clicked();
    void on_comboBox_code_currentIndexChanged(int index);

private:
    void loadAssetCodesForIntangible();
    void loadAssetDataForIntangible(int assetId);
    void saveAssetDataForIntangible();
    void deleteAssetForIntangible();

    void loadAssetCodesForTangible();
    void loadAssetDataForTangible(int assetId);
    void saveAssetDataForTangible();
    void deleteAssetForTangible();

    Ui::editActive *ui;
    QSqlDatabase db;
    int currentAssetId; // Переменная для хранения ID текущего актива
    bool tangibleStatus;
};

#endif // EDITACTIVE_H
