//
// Created by yixin on 2023/10/2.
//

#ifndef HW1_ROBOT_H
#define HW1_ROBOT_H

/* field
--------
|  R   |     // red base
|      |
|      |
|      |
|      |
|  B   |    // blue base
--------
*/


struct RobotPos{
    float x;     // m   set down left as (0,0)
    float y;     // m
    float yaw;   // deg
    float pitch; // deg
};

struct RobotHP{
    int current_hp;
    int max_hp;
};

struct Robot {
    char name[2];
    struct RobotPos pos;
    struct RobotHP hp;
};

Robot *moveRobot(Robot *robot, float dx, float dy);

Robot *hitRobot(Robot *def, Robot *atk);

#endif //HW1_ROBOT_H
