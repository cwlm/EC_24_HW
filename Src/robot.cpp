//
// Created by yixin on 2023/10/2.
//

#include "../Inc/robot.h"
#include <cstdio>
#include <cmath>

Robot *moveRobot(Robot *robot, float dx, float dy) {
    printf("robot %s moved\nfrom x:%.2f y:%.2f\n", robot->name, robot->pos.x, robot->pos.y);
    robot->pos.x += dx;
    robot->pos.y += dy;
    printf("to x:%.2f y:%.2f", robot->pos.x, robot->pos.y);
    return robot;
}

Robot *hitRobot(Robot *def, Robot *atk) {
    float distance = sqrtf(powf(def->pos.x - atk->pos.x, 2) + powf(def->pos.y - atk->pos.y, 2));

    def->hp.current_hp = def->hp.max_hp;
    return def;
}
