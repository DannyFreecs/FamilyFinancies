#ifndef ACTIVITYRECEIPT_H
#define ACTIVITYRECEIPT_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <memory>

namespace Ui {
class ActivityReceipt;
}

class ActivityReceipt : public QMainWindow
{
    Q_OBJECT

public:
    explicit ActivityReceipt(QWidget *parent = nullptr);
    ~ActivityReceipt();

private:
    void initTableView();
    std::pair<bool, int> validateSave();

private slots:
    void on_pushButtonAddItem_clicked();
    void on_pushButtonRemoveItem_clicked();
    void on_pushButtonRemoveAll_clicked();
    void on_pushButtonSave_clicked();

private:
    Ui::ActivityReceipt *ui;
    std::unique_ptr<QStandardItemModel> _receiptModel;
    QMap<QString, QString> _categories;
};

#endif // ACTIVITYRECEIPT_H
