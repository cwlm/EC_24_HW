//
// Created by csc on 2023/10/22.
//

#include "../Inc/robot.h"
#include <cstdio>
#include <cmath>

// function to move robot
Robot *moveRobot(Robot *robot, float dx, float dy) {
    printf("robot %s moved\nfrom x:%.2f y:%.2f\n", robot->name, robot->pos.x, robot->pos.y);
    robot->pos.x += dx;
    robot->pos.y += dy;
    printf("to x:%.2f y:%.2f\n", robot->pos.x, robot->pos.y);
    return robot;
}

// function to attack another robot
Robot *hitRobot(Robot *def, Robot *atk) {
    printf("robot %s tried to hit robot %s.\n", atk->name, def->name);

    // check if succeeded
    float distance = sqrtf(powf(def->pos.x - atk->pos.x, 2) + powf(def->pos.y - atk->pos.y, 2));
    bool hitSucceed = distance <= (rand() % 1000 + 1) / 100.0;

    // handle the result
    if (hitSucceed) {
        printf("Succeeded, hp of robot %s reduced from %d ", def->name, def->hp.current_hp);
        def->hp.current_hp = def->hp.current_hp < 10 ? 0 : (def->hp.current_hp - 10);
        printf("to %d.\n", def->hp.current_hp);
    } else {
        printf("Failed, hp of robot %s still %d.\n", def->name, def->hp.current_hp);
    }
    return def;
}
