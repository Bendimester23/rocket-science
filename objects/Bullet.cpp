//
// Created by bendi on 2022. 02. 12..
//

#include <spdlog/spdlog.h>
#include "Bullet.h"


void Bullet::render() {
    rec.Draw(raylib::Color::Red());

    for (int i = 0; i < positions.size(); i++) {
        if (i > 0) DrawLine(positions[i-1].x, positions[i-1].y, positions[i].x, positions[i].y, raylib::Color::Red());
    }
}

void Bullet::update(float dt) {

}

void Bullet::update(float dt, int posDensity) {
    if (updateId == 0) {
        startPos = pos;
    }
    if (onGround) return;
    pos += (velocity * dt);
    this->totalPath = pos.x-startPos.x;
    spdlog::info(pos.x);
    spdlog::info(startPos.x);
    spdlog::info(totalPath);
    spdlog::info("------------------");
    if (pos.y >= 660) {
        onGround = true;
        positions.insert(positions.cend(), pos);
    }
    rec.SetPosition(pos.x, pos.y);
    velocity.SetY(velocity.y+10*dt);
    if (updateId % posDensity == 0) positions.insert(positions.cend(), pos);
    updateId++;
}

float Bullet::getTotalPathX() {
    return totalPath;
}