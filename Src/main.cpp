//
// Created by yixin on 2023/10/2.
//

#include <cstdio>
#include "../Inc/main.h"
#include "../Inc/robot.h"

int main() {
    struct Robot a[5];
    for (int i = 0; i < 5; i++) {
        a[i].name[0] = 'a';
        a[i].name[1] = '0' + char(i);
        a[i].pos.x = 0;
        a[i].pos.y = 0;
        a[i].pos.yaw = 0;
        a[i].pos.pitch = 0;
        a[i].hp.current_hp = 100;
        a[i].hp.max_hp = 100;
    }
    moveRobot(&a[0], 1, 2);

    return 0;
}
