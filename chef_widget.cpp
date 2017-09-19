#include "chef_widget.h"
#include "ui_chef_widget.h"

chef_widget::chef_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chef_widget)
{
    ui->setupUi(this);

    //设置时钟
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //设置tablewidget列宽自适应
    ui->mymenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->csmenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->donemenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置tabwidget的显示
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);

    //样式表
    ui->mymenu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");
    ui->csmenu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");
    ui->donemenu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");

    ui->id_label->setStyleSheet("border:2px groove gray;"
                                  "border-radius:10px;"
                                  "padding:2px 4px;"
                                  "background-color:rgb(255,255,255);"
                                  "color:rgb(71,143,214);");

    ui->query_pushButton->setStyleSheet("QPushButton"
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

    ui->searchtable_pushButton->setStyleSheet("QPushButton"
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

    ui->clear_pushButton->setStyleSheet("QPushButton"
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

    ui->clear_pushButton_2->setStyleSheet("QPushButton"
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

    ui->back_pushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                        "background-color: rgba(44, 90, 255, 230);"
                                       "color:rgb(255, 255, 255);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0, 170, 255);"
                                       "border-style:inset;}");
}

chef_widget::~chef_widget()
{
    delete ui;
}

void chef_widget::clear_csmenu()
{
    int row = ui->csmenu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 2; ++j)
            {
                delete ui->csmenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->csmenu_tableWidget->removeRow(i);
        }
    }
}

void chef_widget::clear_mymenu()
{
    int row = ui->mymenu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->mymenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->mymenu_tableWidget->removeRow(i);
        }
    }
}

void chef_widget::clear_donemennu()
{
    int row = ui->donemenu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->donemenu_tableWidget->takeItem(i, j);   //删除用 new 申请的内存
            }
            ui->donemenu_tableWidget->removeRow(i);
        }
    }
}

void chef_widget::widgetshow()
{
    this->show();
}

void chef_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
    clear_csmenu();
    clear_mymenu();
    clear_donemennu();
}

void chef_widget::on_query_pushButton_clicked()
{
    if(ui->comboBox->currentText() == "请选择桌号")
    {
        QMessageBox::information(this, tr("查询失败"), tr("清先选择桌号！"), QMessageBox::Ok);
    }
    else
    {
        //清除表格的内容
        clear_csmenu();

        int table_number = ui->comboBox->currentText().toInt();
        extern QVector <Table> Table_list;
        int size = Table_list[table_number - 1].m.Menulist.size();
        if(size == 0)
        {
            QMessageBox::information(this, tr("查询结果"), tr("顾客尚未下单！"), QMessageBox::Ok);
        }
        else
        {
            for(int i = 0; i < size; ++i)
            {
                int row = ui->csmenu_tableWidget->rowCount();
                Food f1 = Table_list[table_number-1].m.Menulist.at(i);

                //下单的食物才能显示，未下单不显示
                if(f1.getFood_Status() == 1)
                {
                    QString name = f1.getName();

                    ui->csmenu_tableWidget->insertRow(row);
                    ui->csmenu_tableWidget->setRowHeight(row,30);

                    QTableWidgetItem *item0 = new QTableWidgetItem(name);
                    item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                    ui->csmenu_tableWidget->setItem(row, 0, item0);

                    QPushButton *claim_button = new QPushButton(tr("认领"));
                    ui->csmenu_tableWidget->setCellWidget(row, 1, claim_button);
                    //给按钮设置行属性，以便直接点击
                    claim_button->setProperty("row",row);
                    claim_button->setProperty("index", i);

                    connect(claim_button, SIGNAL(clicked()), this, SLOT(claim_button_clicked()));
                }
            }
        }
    }
}

void chef_widget::claim_button_clicked()
{
    //使tabwidget_2跳转到认领页面
    ui->tabWidget_2->setCurrentIndex(0);

    //下面两行是获取所点击按钮所在的行数（在构造按钮时先给按钮设置一个property（“index”，i））
    QPushButton *btn = (QPushButton *) sender();
    int index = btn->property("index").toInt();

    extern QVector <Table> Table_list;

    int table_number = ui->comboBox->currentText().toInt();
    int chef_id = ui->id_label->text().toInt();
    QString food_name = Table_list[table_number-1].m.Menulist[index].getName();

    //将菜品添加到厨师的认领菜单中
    int mymenu_row = ui->mymenu_tableWidget->rowCount();
    ui->mymenu_tableWidget->insertRow(mymenu_row);
    ui->mymenu_tableWidget->setRowHeight(mymenu_row,30);

    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(table_number));
    item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->mymenu_tableWidget->setItem(mymenu_row, 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(index + 1));
    item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->mymenu_tableWidget->setItem(mymenu_row, 1, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
    item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->mymenu_tableWidget->setItem(mymenu_row, 2, item2);

    QPushButton *finish_button = new QPushButton(tr("完成"));
    ui->mymenu_tableWidget->setCellWidget(mymenu_row, 3, finish_button);
    //finish_button->setProperty("index", index);
    finish_button->setProperty("row",mymenu_row);
    connect(finish_button, SIGNAL(clicked()), this, SLOT(finish_button_clicked()));

    //设置相应的食物状态为2，并设置食物的chef_id
    Table_list[table_number - 1].m.Menulist[index].setFood_Status(2);
    Table_list[table_number - 1].m.Menulist[index].setChef_id(chef_id);

    //将菜品的认领按钮从顾客菜单中清除
    int row = btn->property("row").toInt();
    delete ui->csmenu_tableWidget->takeItem(row, 1);   //删除用 new 申请的内存
    ui->csmenu_tableWidget->removeCellWidget(row, 1);
    QTableWidgetItem *item = new QTableWidgetItem("已认领");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->csmenu_tableWidget->setItem(row, 1, item);
}

void chef_widget::finish_button_clicked()
{

    //下面两行是获取所点击按钮所在的行数（在构造按钮时先给按钮设置一个property（“index”，index））
    QPushButton *btn = (QPushButton *) sender();
    //int index = btn->property("index").toInt();
    int row = btn->property("row").toInt();

    int table_number = ui->mymenu_tableWidget->item(row, 0)->text().toInt();
    int order_number = ui->mymenu_tableWidget->item(row, 1)->text().toInt();
    QString food_name = ui->mymenu_tableWidget->item(row, 2)->text();

    //设置相应的食物状态为3
    extern QVector <Table> Table_list;
    Table_list[table_number - 1].m.Menulist[order_number - 1].setFood_Status(3);

    //将菜品的完成按钮从厨师的认领菜单中清除
    delete ui->mymenu_tableWidget->takeItem(row, 3);   //删除用 new 申请的内存
    ui->mymenu_tableWidget->removeCellWidget(row, 3);
    QTableWidgetItem *item = new QTableWidgetItem("已完成");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->mymenu_tableWidget->setItem(row, 3, item);

    //添加到历史记录里面
    int donemenu_row = ui->donemenu_tableWidget->rowCount();
    ui->donemenu_tableWidget->insertRow(donemenu_row);
    ui->donemenu_tableWidget->setRowHeight(donemenu_row,30);

    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(table_number));
    item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->donemenu_tableWidget->setItem(donemenu_row, 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(order_number));
    item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->donemenu_tableWidget->setItem(donemenu_row, 1, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
    item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->donemenu_tableWidget->setItem(donemenu_row, 2, item2);
}

void chef_widget::on_searchtable_pushButton_clicked()
{
    //设置餐桌的图片以表示餐桌的状态，0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    extern QVector <Table> Table_list;
    for(int i = 0; i < 8; ++i)
    {
        int status = Table_list[i].getTableStatus();
        switch (i)
        {
        case (0):
            if(status == 0)
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (1):
            if(status == 0)
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (2):
            if(status == 0)
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (3):
            if(status == 0)
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (4):
            if(status == 0)
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (5):
            if(status == 0)
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (6):
            if(status == 0)
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        case (7):
            if(status == 0)
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            else
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/nowaiter_table.png"));
            }
            break;
        default:
            break;
        }
    }
}

void chef_widget::on_clear_pushButton_2_clicked()
{
    clear_donemennu();
}

void chef_widget::on_clear_pushButton_clicked()
{
    clear_mymenu();
}

void chef_widget::receive_chef_pn(QString pn)
{
    extern QVector<Chef> Chef_list;
    extern QVector<Table> Table_list;
    for(int i = 0; i < Chef_list.size(); ++i)
    {
        if(Chef_list[i].get_Employee_pn() == pn)
        {
            int chef_id = Chef_list[i].get_Id();
            ui->id_label->setText(QString::number(chef_id));

            //显示厨师认领菜单，遍历每张的桌子菜单的每个菜
            for(int i = 0; i < Table_list.size(); ++i)
            {
                if(Table_list[i].getTableStatus() != 0)     //餐桌的状态不为0 说明有客人在
                {
                    for(int j = 0; j < Table_list[i].m.Menulist.size(); ++j)    //遍历菜单里的每一道菜
                    {
                        //某道菜被该厨师认领，将其显示在认领菜单中
                        if(Table_list[i].m.Menulist[j].getChef_id() == chef_id)
                        {
                            QString food_name = Table_list[i].m.Menulist[j].getName();
                            int mymenu_row = ui->mymenu_tableWidget->rowCount();
                            ui->mymenu_tableWidget->insertRow(mymenu_row);
                            ui->mymenu_tableWidget->setRowHeight(mymenu_row,30);

                            QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(i + 1));
                            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                            ui->mymenu_tableWidget->setItem(mymenu_row, 0, item0);

                            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(j + 1));
                            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                            ui->mymenu_tableWidget->setItem(mymenu_row, 1, item1);

                            QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
                            item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                            ui->mymenu_tableWidget->setItem(mymenu_row, 2, item2);

                            //食物状态为2，被认领而未完成，在认领列表中设置完成按钮
                            if(Table_list[i].m.Menulist[j].getFood_Status() == 2)
                            {
                                QPushButton *finish_button = new QPushButton(tr("完成"));
                                ui->mymenu_tableWidget->setCellWidget(mymenu_row, 3, finish_button);
                                //finish_button->setProperty("index", index);
                                finish_button->setProperty("row",mymenu_row);
                                connect(finish_button, SIGNAL(clicked()), this, SLOT(finish_button_clicked()));
                            }
                            //食物状态为3，已完成，在认领列表中显示已完成，并添加到完成列表中，
                            else if(Table_list[i].m.Menulist[j].getFood_Status() == 3)
                            {
                                QTableWidgetItem *item = new QTableWidgetItem("已完成");
                                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                ui->mymenu_tableWidget->setItem(mymenu_row, 3, item);

                                int donemenu_row = ui->donemenu_tableWidget->rowCount();
                                ui->donemenu_tableWidget->insertRow(donemenu_row);
                                ui->donemenu_tableWidget->setRowHeight(donemenu_row,30);

                                QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(i + 1));
                                item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                ui->donemenu_tableWidget->setItem(donemenu_row, 0, item0);

                                QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(j + 1));
                                item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                ui->donemenu_tableWidget->setItem(donemenu_row, 1, item1);

                                QTableWidgetItem *item2 = new QTableWidgetItem(food_name);
                                item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                ui->donemenu_tableWidget->setItem(donemenu_row, 2, item2);

                                int fe = Table_list[i].m.Menulist[j].getF_Evaluation();
                                if(fe == 0)
                                {
                                    QTableWidgetItem *item3 = new QTableWidgetItem("未评价");
                                    item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                    ui->donemenu_tableWidget->setItem(donemenu_row, 3, item3);
                                }
                                else
                                {
                                    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(fe));
                                    item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                                    ui->donemenu_tableWidget->setItem(donemenu_row, 3, item3);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ui->searchtable_pushButton->click();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
}

void chef_widget::showTime()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}

void chef_widget::closeEvent(QCloseEvent *event)
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
