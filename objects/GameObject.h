//
// Created by bendi on 2022. 02. 05..
//

#ifndef ROCKET_SCIENCE2_GAMEOBJECT_H
#define ROCKET_SCIENCE2_GAMEOBJECT_H

class GameObject {
    virtual void render() = 0;
    virtual void update(float dt) = 0;
};

#endif //ROCKET_SCIENCE2_GAMEOBJECT_H
