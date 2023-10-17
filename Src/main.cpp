//
// Created by yixin on 2023/10/2.
//

#include <iostream>
#include "../Inc/main.h"
#include "../Inc/robot.h"

int main() {
    RobotPos pos{0,0,0,0};
    moveRobot(&pos, 1, 20000);
    std::cout << pos.x << std::endl << pos.y << std::endl;

    return 0;
}
