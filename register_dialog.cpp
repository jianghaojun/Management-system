#include "register_dialog.h"
#include "ui_register_dialog.h"
#include <QMessageBox>

register_Dialog::register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_Dialog)
{
    ui->setupUi(this);
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
        showCaccount(hash);
        QMessageBox::information(this, tr("注册成功"), tr("注册成功！"), QMessageBox::Ok);
        this->hide();
        emit login_dialogshow();
    }
}

void register_Dialog::on_repushButton_clicked()    //注册按钮
{
    QString s1 = "顾客";
    QString s2 = "服务员";
    QString s3 = "厨师";
    QString s4 = "经理";
    QString s5 = "系统管理员";
    extern QHash <QString, QString> Customer;
    extern QHash <QString, QString> Employee;

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

        Customer_Upload(Customer);
        Employee_Upload(Employee);
    }
}

void register_Dialog::on_backpushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

