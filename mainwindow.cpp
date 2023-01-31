#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(new InputController)
{
    ui->setupUi(this);
    controller->start();
    connect(controller, SIGNAL(sendCommand(QVariant)), this, SLOT(setCommand(QVariant)));
    qDebug("create");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    // 根据命令绘图
    // @TODO 补全其他指令,调整画笔颜色，左转右转调用海龟类中的
    bool draw_flag = true; // 标志当前是否需要画图
    for(int i = 0; i < Command.size(); i++){
        std::vector<int> command = Command[i];

        if(command[0] == 5){
            qDebug("5 paint");
            QPoint cur_pos = convertVector(Turtle.getPos());
            Turtle.move(command[1]);
            QPoint next_pos = convertVector(Turtle.getPos());

            if(draw_flag){
                painter.drawLine(cur_pos, next_pos);
            }
        }
    }
}

void MainWindow::setCommand(QVariant varValue){
    Command = varValue.value<std::vector<std::vector<int>>>();
    this->update(); // 重绘
    return ;
}

QPoint MainWindow::convertVector(std::vector<int> vec){
    return QPoint(vec[0], vec[1]);
}
