//
// Created by csc on 2023/10/22.
//

#include "../Inc/robot.h"
#include <cstdio>
#include <cmath>

// function to deduce HP
void reduceHP(Robot *robot, int dhp){
    robot->hp.current_hp = robot->hp.current_hp < dhp ? 0 : (robot->hp.current_hp - dhp);
    if (robot->hp.current_hp <= 0){
        robot->alive = false;
    }
}

// function to move robot
int moveRobot(Robot *robot, float dx, float dy) {
    printf("robot %s moved\nfrom x:%.2f y:%.2f\n", robot->name, robot->pos.x, robot->pos.y);
    robot->pos.x += dx;
    robot->pos.y += dy;
    printf("to x:%.2f y:%.2f\n", robot->pos.x, robot->pos.y);
    return 0;
}

// function to attack another robot
int hitRobot(Robot *def, Robot *atk) {
    if (!def->alive){
        fprintf(stderr, "Robot %s is already dead!", def->name);
        return 1;
    }

    printf("Robot %s tried to hit robot %s.\n", atk->name, def->name);
    const float vMax = 10;// maximum muzzle velocity

    // check if succeeded or rule violated
    float distance = sqrtf(powf(def->pos.x - atk->pos.x, 2) + powf(def->pos.y - atk->pos.y, 2));
    float vOut = sqrtf(distance * 9.8 / sin(2 * atk->pos.yaw * M_PI / 180.0));
    printf("%f %f\n", vOut, vMax);

    bool exceedVLimit = vOut > vMax;
    bool hitSucceed = distance <= (rand() % 1000 + 1) / 100.0;

    // handle the result
    if (exceedVLimit) {// speed
        printf("Robot %s violates the rule by exceeding maximum muzzle velocity.\n", atk->name);
        printf("Hp of robot %s reduced by 10, from %d ", atk->name, atk->hp.current_hp);
        reduceHP(atk, 10);
        printf("to %d.\n", atk->hp.current_hp);
    }

    if (hitSucceed) {// hit
        printf("Succeeded, hp of robot %s reduced from %d ", def->name, def->hp.current_hp);
        def->hp.current_hp = def->hp.current_hp < 10 ? 0 : (def->hp.current_hp - 10);
        printf("to %d.\n", def->hp.current_hp);
    } else {
        printf("Failed, hp of robot %s still %d.\n", def->name, def->hp.current_hp);
    }

    atk->gimbal.heat += 10;
    if (atk->gimbal.heat > 200) { // heat
        printf("Robot %s severely violates the rule by overheating, ", atk->name);
        atk->gimbal.heat = 200;
        reduceHP(atk, 50);
        printf("HP reduced to %d.\n", atk->hp.current_hp);
    } else if (atk->gimbal.heat <= 200 && atk->gimbal.heat > 100) {
        printf("Robot %s violates the rule by overheating, ", atk->name);
        reduceHP(atk, 10);
        printf("HP reduced to %d.\n", atk->hp.current_hp);
    }

    return 0;
}
