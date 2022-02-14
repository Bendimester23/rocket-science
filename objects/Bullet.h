//
// Created by bendi on 2022. 02. 12..
//

#ifndef ROCKET_SCIENCE2_BULLET_H
#define ROCKET_SCIENCE2_BULLET_H

#include "GameObject.h"
#include <raylib-cpp.hpp>

class Bullet: public GameObject {
    raylib::Vector2 pos;
    raylib::Vector2 velocity;
    raylib::Rectangle rec;
    bool onGround;
    raylib::Vector2 startPos;
    std::vector<raylib::Vector2> positions;
    int updateId;
    float totalPath;
public:
    Bullet(float x, float y, float vX, float vY): pos(x, y), velocity(vX, vY), rec(x, y, 10, 10), startPos(x, y) {
        positions.insert(positions.cend(), pos);
    }

    ~Bullet() {
        positions.clear();
    }

    void render();

    void update(float dt);

    void update(float dt, int posDensity);

    float getTotalPathX();
};

#endif //ROCKET_SCIENCE2_BULLET_H
