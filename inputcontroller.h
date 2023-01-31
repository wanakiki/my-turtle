#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H
#include <QObject>
#include <QThread>
#include <iostream>
#include <QVariant>

// ref: https://blog.csdn.net/weixin_42126427/article/details/109614541
// https://blog.csdn.net/ligare/article/details/122730222
// QVariant 包装 qRegisterMetaType 注册

// 独立线程处理标准输入输出
// sendCommand 信号发送给UI界面进行更新

Q_DECLARE_METATYPE(std::vector<std::vector<int>>)

class InputController : public QThread
{
    Q_OBJECT
public:
    InputController();

protected:
    void run();
private:
    std::vector<std::vector<int>> command;

signals:
    void sendCommand(QVariant varValue);
};

#endif // INPUTCONTROLLER_H
