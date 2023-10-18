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

RobotPos* moveRobot(RobotPos *pos, float dx, float dy);

struct RobotHP{
    int hp;
    int max_hp;
};

RobotHP* hitRobot(RobotHP* hpDef, RobotPos *posAtk, RobotPos *posDef);

#endif //HW1_ROBOT_H
