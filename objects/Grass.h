//
// Created by bendi on 2022. 02. 05..
//

#ifndef ROCKET_SCIENCE2_GRASS_H
#define ROCKET_SCIENCE2_GRASS_H
#include "GameObject.h"
#include <raylib-cpp.hpp>

class Grass: public GameObject {
private:
    raylib::Rectangle ground;
    raylib::Rectangle hill;
    int height = 0;

public:
    Grass(): ground(0, 720-50, 1280, 720), hill(0, 720-50, 200, 1000) {

    }

    void render() override;
    void update(float dt) override;

    void setHeight(float height);

    int getHeight();
};

#endif //ROCKET_SCIENCE2_GRASS_H
