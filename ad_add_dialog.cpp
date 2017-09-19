#include "ad_add_dialog.h"
#include "ui_ad_add_dialog.h"

ad_add_Dialog::ad_add_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_add_Dialog)
{
    ui->setupUi(this);
    //样式表
    ui->add_pushButton->setStyleSheet("QPushButton{"
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

    ui->id_lineEdit->setStyleSheet("border:2px groove gray;"
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

    ui->back_pushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                       "color:rgb(0,147,221);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;}");

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
        ui->id_lineEdit->setText("服务员与厨师需要编号");
        ui->pnlineEdit->clear();
        ui->pwdlineEdit->clear();
    }
}

void ad_add_Dialog::addpart(QVector<Waiter> &vector, int id, QString pn, QString pwd)
{
    if(search_account(vector, pn, id))
    {
        QMessageBox::information(this, tr("添加失败"), tr("用户已存在！手机号或编号重复！"), QMessageBox::Ok);
    }
    else
    {
        Waiter w(id, pn, pwd);
        vector.push_back(w);
        QMessageBox::information(this, tr("添加成功"), tr("添加成功！"), QMessageBox::Ok);
        ui->id_lineEdit->setText("服务员与厨师需要编号");
        ui->pnlineEdit->clear();
        ui->pwdlineEdit->clear();
    }
}

void ad_add_Dialog::addpart(QVector<Chef> &vector, int id, QString pn, QString pwd)
{
    if(search_account(vector, pn, id))
    {
        QMessageBox::information(this, tr("添加失败"), tr("用户已存在！手机号或编号重复！"), QMessageBox::Ok);
    }
    else
    {
        Chef c(id, pn, pwd);
        vector.push_back(c);
        QMessageBox::information(this, tr("添加成功"), tr("添加成功！"), QMessageBox::Ok);
        ui->id_lineEdit->setText("服务员与厨师需要编号");
        ui->pnlineEdit->clear();
        ui->pwdlineEdit->clear();
    }
}

void ad_add_Dialog::on_add_pushButton_clicked()
{
    QString s1 = "顾客";
    QString s2 = "服务员";
    QString s3 = "厨师";
    QString s4 = "经理";
    extern QHash <QString, QString> Customer;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    extern QHash <QString, QString> Manager;
    extern QHash <QString, QString> System_manager;

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
        int id = ui->id_lineEdit->text().toInt();

        if(ui->comboBox->currentText() == s1)        //顾客
        {
            addpart(Customer, pn, pwd);
        }
        else if(ui->comboBox->currentText() == s2)    //服务员
        {
            if(ui->id_lineEdit->text() == "服务员和厨师需要编号")
            {
                QMessageBox::information(this, tr("添加失败"), tr("请输入编号"), QMessageBox::Ok);
            }
            else
            {
                addpart(Waiter_list, id, pn, pwd);
            }
        }
        else if(ui->comboBox->currentText() == s3)    //厨师
        {
            if(ui->id_lineEdit->text() == "服务员和厨师需要编号")
            {
                QMessageBox::information(this, tr("添加失败"), tr("请输入编号"), QMessageBox::Ok);
            }
            else
            {
                addpart(Chef_list, id, pn, pwd);
            }
        }
        else if(ui->comboBox->currentText() == s4)    //经理
        {
            addpart(Manager, pn, pwd);
        }
        else                                          //系统管理员
        {
            addpart(System_manager, pn, pwd);
        }
    }
}
