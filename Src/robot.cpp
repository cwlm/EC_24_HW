//
// Created by yixin on 2023/10/2.
//

#include "../Inc/robot.h"
#include <cmath>

Robot *moveRobot(Robot *robot, float dx, float dy) {
    robot->pos.x += dx;
    robot->pos.y += dx;
    return robot;
}

Robot *hitRobot(Robot *def, Robot *atk) {
    float distance = sqrtf(powf(def->pos.x - atk->pos.x, 2) + powf(def->pos.y - atk->pos.y, 2));

    def->hp.current_hp = def->hp.max_hp;
    return def;
}
