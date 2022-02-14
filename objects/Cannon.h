//
// Created by bendi on 2022. 02. 03..
//

#ifndef ROCKET_SCIENCE2_CANNON_H
#define ROCKET_SCIENCE2_CANNON_H
#include "raylib-cpp.hpp"
#include "GameObject.h"

class Cannon: public GameObject {
private:
    float angle;
    raylib::Rectangle base;
    //Da boom thingy stuff
    raylib::Rectangle boom;
    int height;

public:
    Cannon(int h): base(50, 640-h, 100, 30), boom(100, 630-h, 100, 30), angle(0), height(h) {
    }

    void render() override;
    void update(float dt) override;

    void setHeight(float h);
    int getHeight() const;

    void setAngle(float h);
    int getAngle() const;

    float getActualHeight() const;
    float getShootX() const;
};

#endif //ROCKET_SCIENCE2_CANNON_H
