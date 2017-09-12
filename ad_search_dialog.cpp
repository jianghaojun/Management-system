#include "ad_search_dialog.h"
#include "ui_ad_search_dialog.h"
#include "account_list.h"

ad_search_Dialog::ad_search_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_search_Dialog)
{
    ui->setupUi(this);
}

ad_search_Dialog::~ad_search_Dialog()
{
    delete ui;
}

void ad_search_Dialog::dialogshow()
{
    this->show();
}

void ad_search_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_search_Dialog::searchpart(QHash<QString, QString> hash, QString pn)
{
    if(search_account(hash, pn))
    {
        QString pwd = search_account_pwd(hash, pn);
        ui->result_label->setText("用户存在");
        ui->pwd_label->setText(pwd);
    }
    else
    {
        ui->result_label->clear();
        ui->pwd_label->clear();
        QMessageBox::information(this, tr("查询失败"), tr("用户不存在"), QMessageBox::Ok);
        ui->pnlineEdit->setFocus();
    }
}

void ad_search_Dialog::on_search_pushButton_clicked()
{
    QString s1 = "顾客";
    QString s2 = "服务员";
    QString s3 = "厨师";
    QString s4 = "经理";
    QString s5 = "系统管理员";
    extern QHash <QString, QString> Customer;
    extern QHash <QString, QString> Employee;
    if(ui->pnlineEdit->text().isEmpty())
       {
           QMessageBox::information(this, tr("查询失败"), tr("请输入手机号再查询"), QMessageBox::Ok);
           ui->pnlineEdit->setFocus();
       }
    else
      {
        QString pn = ui->pnlineEdit->text();
           if(ui->comboBox->currentText() == s1)        //顾客
           {
               searchpart(Customer, pn);
           }

           else if(ui->comboBox->currentText() == s2)        //服务员
           {
              searchpart(Employee, pn);
           }

           else if(ui->comboBox->currentText() == s3)        //厨师
           {
               searchpart(Employee, pn);
           }

           else if(ui->comboBox->currentText() == s4)        //经理
           {
               searchpart(Employee, pn);    
           }

           else if(ui->comboBox->currentText() == s5)        //系统管理员
           {
               searchpart(Employee, pn);             
           }
       }
}
