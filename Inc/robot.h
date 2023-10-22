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
struct RobotChassis{
    float maxV;
    float power;
};

struct RobotGimbal{
    float maxAngularV;
    float power;
    float heat;
};

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
    char name[3];
    int maxP;
    bool alive;
    struct RobotPos pos;
    struct RobotHP hp;
    struct RobotChassis chassis;
    struct RobotGimbal gimbal;
};

int moveRobot(Robot *robot, float dx, float dy);

int hitRobot(Robot *def, Robot *atk);

#endif //HW1_ROBOT_H
