#include "waiter_widget.h"
#include "ui_waiter_widget.h"


waiter_widget::waiter_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waiter_widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //设置tablewidget列宽自适应
    ui->csmenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

waiter_widget::~waiter_widget()
{
    delete ui;
}

void waiter_widget::widgetshow()
{
    this->show();
}

void waiter_widget::on_searchtable_pushButton_clicked()
{
    //设置餐桌的图片以表示餐桌的状态，0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    extern QVector <Table> Table_list;
    for(int i = 0; i < 8; ++i)
    {
        int status = Table_list[i].getTableStatus();
        switch (i)
        {
        case (0):
            if(status == 1)
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (1):
            if(status == 1)
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (2):
            if(status == 1)
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (3):
            if(status == 1)
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (4):
            if(status == 1)
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (5):
            if(status == 1)
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (6):
            if(status == 1)
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        case (7):
            if(status == 1)
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/empty_table.png"));
            }
            else if(status == 2)
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/full_table.png"));
            }
            else
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/nocs_table.png"));
            }
            break;
        default:
            break;
        }
    }
}

void waiter_widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
}

void waiter_widget::on_A1_pushButton_clicked()
{
    serverbutton_part(0);
}

void waiter_widget::on_A2_pushButton_clicked()
{
    serverbutton_part(1);
}

void waiter_widget::on_A3_pushButton_clicked()
{
    serverbutton_part(2);
}

void waiter_widget::on_A4_pushButton_clicked()
{
    serverbutton_part(3);
}

void waiter_widget::on_A5_pushButton_clicked()
{
    serverbutton_part(4);
}

void waiter_widget::on_A6_pushButton_clicked()
{
    serverbutton_part(5);
}

void waiter_widget::on_A7_pushButton_clicked()
{
    serverbutton_part(6);
}

void waiter_widget::on_A8_pushButton_clicked()
{
    serverbutton_part(7);
}

void waiter_widget::serverbutton_part(int i)
{
    //0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
    extern QVector <Table> Table_list;
    extern QVector <Waiter> Waiter_list;
    int id = ui->id_lineEdit->text().toInt();
    if(ui->id_lineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("选择失败"), tr("请输入编号！"), QMessageBox::Ok);
    }
    else
    {
        int status = Table_list[i].getTableStatus();
        if(status == 0)
        {
            QMessageBox::information(this, tr("选择失败"), tr("本桌没有客人！"), QMessageBox::Ok);
        }
        else if(status == 1)
        {
            Table_list[i].setTableStatus(2);                        //设置餐桌的状态
            Table_list[i].setTableWaiter_id(id);                    //设置餐桌对应服务员的编号
            Waiter_list[id - 1].setWaiterTable(i + 1);              //设置服务员所服务的桌号
            ui->tablenumber_label->setText(QString::number(i + 1)); //设置标签显示服务的桌号
        }
        else
        {
            QMessageBox::information(this, tr("选择失败"), tr("本桌已有服务员！"), QMessageBox::Ok);
        }
    }
}

void waiter_widget::addwater_message()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->textEdit->append(txtTime);
    ui->textEdit->append("  顾客呼叫服务！");
}

void waiter_widget::foodhurry_message()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->textEdit->append(txtTime);
    ui->textEdit->append("  顾客催菜！");
}

void waiter_widget::showTime()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}

void waiter_widget::on_query_pushButton_clicked()
{
    if(ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("查询失败"), tr("请选择餐桌！"), QMessageBox::Ok);
    }
    else
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
        ui->csmenu_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("菜名") << tr("进度"));

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        //将table的menu显示出来
        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->csmenu_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);

            QString name = f1.getName();

            ui->csmenu_tableWidget->insertRow(row);
            ui->csmenu_tableWidget->setRowHeight(row,30);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->csmenu_tableWidget->setItem(row, 0, item0);

            //设置进度条
            QProgressBar *progress = new QProgressBar(ui->csmenu_tableWidget);
            progress->setTextVisible(false);
            ui->csmenu_tableWidget->setCellWidget(row, 1, progress);

            //0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->准备上菜
            if(f1.getFood_Status() == 0 || f1.getFood_Status() == 1)
            {
                progress->setValue(0);
            }
            else if(f1.getFood_Status() == 2)
            {
                progress->setValue(50);
            }
            else
            {
                progress->setValue(100);
            }
        }
    }
}
