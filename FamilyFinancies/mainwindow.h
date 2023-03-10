#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//ATTRIBUTIONS: <a href="https://www.freepik.com/free-vector/home-budget-icons-set_4017023.htm">Image by macrovector</a> on Freepik
// <a href="https://www.flaticon.com/free-icons/budget" title="budget icons">Budget icons created by Freepik - Flaticon</a>
// <a href="https://www.flaticon.com/free-icons/budget" title="budget icons">Budget icons created by Flat Icons - Flaticon</a>
// <a href="https://www.freepik.com/free-photo/yellow-triangle-warning-sign-icon-isolated_3686557.htm#query=exclamation%20mark&position=4&from_view=search&track=ais">Image by rawpixel.com</a> on Freepik

#include <QMainWindow>
#include <memory>
#include "submenuexpenses.h"
#include "activityreceipt.h"
#include "activityshoppingitem.h"
#include "activityhouse.h"
#include "activitychild.h"
#include "activitymedical.h"
#include "activityother.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void releaseActivites();
    void releasesubMenus();
    void setMenuButtonsToDefaultStyle();
    void setMenuButtonsSelectedStyle(QPushButton *button);

private slots:
    void onCreateActivityReceipt();
    void onCreateActivityShoppingItem();
    void onCreateActivityHouse(const QString &house);
    void onCreateActivityChild(const QString &child);
    void onCreateActivityMedical();
    void onCreateActivityOther();
    void on_menuButtonExpenses_clicked();
    void on_actionAddReceipt_triggered();
    void on_actionAddItem_triggered();

private:
    Ui::MainWindow *ui;
    // Submenu windows
    std::unique_ptr<SubMenuExpenses> _subMenuExpenses;
    // Activity windows
    std::unique_ptr<ActivityReceipt> _activityReceipt;
    std::unique_ptr<ActivityShoppingItem> _activityShoppingItem;
    std::unique_ptr<ActivityHouse> _activityHouse;
    std::unique_ptr<ActivityChild> _activityChild;
    std::unique_ptr<ActivityMedical> _activityMedical;
    std::unique_ptr<ActivityOther> _activityOther;
};
#endif // MAINWINDOW_H
