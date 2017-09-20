#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    //设置tablewidget列宽自适应
    ui->mymenu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->menu_tableWidget->verticalHeader()->setVisible(false);
    ui->menu_tableWidget->setShowGrid(false);
    ui->menu_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->evaluate_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //样式表
    ui->mymenu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");
    ui->menu_tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,170,255);}");

    ui->pn_label->setStyleSheet("border:2px groove gray;"
                                  "border-radius:10px;"
                                  "padding:2px 4px;"
                                  "background-color:rgb(255,255,255);"
                                  "color:rgb(71,143,214);");
    ui->tablenumber_label->setStyleSheet("border:2px groove gray;"
                                  "border-radius:10px;"
                                  "padding:2px 4px;"
                                  "background-color:rgb(255,255,255);"
                                  "color:rgb(71,143,214);");
    ui->fee_label->setStyleSheet("border:2px groove gray;"
                                  "border-radius:10px;"
                                  "padding:2px 4px;"
                                  "background-color:rgb(255,255,255);"
                                  "color:rgb(71,143,214);");

    ui->A1_pushButton->setStyleSheet("QPushButton"
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
    ui->A2_pushButton->setStyleSheet("QPushButton"
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
    ui->A3_pushButton->setStyleSheet("QPushButton"
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
    ui->A4_pushButton->setStyleSheet("QPushButton"
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
    ui->A5_pushButton->setStyleSheet("QPushButton"
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
    ui->A6_pushButton->setStyleSheet("QPushButton"
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
    ui->A7_pushButton->setStyleSheet("QPushButton"
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
    ui->A8_pushButton->setStyleSheet("QPushButton"
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


    ui->back_pushButton->setStyleSheet("QPushButton{"
                                          "border-style:hidden;"
                                          "background-color: rgba(44, 90, 255, 230);"
                                          "color: rgb(255, 255, 255);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(0, 170, 255);"
                                          "border-style:inset;}");

    ui->querytable_pushButton->setStyleSheet("QPushButton{"
                                          "border:2px groove;"
                                          "border-radius:5px;"
                                          "padding:2px 4px;"
                                          "background-color: rgba(57, 57, 57);"
                                          "color: rgb(255, 255, 255);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(255,255,255);"
                                          "border-style:inset;}");

    ui->query_pushButton->setStyleSheet("QPushButton{"
                                          "border:2px groove;"
                                          "border-radius:5px;"
                                          "padding:2px 4px;"
                                          "background-color: rgba(57, 57, 57);"
                                          "color: rgb(255, 255, 255);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(255,255,255);"
                                          "border-style:inset;}");

    ui->water_pushButton->setStyleSheet("QPushButton{"
                                          "border:2px groove;"
                                          "border-radius:5px;"
                                          "padding:2px 4px;"
                                          "background-color: rgba(57, 57, 57);"
                                          "color: rgb(255, 255, 255);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(255,255,255);"
                                          "border-style:inset;}");

    ui->hurry_pushButton->setStyleSheet("QPushButton{"
                                          "border:2px groove;"
                                          "border-radius:5px;"
                                          "padding:2px 4px;"
                                          "background-color: rgba(57, 57, 57);"
                                          "color: rgb(255, 255, 255);}"
                                          ""
                                          "QPushButton:pressed{"
                                          "background-color:rgb(255,255,255);"
                                          "border-style:inset;}");

    ui->order_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:11px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->pay_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:11px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(0,147,221);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");

    ui->submit_pushButton->setStyleSheet("QPushButton"
                                       "{"
                                       "border:2px groove white;"
                                       "border-radius:11px;"
                                       "padding:2px 4px;"
                                       "color:rgb(255,255,255);"
                                       "background-color:rgb(255,65,8);"
                                       "}"
                                       "QPushButton:pressed"
                                       "{"
                                       "background-color:rgb(0,170,255);"
                                       "border-style:inset;"
                                       "}");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::widgetshow()
{
    this->show();
}

void Widget::on_querytable_pushButton_clicked()
{
    extern QVector <Table> Table_list;
    for(int i = 0; i < Table_list.size(); ++i)
    {
        int status = Table_list[i].getTableStatus();
        switch (i)
        {
        case (0):
            if(status == 0)
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A1_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (1):
            if(status == 0)
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A2_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (2):
            if(status == 0)
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A3_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (3):
            if(status == 0)
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A4_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (4):
            if(status == 0)
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A5_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (5):
            if(status == 0)
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A6_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (6):
            if(status == 0)
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A7_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        case (7):
            if(status == 0)
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/empty1_table.png"));
            }
            else
            {
                ui->A8_label->setPixmap(QPixmap(":/image/images/full1_table.png"));
            }
            break;
        default:
            break;
        }
    }
}

void Widget::on_A1_pushButton_clicked()
{
    seatbutton_part(0);
}

void Widget::on_A2_pushButton_clicked()
{
    seatbutton_part(1);
}

void Widget::on_A3_pushButton_clicked()
{
    seatbutton_part(2);
}

void Widget::on_A4_pushButton_clicked()
{
    seatbutton_part(3);
}

void Widget::on_A5_pushButton_clicked()
{
    seatbutton_part(4);
}

void Widget::on_A6_pushButton_clicked()
{
    seatbutton_part(5);
}

void Widget::on_A7_pushButton_clicked()
{
    seatbutton_part(6);
}

void Widget::on_A8_pushButton_clicked()
{
    seatbutton_part(7);
}

void Widget::seatbutton_part(int i)
{
    if(!ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("上座失败"), tr("您已经选择了座位！"), QMessageBox::Ok);
    }
    else
    {
        extern QVector <Table> Table_list;
        if(Table_list[i].getTableStatus() == 0)
        {
            QMessageBox::information(this, tr("上座成功"), tr("请就坐！"), QMessageBox::Ok);
            ui->tablenumber_label->setText("0" + QString::number(i + 1));
            ui->tablenumber_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Table_list[i].setTableStatus(1);  // 0表示空闲，1表示有客人但没有服务员，2表示既有客人也有服务员
            Table_list[i].setTableCustomer_pn(ui->pn_label->text());
            ui->tabWidget->setCurrentIndex(1);  // 跳转到点菜界面
            emit ui->querytable_pushButton->click();  //点击查询餐桌情况按钮
        }
        else
        {
            QMessageBox::information(this, tr("上座失败"), tr("已有顾客！"), QMessageBox::Ok);
        }
    }
}

void Widget::show_mymenu(int table_number)
{
    extern QVector<Table> Table_list;
    for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
    {
        int row = ui->mymenu_tableWidget->rowCount();
        Food f1 = Table_list[table_number-1].m.Menulist.at(i);

        QString name = f1.getName();
        QString price = QString::number(f1.getPrice());

        ui->mymenu_tableWidget->insertRow(row);
        ui->mymenu_tableWidget->setRowHeight(row,30);

        QTableWidgetItem *item0 = new QTableWidgetItem(name);
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->mymenu_tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(price);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->mymenu_tableWidget->setItem(row, 1, item1);

        QProgressBar *progress = new QProgressBar(ui->mymenu_tableWidget);
        progress->setTextVisible(false);

        //以下是为了应对已经下单后，继续加菜的情况
        //food_status:0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->已上菜
        if(f1.getFood_Status() == 0)
        {
            QPushButton *delete_button = new QPushButton(tr("删除"));
            ui->mymenu_tableWidget->setCellWidget(row, 2, delete_button);
            connect(delete_button, SIGNAL(clicked()), this, SLOT(delete_button_clicked()));
        }
        else if(f1.getFood_Status() == 1)
        {
            progress->setValue(0);
            ui->mymenu_tableWidget->setCellWidget(row, 2, progress);
        }
        else if(f1.getFood_Status() == 2)
        {
            progress->setValue(50);
            ui->mymenu_tableWidget->setCellWidget(row, 2, progress);
        }
        else
        {
            progress->setValue(100);
            ui->mymenu_tableWidget->setCellWidget(row, 2, progress);
        }
    }
}

void Widget::clear_mymenu()
{
    int row = ui->mymenu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->mymenu_tableWidget->takeItem(i, j);
            }
            ui->mymenu_tableWidget->removeRow(i);
        }
    }
}

void Widget::clear_evaluate()
{
    int row = ui->evaluate_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->evaluate_tableWidget->takeItem(i, j);
            }
            ui->evaluate_tableWidget->removeRow(i);
        }
    }
}

void Widget::clear_menu()
{
    int row = ui->menu_tableWidget->rowCount();
    if(row != 0)
    {
        for(int i = row; i >= 0; --i)
        {
            for(int j = 0; j < 3; ++j)
            {
                delete ui->menu_tableWidget->takeItem(i, j);
            }
            ui->menu_tableWidget->removeRow(i);
        }
    }
}

void Widget::add_button_clicked()
{
    if(ui->tablenumber_label->text().isEmpty())  //未选择座位
    {
        QMessageBox::information(this, tr("点菜失败"), tr("请先选择您的座位！"), QMessageBox::Ok);
    }
    else
    {
        //下面两行是获取所点击按钮所在的行数（在构造按钮时先给按钮设置一个property（“row”，row），即按钮所在的行数）
        QPushButton *btn = (QPushButton *) sender();
        int row = btn->property("row").toInt();

        //获取button所在行的菜的信息
        int id = ui->menu_tableWidget->item(row, 1)->text().toInt();
        QString name = ui->menu_tableWidget->item(row, 3)->text();
        int price = ui->menu_tableWidget->item(row, 4)->text().toInt();
        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;
        Food f(name, id, price);

        //添加到table的menu中去，添加进去的是常对象
        Table_list[table_number-1].m.Menulist.push_back(f);

        //清空原先的表格
        clear_mymenu();

        //将table的menu中的菜品显示在mymenu_tablewidget中
        show_mymenu(table_number);

        //用标签显示费用                
        QString fee = QString::number(Table_list[table_number-1].m.getSum());
        ui->fee_label->setText("￥:" + fee);

        //使tabwidget_2转到“我的菜单”界面
        ui->tabWidget_2->setCurrentIndex(0);
    }
}

void Widget::delete_button_clicked()
{
    int rowcount = ui->mymenu_tableWidget->rowCount();
    int currentrow;

    //获取点击按钮所在行列
    QPushButton *senderbutton = (QPushButton*)sender();
    for(int i = 0; i < rowcount; ++i)
    {
        QPushButton *button = (QPushButton*)ui->mymenu_tableWidget->cellWidget(i, 2);
        if(senderbutton == button)
        {
            currentrow = i;
            break;
        }
    }

    //删除行
    for(int i = 0; i < 3; ++i)
    {
        delete ui->mymenu_tableWidget->takeItem(currentrow, i);   //删除用 new 申请的内存
    }
    ui->mymenu_tableWidget->removeRow(currentrow);

    //删除菜单里对应的菜
    int table_number = ui->tablenumber_label->text().toInt();
    extern QVector <Table> Table_list;
    Table_list[table_number-1].m.Menulist.removeAt(currentrow);

    //重新显示总价
    QString fee = QString::number(Table_list[table_number-1].m.getSum());
    ui->fee_label->setText("￥:" + fee);
}

void Widget::on_back_pushButton_clicked()
{
    this->hide();
    emit login_dialogshow();
    ui->tablenumber_label->clear();
    ui->fee_label->setText("￥");

    //清空我的菜单
    clear_mymenu();
}

void Widget::receive_customer_pn(QString pn)
{
    clear_menu();
    //用tablewidget来显示菜单
    extern QMultiHash <QString, Food> Menu_total;
    extern QVector <QString> Food_picture_list;
    QMultiHash <QString, Food>::iterator i = Menu_total.begin();
    while(i != Menu_total.end())
    {
        Food f = i.value();
        QString food_type = i.key();
        int id = f.getID();
        QString Id = QString::number(id);       //将int类型转换成QString类型
        QString food_name = f.getName();
        int food_price = f.getPrice();
        QString Food_price = QString::number(food_price);
        QString food_picture;

        if(id - 1 < 6)
        {
            food_picture = Food_picture_list[id - 1];
        }
        else
        {
            food_picture = ":/image/images/chicken.png";
        }

        int row = ui->menu_tableWidget->rowCount();
        ui->menu_tableWidget->insertRow(row);

        //设置tablewidget行高
        ui->menu_tableWidget->setRowHeight(row,75);

        QWidget *widget = new QWidget(ui->menu_tableWidget);
        QLabel *label = new QLabel;
        label->setPixmap(QPixmap(food_picture).scaled(50,50));
        QHBoxLayout *hLayout = new QHBoxLayout(widget);
        hLayout->addWidget(label);
        hLayout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        ui->menu_tableWidget->setCellWidget(row, 0, widget);

        QTableWidgetItem *item1 = new QTableWidgetItem(Id);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(food_type);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(food_name);
        item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(Food_price);
        item4->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->menu_tableWidget->setItem(row, 4, item4);

        QPushButton *add_button = new QPushButton(tr("点菜"));
        ui->menu_tableWidget->setCellWidget(row, 5, add_button);

        //给按钮添加一个属性"row"它的行号，以便在点击时能直接获取它所在的行
        add_button->setProperty("row", row);

        connect(add_button, SIGNAL(clicked()), this, SLOT(add_button_clicked()));

        ++i;
    }

    extern QVector<Table> Table_list;
    for(int i = 0; i < Table_list.size(); ++i)
    {
        if(Table_list[i].getTableCustomer_pn() == pn)
        {
            ui->tablenumber_label->setText("0" + QString::number(i+1));
            int table_number = ui->tablenumber_label->text().toInt();
            //顾客退出又重新登录，显示其菜单
            show_mymenu(table_number);
            QString fee = QString::number(Table_list[table_number-1].m.getSum());
            ui->fee_label->setText("￥:" + fee);
        }
    }
    ui->pn_label->setText(pn);
    ui->pn_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
}

void Widget::on_order_pushButton_clicked()
{
    //显示选择信息框
    QMessageBox *messagebox = new QMessageBox(this);
    messagebox->setWindowTitle("下单确认");
    messagebox->setText("客官确定要下单吗？");
    messagebox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    messagebox->setDefaultButton(QMessageBox::Cancel);
    int choice = messagebox->exec();

    //根据顾客的选择做出反应
    if(choice == QMessageBox::Ok && !ui->tablenumber_label->text().isEmpty())
    {
        //清空原先的表格
        clear_mymenu();

        //重置每列的头文字
        ui->mymenu_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("菜名") << tr("价格") << tr("进度"));

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        //将mymenu显示出来
        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->mymenu_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);          

            QString name = f1.getName();
            QString price = QString::number(f1.getPrice());

            ui->mymenu_tableWidget->insertRow(row);
            ui->mymenu_tableWidget->setRowHeight(row,30);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 0, item0);

            QTableWidgetItem *item1 = new QTableWidgetItem(price);
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 1, item1);

            //设置进度条
            QProgressBar *progress = new QProgressBar(ui->mymenu_tableWidget);
            progress->setTextVisible(false);
            ui->mymenu_tableWidget->setCellWidget(row, 2, progress);

            if(f1.getFood_Status() == 0 || f1.getFood_Status() == 1)
            {
                //设置食物的状态，加的菜状态为0，要设置为1，已经下单或开始制作的菜的状态不能改变
                //0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->准备上菜
                Table_list[table_number-1].m.Menulist[i].setFood_Status(1);
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
    else if(choice == QMessageBox::Ok && ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("下单失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
}

void Widget::on_pay_pushButton_clicked()
{
    QString sum = ui->fee_label->text();
    QMessageBox *paymessage = new QMessageBox(this);
    paymessage->setIconPixmap(QPixmap(":/image/images/pay.png"));
    paymessage->setWindowTitle("买单确认");
    paymessage->setText("客官消费金额 " + sum);
    paymessage->setInformativeText("买单后请客官评价我们的菜品和服务员哦！");
    paymessage->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    paymessage->setDefaultButton(QMessageBox::Ok);
    int choice = paymessage->exec();
    if(choice == QMessageBox::Ok && !ui->tablenumber_label->text().isEmpty())
    {
        //在evaluate_tablewidget内显示评价表

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->evaluate_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);
            QString name = f1.getName();
            //QString price = QString::number(f1.getPrice());

            ui->evaluate_tableWidget->insertRow(row);
            ui->evaluate_tableWidget->setRowHeight(row,50);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->evaluate_tableWidget->setItem(row, 0, item0);

            QDoubleSpinBox *foodbox = new QDoubleSpinBox();
            foodbox->setMaximum(5.0);
            foodbox->setMinimum(0.0);
            foodbox->setSingleStep(0.5);
            foodbox->setValue(5.0);
            ui->evaluate_tableWidget->setCellWidget(row, 1, foodbox);
        }
        //插入服务的评分项
        int row = ui->evaluate_tableWidget->rowCount();

        ui->evaluate_tableWidget->insertRow(row);
        ui->evaluate_tableWidget->setRowHeight(row,50);

        QTableWidgetItem *item0 = new QTableWidgetItem("服务员");
        item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->evaluate_tableWidget->setItem(row, 0, item0);

        QDoubleSpinBox *waiterbox = new QDoubleSpinBox();
        waiterbox->setMaximum(5.0);
        waiterbox->setMinimum(0.0);
        waiterbox->setSingleStep(0.5);
        waiterbox->setValue(5.0);

        ui->evaluate_tableWidget->setCellWidget(row, 1, waiterbox);

        //转换到评价界面
        ui->tabWidget_2->setCurrentIndex(1);
    }
}

void Widget::on_query_pushButton_clicked()
{
    if(!ui->tablenumber_label->text().isEmpty())  //未选择座位
    {
        clear_mymenu();

        //重置每列的头文字
        ui->mymenu_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("菜名") << tr("价格") << tr("进度"));

        int table_number = ui->tablenumber_label->text().toInt();

        extern QVector <Table> Table_list;

        //将table的menu显示出来
        for(int i = 0; i < Table_list[table_number-1].m.Menulist.size(); ++i)
        {
            int row = ui->mymenu_tableWidget->rowCount();
            Food f1 = Table_list[table_number-1].m.Menulist.at(i);

            QString name = f1.getName();
            QString price = QString::number(f1.getPrice());

            ui->mymenu_tableWidget->insertRow(row);
            ui->mymenu_tableWidget->setRowHeight(row,30);

            QTableWidgetItem *item0 = new QTableWidgetItem(name);
            item0->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 0, item0);

            QTableWidgetItem *item1 = new QTableWidgetItem(price);
            item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->mymenu_tableWidget->setItem(row, 1, item1);

            if(f1.getFood_Status() == 0)
            {
                QPushButton *delete_button = new QPushButton(tr("删除"));
                ui->mymenu_tableWidget->setCellWidget(row, 2, delete_button);
                connect(delete_button, SIGNAL(clicked()), this, SLOT(delete_button_clicked()));
            }
            else
            {
                //设置进度条
                QProgressBar *progress = new QProgressBar(ui->mymenu_tableWidget);
                progress->setTextVisible(false);
                ui->mymenu_tableWidget->setCellWidget(row, 2, progress);

                //0->未下单，1->下单尚未被认领，2->厨师认领并已开始做菜，3->准备上菜
                if(f1.getFood_Status() == 1)
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
    else
    {
        QMessageBox::information(this, tr("查询失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
}

void Widget::on_water_pushButton_clicked()
{
    if(ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("发送失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
    else
    {
        emit addwater(ui->tablenumber_label->text());
        QMessageBox::information(this, tr("发送成功"), tr("已发送信息！"), QMessageBox::Ok);
    }
}

void Widget::on_hurry_pushButton_clicked()
{
    if(ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("发送失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
    else
    {
        emit foodhurry(ui->tablenumber_label->text());
        QMessageBox::information(this, tr("发送成功"), tr("已发送信息！"), QMessageBox::Ok);
    }

}

void Widget::on_submit_pushButton_clicked()
{
    extern QVector<Table> Table_list;
    extern QVector <Waiter> Waiter_list;
    extern QVector <Chef> Chef_list;

    if(ui->tablenumber_label->text().isEmpty())
    {
        QMessageBox::information(this, tr("提交失败"), tr("请先选择座位！"), QMessageBox::Ok);
    }
    else
    {
        int table_number = ui->tablenumber_label->text().toInt();
        int food_number = Table_list[table_number - 1].m.Menulist.size();
        int waiter_id = Table_list[table_number - 1].getTableWaiter_id();
        if(food_number == 0 || waiter_id == 0)
        {
            QMessageBox::information(this, tr("提交失败"), tr("请用餐完毕后再评价！"), QMessageBox::Ok);
        }
        else
        {
            for(int i = 0; i < food_number; ++i)
            {
                QDoubleSpinBox *foodbox = (QDoubleSpinBox*)ui->evaluate_tableWidget->cellWidget(i,1);
                double fe = foodbox->value();
                int chef_id = Table_list[table_number - 1].m.Menulist[i].getChef_id();
                int food_id = Table_list[table_number - 1].m.Menulist[i].getID();

                //设置食物的评价
                Table_list[table_number - 1].m.Menulist[i].setF_Evaluation(fe);
                //记录制作食物的厨师所作食物的评分
                Chef_list[chef_id - 1].set_Evaluation(food_id, fe);//记录当天所作的菜（编号）和评价
            }
            //设置对服务员的评价
            QDoubleSpinBox *waiterbox = (QDoubleSpinBox*)ui->evaluate_tableWidget->cellWidget(food_number,1);
            double we = waiterbox->value();
            Waiter_list[waiter_id - 1].set_Evaluation(table_number, we);

            //重置桌子和相应服务员的状态
            Table_list[table_number - 1].setTableStatus(0);     //桌子重新回到空闲状态
            Table_list[table_number - 1].m.Menulist.clear();    //桌子的菜单清空
            Table_list[table_number - 1].setTableCustomer_pn("0");
            Waiter_list[waiter_id - 1].setWaiterTable(0);       //服务员回到空闲状态
            ui->tablenumber_label->clear();                     //清空桌号标签
            clear_mymenu();                                     //清空我的菜单
            clear_evaluate();
            ui->querytable_pushButton->click();                 //重新显示餐桌的空闲状态

            QMessageBox::information(this, tr("提交"), tr("提交成功！感谢您对我们的评价！欢迎下次光临！"), QMessageBox::Ok);
            this->hide();
            emit login_dialogshow();
        }
    }
}

void Widget::closeEvent(QCloseEvent *event)
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

void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}
