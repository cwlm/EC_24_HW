//
// Created by yixin on 2023/10/2.
//

#include <cstdio>
#include "../Inc/main.h"
#include "../Inc/robot.h"

int main() {
    // initialize
    struct Robot a[5];// team a
    struct Robot b[5];// team b

    for (int i = 0; i < 5; i++) {
        a[i].name[0] = 'a';
        a[i].name[1] = (char) ((int) '0' + i);
        a[i].name[2] = '\0';
        a[i].pos.x = 0;
        a[i].pos.y = 0;
        a[i].pos.yaw = 45;
        a[i].pos.pitch = 0;
        a[i].hp.current_hp = 100;
        a[i].hp.max_hp = 100;
    }
    for (int i = 0; i < 5; i++) {
        b[i].name[0] = 'b';
        b[i].name[1] = (char) ((int) '0' + i);
        b[i].name[2] = '\0';
        b[i].pos.x = 0;
        b[i].pos.y = 0;
        b[i].pos.yaw = 45;
        b[i].pos.pitch = 0;
        b[i].hp.current_hp = 100;
        b[i].hp.max_hp = 100;
    }

    moveRobot(&a[0], 1, 5);
    while (a[0].hp.current_hp > 0) {
        hitRobot(&a[0], &b[0]);
    }

    return 0;
}
