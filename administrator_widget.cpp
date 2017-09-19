#include "administrator_widget.h"
#include "ui_administrator_widget.h"
#include "login_dialog.h"
#include "food.h"

Administrator_widget::Administrator_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator_widget)
{
    ui->setupUi(this);

    ui->Account_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Menu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //样式表
    ui->Account_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");
    ui->Menu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");

    ui->comboBox->setStyleSheet("QComboBox::drop-down"
                                "{"
                                "subcontrol-origin: padding;"
                                "subcontrol-position: top right;"
                                "width: 20px;"
                                "border-left-width: 1px;"
                                "border-left-color: darkgray;"
                                "border-left-style: solid; "
                                "border-top-right-radius: 10px;"
                                "border-bottom-right-radius: 10px;"
                                "}"
                                "QComboBox::down-arrow"
                                "{"
                                "image:url(:/image/images/arrow2.png);"
                                "}"
                                "QComboBox"
                                "{"
                                "border:2px groove gray;"
                                "border-radius:10px;"
                                "padding:2px 4px;"
                                "color:rgb(160,160,160);"
                                "}");

    ui->comboBox_2->setStyleSheet("QComboBox::drop-down"
                                "{"
                                "subcontrol-origin: padding;"
                                "subcontrol-position: top right;"
                                "width: 20px;"
                                "border-left-width: 1px;"
                                "border-left-color: darkgray;"
                                "border-left-style: solid; "
                                "border-top-right-radius: 10px;"
                                "border-bottom-right-radius: 10px;"
                                "}"
                                "QComboBox::down-arrow"
                                "{"
                                "image:url(:/image/images/arrow2.png);"
                                "}"
                                "QComboBox"
                                "{"
                                "border:2px groove gray;"
                                "border-radius:10px;"
                                "padding:2px 4px;"
                                "color:rgb(160,160,160);"
                                "}");

    ui->showmenu_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->searchfood_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->addfood_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->deletefood_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->uploadfood_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->search_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->showaccount_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->add_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->delete_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->upload_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:10px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->back_pushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                        "background-color: rgba(44, 90, 255, 230);"
                                       "color:rgb(255, 255, 255);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0, 170, 255);"
                                       "border-style:inset;}");
}

Administrator_widget::~Administrator_widget()
{
    delete ui;
}

void Administrator_widget::widgetshow()
{
    this->show();
}

void Administrator_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

//账户管理

void Administrator_widget::on_showaccount_pushButton_clicked()
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

    clear_accountwidget();
    if(ui->comboBox_2->currentText() == s1)
    {
        showaccount_part(Customer);
    }
    else if(ui->comboBox_2->currentText() == s2)
    {
        showaccount_part(Waiter_list);
    }
    else if(ui->comboBox_2->currentText() == s3)
    {
        showaccount_part(Chef_list);
    }
    else if(ui->comboBox_2->currentText() == s4)
    {
        showaccount_part(Manager);
    }
    else
    {
        showaccount_part(System_manager);
    }

}

void Administrator_widget::showaccount_part(QHash<QString, QString> hash)
{
    QHash<QString, QString>::const_iterator i = hash.constBegin();

    while(i != hash.constEnd())
    {
        int row = ui->Account_tableWidget->rowCount();
        QString type = ui->comboBox_2->currentText();
        QString pn = i.key();
        QString pwd = i.value();

        ui->Account_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(type);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(pn);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(pwd);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 2, item2);

        ++i;
    }
}

void Administrator_widget::showaccount_part(QVector<Waiter> vector)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        int row = ui->Account_tableWidget->rowCount();
        QString type = ui->comboBox_2->currentText();
        QString pn = vector[i].get_Employee_pn();
        QString pwd = vector[i].get_Employee_pwd();
        QString id = QString::number(vector[i].get_Id());

        ui->Account_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(type + ":" + id);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(pn);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(pwd);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 2, item2);
    }
}

void Administrator_widget::showaccount_part(QVector<Chef> vector)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        int row = ui->Account_tableWidget->rowCount();
        QString type = ui->comboBox_2->currentText();
        QString pn = vector[i].get_Employee_pn();
        QString pwd = vector[i].get_Employee_pwd();
        QString id = QString::number(vector[i].get_Id());

        ui->Account_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(type + ":" + id);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(pn);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(pwd);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Account_tableWidget->setItem(row, 2, item2);
    }
}

void Administrator_widget::clear_accountwidget()
{
    int row1 = ui->Account_tableWidget->rowCount();               //清空原先的表格
    if(row1 != 0)
    {
        for(int i = row1; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->Account_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->Account_tableWidget->removeRow(i);
        }
    }
}

void Administrator_widget::on_search_pushButton_clicked()
{
    emit ad_search_dialogshow();
}

void Administrator_widget::on_add_pushButton_clicked()
{
    emit ad_add_dialogshow();
}

void Administrator_widget::on_delete_pushButton_clicked()
{
    emit ad_delete_dialogshow();
}

void Administrator_widget::on_upload_pushButton_clicked()
{
    extern QHash <QString, QString> Customer;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    extern QHash <QString, QString> Manager;
    extern QHash <QString, QString> System_manager;

    Customer_Upload(Customer);                 //数据回传函数
    Waiter_Upload(Waiter_list);
    Chef_Upload(Chef_list);
    Manager_Upload(Manager);
    System_manager_Upload(System_manager);
    QMessageBox::information(this, tr("上传成功"), tr("上传成功！"), QMessageBox::Ok);
}

//菜单管理

void Administrator_widget::showmenu_part(QMultiHash<QString, Food> hash, QString food_type)
{
    QMultiHash <QString, Food>::iterator i = hash.find(food_type);
    while(i != hash.end() && i.key() == food_type)
    {
        Food f = i.value();
        int id = f.getID();
        QString Id = QString::number(id);       //将int类型转换成QString类型
        QString food_name = f.getName();
        int food_price = f.getPrice();
        QString Food_price = QString::number(food_price);

        int row = ui->Menu_tableWidget->rowCount();
        ui->Menu_tableWidget->insertRow(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(food_type);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(Id);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(Food_price);
        item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->Menu_tableWidget->setItem(row, 3, item3);

        ++i;
    }
}

void Administrator_widget::on_showmenu_pushButton_clicked()
{
    //设置菜单显示
    QString s1 = "Cold Dish";
    QString s2 = "Main Course";
    QString s3 = "Soup";

    int row1 = ui->Menu_tableWidget->rowCount();                //清空原先的表格
    if(row1 != 0)
    {
        for(int i = row1; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->Account_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->Menu_tableWidget->removeRow(i);
        }
    }

    extern QMultiHash <QString, Food> Menu_total;

    if(ui->comboBox->currentText() == s1)
    {
        showmenu_part(Menu_total, s1);
    }
    else if(ui->comboBox->currentText() == s2)
    {
        showmenu_part(Menu_total, s2);
    }
    else
    {
        showmenu_part(Menu_total, s3);
    }
}

void Administrator_widget::on_searchfood_pushButton_clicked()
{
    emit ad_searchmenu_dialogshow();
}

void Administrator_widget::on_addfood_pushButton_clicked()
{
    emit ad_addmenu_dialogshow();
}

void Administrator_widget::on_deletefood_pushButton_clicked()
{
    emit ad_deletemenu_dialogshow();
}

void Administrator_widget::on_uploadfood_pushButton_clicked()
{
    extern QMultiHash<QString, Food> Menu_total;
    Menu_upload(Menu_total);
    QMessageBox::information(this, tr("上传成功"), tr("上传成功！"), QMessageBox::Ok);
}

void Administrator_widget::closeEvent(QCloseEvent *event)
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
