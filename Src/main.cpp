//
// Created by yixin on 2023/10/2.
//

#include <cstdio>
#include "../Inc/main.h"
#include "../Inc/robot.h"

int main() {
    Robot b1{0, 0, 0, 0, 100, 100};
    moveRobot(&b1, 1, 20000);
    printf("x:%.1f y:%.1f", b1.pos.x, b1.pos.y);

    return 0;
}
