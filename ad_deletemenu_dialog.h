#ifndef AD_DELETEMENU_DIALOG_H
#define AD_DELETEMENU_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "food.h"
#include "menu_total.h"

namespace Ui {
class ad_deletemenu_Dialog;
}

class ad_deletemenu_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_deletemenu_Dialog(QWidget *parent = 0);
    ~ad_deletemenu_Dialog();

private:
    Ui::ad_deletemenu_Dialog *ui;

    void deletepart(QMultiHash <QString, Food> &hash, QString food_type, int id, QString food_name, int food_price);

private slots:
    void dialogshow();                      //自己显示

    void on_back_pushButton_clicked();      //返回按钮

    void on_delete_pushButton_clicked();    //删除菜品按钮

signals:
    void administrator_widgetshow();  //系统管理员的界面显示
};

#endif // AD_DELETEMENU_DIALOG_H
