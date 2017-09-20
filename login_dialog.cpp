#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "account_list.h"
#include <QMessageBox>
#include <QStyle>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QFile>

login_Dialog::login_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_Dialog)
{
    ui->setupUi(this);
    //样式表
    ui->loginpushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:15px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->pnlineEdit->setStyleSheet("border:2px groove gray;"
                                  "border-radius:15px;"
                                  "padding:2px 4px;"
                                  "color:rgb(160,160,160);");

    ui->pwdlineEdit->setStyleSheet("border:2px groove gray;"
                                   "border-radius:15px;"
                                   "padding:2px 4px;"
                                   "color:rgb(160,160,160);");

    ui->comboBox->setStyleSheet("QComboBox::drop-down"
                                "{"
                                "subcontrol-origin: padding;"
                                "subcontrol-position: top right;"
                                "width: 20px;"
                                "border-left-width: 1px;"
                                "border-left-color: darkgray;"
                                "border-left-style: solid; "
                                "border-top-right-radius: 15px;"
                                "border-bottom-right-radius: 15px;"
                                "}"
                                "QComboBox::down-arrow"
                                "{"
                                "image:url(:/image/images/arrow2.png);"
                                "}"
                                "QComboBox"
                                "{"
                                "border:2px groove gray;"
                                "border-radius:15px;"
                                "padding:2px 4px;"
                                "color:rgb(160,160,160);"
                                "}");


    ui->registerpushButton->setStyleSheet("QPushButton{"
                                          "border-style:hidden;"
                                          "color:rgb(0,147,221);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(0,170,255);"
                                          "border-style:inset;}");

    ui->quitpushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                       "color:rgb(0,147,221);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;}");

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
    extern QHash <QString, QString> Manager;
    extern QHash <QString, QString> System_manager;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    if(ui->pnlineEdit->text().isEmpty() || ui->pwdlineEdit->text().isEmpty() || ui->comboBox->currentText() == "身份"
            || ui->pnlineEdit->text() == "请输入手机号" || ui->pwdlineEdit->text() == "请输入密码:")
    {
        QMessageBox::information(this, tr("登录失败"), tr("请输入手机号或密码并选择身份后再登录!"), QMessageBox::Ok);
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
            if(search_account(Waiter_list, pn, pwd))
            {
                qDebug()<<"2";
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit waiter_widgetshow();
                emit send_waiter_pn(pn);   //向服务员界面传送服务员的手机号
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s3)   //厨师
        {
            if(search_account(Chef_list, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit chef_widgetshow();
                emit send_chef_pn(pn);    //向厨师界面传送厨师的手机号
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s4)    //经理
        {
            if(search_account(Manager, pn, pwd))
            {
                QMessageBox::information(this, tr("登录成功"), tr("登录成功！"), QMessageBox::Ok);
                this->hide();
                emit manager_widgetshow();
            }
            else
            {
                QMessageBox::warning(this, tr("登录失败"), tr("请输入正确的手机号或密码！"), QMessageBox::Ok);
            }
        }

        else if(ui->comboBox->currentText() == s5)    //系统管理员
        {
            if(search_account(System_manager, pn, pwd))
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
    extern QHash <QString, QString> Customer;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    extern QHash <QString, QString> Manager;
    extern QHash <QString, QString> System_manager;
    extern QMultiHash<QString, Food> Menu_total;

    Menu_upload(Menu_total);                    //数据回传函数
    Customer_Upload(Customer);
    Waiter_Upload(Waiter_list);
    Chef_Upload(Chef_list);
    Manager_Upload(Manager);
    System_manager_Upload(System_manager);
    this->close();
}

void login_Dialog::dialogshow()                //登录界面自己显示
{
    this->show();
}

void login_Dialog::closeEvent(QCloseEvent *event)
{
    switch(QMessageBox::information(this,tr("提示"),tr("你确定退出该程序?"),tr("确定"), tr("取消"),0,1))
    {
    case 0:
    {
        extern QHash <QString, QString> Customer;
        extern QVector <Waiter> Waiter_list;
        extern QVector <Chef> Chef_list;
        extern QHash <QString, QString> Manager;
        extern QHash <QString, QString> System_manager;
        extern QMultiHash<QString, Food> Menu_total;

        Menu_upload(Menu_total);                    //数据回传函数
        Customer_Upload(Customer);
        Waiter_Upload(Waiter_list);
        Chef_Upload(Chef_list);
        Manager_Upload(Manager);
        System_manager_Upload(System_manager);

        event->accept();
        break;
    }
    case 1:
    default:
        event->ignore();
        break;
    }
}
