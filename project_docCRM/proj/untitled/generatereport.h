#ifndef GENERATEREPORT_H
#define GENERATEREPORT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class generateReport;
}

class generateReport : public QDialog
{
    Q_OBJECT

public:
    explicit generateReport(QString reportType,QSqlDatabase database,QWidget *parent = nullptr);
    ~generateReport();
private slots:
    void on_activeTypeChanged(const QString &type);
    void on_activeCodeChanged(const QString &code);

private:
    Ui::generateReport *ui;
    QSqlDatabase db;
    void populateActiveCodes(const QString &type);
    void populateActiveCategory(const QString &code, const QString &type);
    void setFieldsForAssetsReport();
    void setFieldsForDepreciationReport();
    void setFieldsForMoveReport();
    void setFieldsForInventoryReport();
    void setFieldsForCategoryReport();
    void populateDateRange(const QString &code, const QString &type);

    void generateAssetsReport();
    void generateMoveReport();
    void generateInventoryReport();
    void generateCategoryReport();
    void generateDepreciationReport();
    double calculateDepreciation( int assetID, const QString &selectedCategory, const QString &depreciationMethod);

};

#endif // GENERATEREPORT_H
