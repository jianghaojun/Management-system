#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "account_list.h"
#include <QMessageBox>

login_Dialog::login_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_Dialog)
{
    ui->setupUi(this);
}

login_Dialog::~login_Dialog()
{
    delete ui;
}

void login_Dialog::on_loginpushButton_clicked()    //登录按钮
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
        QMessageBox::information(this, tr("登录失败"), tr("请输入手机号或密码后再登录"), QMessageBox::Ok);
        ui->pwdlineEdit->setFocus();
        ui->pnlineEdit->setFocus();
    }
    else
    {
        QString pn = ui->pnlineEdit->text();
        QString pwd = ui->pwdlineEdit->text();
        if(ui->comboBox->currentText() == s1)        //顾客
        {
            if(search_account(Customer, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit cs_widgetshow();
                emit send_customer_pn(pn);   //向顾客界面传送顾客的手机号
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }
        else if(ui->comboBox->currentText() == s2)   //服务员
        {
            if(search_account(Employee, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit cs_widgetshow();
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s3)   //厨师
        {
            if(search_account(Employee, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit cs_widgetshow();
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s4)    //经理
        {
            if(search_account(Employee, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit cs_widgetshow();
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s5)    //系统管理员
        {
            if(search_account(Employee, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit administrator_widgetshow();
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }
    }
}


void login_Dialog::on_registerpushButton_clicked()    //注册按钮
{
    this->hide();
    emit register_dialogshow();
}



void login_Dialog::on_quitpushButton_clicked()   //退出按钮 数据回传到数据库
{
    /*
    QSqlDatabase db = QSqlDatabase::database("DB");
    db.setDatabaseName("database.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open the database!",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }

    QSqlQuery query(db);
    query.exec("delete from menu_total");
    */

    extern QHash <QString, QString> Customer;
    extern QHash <QString, QString> Employee;
    Customer_Upload(Customer);                 //数据回传函数
    Employee_Upload(Employee);
    this->close();
}

void login_Dialog::dialogshow()                //登录界面自己显示
{
    this->show();
}
