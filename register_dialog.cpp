#include "register_dialog.h"
#include "ui_register_dialog.h"
#include <QMessageBox>

register_Dialog::register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_Dialog)
{
    ui->setupUi(this);
    //样式表
    ui->repushButton->setStyleSheet("QPushButton{"
                                       "border:2px groove white;"
                                       "border-radius:15px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;}");

    ui->pnlineEdit->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "color:rgb(160,160,160);");

    ui->pwdlineEdit->setStyleSheet("border:2px groove gray;"
                                   "border-radius:15px;"
                                   "padding:2px 4px;"
                                   "color:rgb(160,160,160);");

    ui->backpushButton->setStyleSheet("QPushButton{"
                                          "border-style:hidden;"
                                          "color:rgb(0,147,221);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(0,170,255);"
                                          "border-style:inset;}");
}

register_Dialog::~register_Dialog()
{
    delete ui;
}

void register_Dialog::dialogshow()
{
    this->show();
}

void register_Dialog::registerpart(QHash<QString, QString> &hash, QString pn, QString pwd)
{
    if(search_account(hash, pn))
    {
        QMessageBox::warning(this, tr("注册失败"), tr("用户已存在！"), QMessageBox::Ok);
    }
    else
    {
        hash.insert(pn, pwd);
        //showCaccount(hash);
        QMessageBox::information(this, tr("注册成功"), tr("注册成功！"), QMessageBox::Ok);
        this->hide();
        emit login_dialogshow();
    }
}

void register_Dialog::on_repushButton_clicked()    //注册按钮
{
    //QString s1 = "顾客";
    //QString s2 = "服务员";
    //QString s3 = "厨师";
    //QString s4 = "经理";
    //QString s5 = "系统管理员";
    //extern QHash <QString, QString> Employee;

    extern QHash <QString, QString> Customer;

    if(ui->pnlineEdit->text().isEmpty() || ui->pwdlineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("注册失败"), tr("请输入手机号或密码后再注册"), QMessageBox::Ok);
        ui->pwdlineEdit->setFocus();
        ui->pnlineEdit->setFocus();
    }
    else
    {
        QString pn = ui->pnlineEdit->text();
        QString pwd = ui->pwdlineEdit->text();

        registerpart(Customer, pn, pwd);

        //账号信息上传数据库
        Customer_Upload(Customer);

        /*
        if(ui->comboBox->currentText() == s1)
        {
            registerpart(Customer, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s2)
        {
            registerpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s3)
        {
            registerpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s4)
        {
            registerpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s5)
        {
            registerpart(Employee, pn, pwd);
        }

        Employee_Upload(Employee);
        */
    }
}

void register_Dialog::on_backpushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

