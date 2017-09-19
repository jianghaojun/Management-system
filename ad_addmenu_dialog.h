#ifndef AD_ADDMENU_DIALOG_H
#define AD_ADDMENU_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "food.h"
#include "menu_total.h"

namespace Ui {
class ad_addmenu_Dialog;
}

class ad_addmenu_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_addmenu_Dialog(QWidget *parent = 0);
    ~ad_addmenu_Dialog();

private:
    Ui::ad_addmenu_Dialog *ui;

    void addpart(QMultiHash <QString, Food> &hash, QString food_type, int id, QString food_name, int food_price);

private slots:
    void dialogshow();                      //自己显示

    void on_back_pushButton_clicked();      //返回按钮

    void on_add_pushButton_clicked();       //添加菜品按钮

signals:
    void administrator_widgetshow();  //系统管理员的界面显示
};

#endif // AD_ADDMENU_DIALOG_H
