#include "ad_add_dialog.h"
#include "ui_ad_add_dialog.h"

ad_add_Dialog::ad_add_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_add_Dialog)
{
    ui->setupUi(this);
}

ad_add_Dialog::~ad_add_Dialog()
{
    delete ui;
}

void ad_add_Dialog::dialogshow()
{
    this->show();
}

void ad_add_Dialog::on_back_pushButton_clicked()
{
    this->hide();
    emit administrator_widgetshow();
}

void ad_add_Dialog::addpart(QHash<QString, QString> &hash, QString pn, QString pwd)
{
    if(search_account(hash, pn))
    {
        QMessageBox::information(this, tr("添加失败"), tr("用户已存在！"), QMessageBox::Ok);
    }
    else
    {
        hash.insert(pn, pwd);
        QMessageBox::information(this, tr("添加成功"), tr("添加成功！"), QMessageBox::Ok);
    }
}

void ad_add_Dialog::on_add_pushButton_clicked()
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
        QMessageBox::information(this, tr("添加失败"), tr("请输入手机号或密码后再添加"), QMessageBox::Ok);
        ui->pwdlineEdit->setFocus();
        ui->pnlineEdit->setFocus();
    }
    else
    {
        QString pn = ui->pnlineEdit->text();
        QString pwd = ui->pwdlineEdit->text();

        if(ui->comboBox->currentText() == s1)        //顾客
        {
            addpart(Customer, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s2)    //服务员
        {
            addpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s3)    //厨师
        {
            addpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s4)    //经理
        {
            addpart(Employee, pn, pwd);
        }

        else if(ui->comboBox->currentText() == s5)    //系统管理员
        {
            addpart(Employee, pn, pwd);

        }
    }
}
