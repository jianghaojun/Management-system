#ifndef AD_SEARCH_DIALOG_H
#define AD_SEARCH_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "account_list.h"

namespace Ui {
class ad_search_Dialog;
}

class ad_search_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_search_Dialog(QWidget *parent = 0);
    ~ad_search_Dialog();

private:
    Ui::ad_search_Dialog *ui;

    void searchpart(QHash <QString, QString> hash, QString pn);
private slots:
    void dialogshow();                      //自己显示

    void on_back_pushButton_clicked();      //返回按钮

    void on_search_pushButton_clicked();    //查询按钮


signals:
    void administrator_widgetshow();  //系统管理员的界面显示
};

#endif // AD_SEARCH_DIALOG_H
