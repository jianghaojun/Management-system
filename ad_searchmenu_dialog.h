#ifndef AD_SEARCHMENU_DIALOG_H
#define AD_SEARCHMENU_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "food.h"
#include "menu_total.h"

namespace Ui {
class ad_searchmenu_Dialog;
}

class ad_searchmenu_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_searchmenu_Dialog(QWidget *parent = 0);
    ~ad_searchmenu_Dialog();

private:
    Ui::ad_searchmenu_Dialog *ui;

    void searchpart(QMultiHash <QString, Food> hash, QString food_type, int id);   //查找菜品的部分代码，模块化

private slots:
    void dialogshow();                      //自己显示

    void on_back_pushButton_clicked();      //返回按钮

    void on_search_pushButton_clicked();    //查找按钮

signals:
    void administrator_widgetshow();  //系统管理员的界面显示
};

#endif // AD_SEARCHMENU_DIALOG_H
