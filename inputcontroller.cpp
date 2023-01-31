#include "inputcontroller.h"

InputController::InputController()
{
    qRegisterMetaType<QVariant>("QVariant");
}

void InputController::run(){
    // 获取输入
    std::cout << "Input commands: " << std::endl;
    int num = 0;
    std::vector<std::vector<int>> command;
    std::vector<int> tmp_command;
    while(std::cin >> num){
        tmp_command.push_back(num);

        if(std::cin.get() == '\n' && tmp_command.size() != 0){
            command.push_back(tmp_command);
            tmp_command.clear();
        }

        if(num == 9){
            QVariant varValue;
            varValue.setValue(command);
            emit sendCommand(varValue);
            command.clear();
            qDebug("update");
        }
    }
}
