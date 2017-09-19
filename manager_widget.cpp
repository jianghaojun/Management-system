#include "manager_widget.h"
#include "ui_manager_widget.h"

manager_widget::manager_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager_widget)
{
    ui->setupUi(this);

    //设置时钟
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //设置tablewidget列宽自适应
    ui->waiter_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->chef_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tabWidget->setCurrentIndex(0);

    //样式表
    ui->waiter_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");
    ui->chef_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");

    ui->back_pushButton->setStyleSheet("QPushButton{"
                                       "border-style:hidden;"
                                        "background-color: rgba(44, 90, 255, 230);"
                                       "color:rgb(255, 255, 255);}"
                                       ""
                                       "QPushButton:pressed{"
                                       "background-color:rgb(0, 170, 255);"
                                       "border-style:inset;}");

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

}

manager_widget::~manager_widget()
{
    delete ui;
}

void manager_widget::clear_waiterwidget()
{
    int row = ui->waiter_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->waiter_tableWidget->takeItem(i, j);
            }
            ui->waiter_tableWidget->removeRow(i);
        }
    }
}

void manager_widget::clear_chefwidget()
{
    int row = ui->chef_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 4; ++j)
            {
                delete ui->chef_tableWidget->takeItem(i, j);
            }
            ui->chef_tableWidget->removeRow(i);
        }
    }
}

void manager_widget::closeEvent(QCloseEvent *event)
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

void manager_widget::widgetshow()
{
    this->show();
}

void manager_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

void manager_widget::on_query_pushButton_clicked()
{
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;
    int index = ui->tabWidget->currentIndex();
    switch (index)
    {
    case (0):
        clear_waiterwidget();
        for(int i = 0; i < Waiter_list.size(); ++ i)
        {
            int id = Waiter_list[i].get_Id();
            int count = Waiter_list[i].get_Count();
            double waiter_evaluate = Waiter_list[i].get_Evaluation();

            int row = ui->waiter_tableWidget->rowCount();
            ui->waiter_tableWidget->insertRow(row);
            ui->waiter_tableWidget->setRowHeight(row,30);

            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(id));
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->waiter_tableWidget->setItem(row, 0, item1);

            QTableWidgetItem *item2 = new QTableWidgetItem("服务总次数：" + QString::number(count));
            item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->waiter_tableWidget->setItem(row, 1, item2);

            QTableWidgetItem *item3 = new QTableWidgetItem("平均分：" + QString::number(waiter_evaluate));
            item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->waiter_tableWidget->setItem(row, 2, item3);

            QMultiHash <int, double>::iterator j = Waiter_list[i].service_record.begin();
            while(j != Waiter_list[i].service_record.end())
            {
                int table_id = j.key();
                double evaluate = j.value();

                int row = ui->waiter_tableWidget->rowCount();
                ui->waiter_tableWidget->insertRow(row);
                ui->waiter_tableWidget->setRowHeight(row,30);

                QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(table_id));
                item5->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->waiter_tableWidget->setItem(row, 1, item5);

                QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(evaluate));
                item6->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->waiter_tableWidget->setItem(row, 2, item6);

                ++j;
            }
        }
        break;
    case(1):
        clear_chefwidget();
        for(int i = 0; i < Chef_list.size(); ++ i)
        {
            int id = Chef_list[i].get_Id();
            int count = Chef_list[i].get_Count();
            double chef_evaluate = Chef_list[i].get_Evaluation();

            int row = ui->chef_tableWidget->rowCount();
            ui->chef_tableWidget->insertRow(row);
            ui->chef_tableWidget->setRowHeight(row,30);

            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(id));
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->chef_tableWidget->setItem(row, 0, item1);

            QTableWidgetItem *item2 = new QTableWidgetItem("制作总次数：" + QString::number(count));
            item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->chef_tableWidget->setItem(row, 1, item2);

            QTableWidgetItem *item3 = new QTableWidgetItem("平均分：" + QString::number(chef_evaluate));
            item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->chef_tableWidget->setItem(row, 2, item3);


            QMultiHash <int, double>::iterator j = Chef_list[i].cook_record.begin();
            while(j != Chef_list[i].cook_record.end())
            {
                int food_id = j.key();
                double evaluate = j.value();

                int row = ui->chef_tableWidget->rowCount();
                ui->chef_tableWidget->insertRow(row);
                ui->chef_tableWidget->setRowHeight(row,30);

                QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(food_id));
                item5->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->chef_tableWidget->setItem(row, 1, item5);

                QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(evaluate));
                item6->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                ui->chef_tableWidget->setItem(row, 2, item6);
                ++j;
            }
        }
        break;
    default:
        break;
    }
}

void manager_widget::showTime()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}

