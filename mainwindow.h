#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "turtle.h"
#include "inputcontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);

private slots:
    void setCommand(QVariant varValue);
private:
    Ui::MainWindow *ui;
    InputController *controller;
    std::vector<std::vector<int> > Command;

    turtle Turtle;

    // 工具函数
    // 将 vector 转化为 QPoint
    QPoint convertVector(std::vector<int> vec);
};

#endif // MAINWINDOW_H
