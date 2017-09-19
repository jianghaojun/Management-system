#ifndef AD_DELETE_DIALOG_H
#define AD_DELETE_DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "account_list.h"

namespace Ui {
class ad_delete_Dialog;
}

class ad_delete_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ad_delete_Dialog(QWidget *parent = 0);
    ~ad_delete_Dialog();

private:
    Ui::ad_delete_Dialog *ui;

private slots:
    void dialogshow();                 //自己界面显示

    void on_back_pushButton_clicked(); //返回按钮

    void on_delete_pushButton_clicked();  //删除账户按钮

    void deletepart(QHash <QString, QString> &hash, QString pn);   //删除按钮的部分代码，模块化

    void deletepart(QVector <Waiter> &vector, QString pn);

    void deletepart(QVector <Chef> &vector, QString pn);

signals:
    void administrator_widgetshow();      //系统管理员界面显示
};

#endif // AD_DELETE_DIALOG_H
