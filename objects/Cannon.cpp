//
// Created by bendi on 2022. 02. 03..
//

#include "Cannon.h"

static const raylib::Color Brown = raylib::Color(139, 69, 19, 255);
static const raylib::Color Gray = raylib::Color(130, 130, 130, 255);

void Cannon::render() {
    this->boom.Draw(Gray);
    this->base.Draw(Brown);
    DrawLineEx(raylib::Vector2(190, 645-height), raylib::Vector2(190+getShootX(), 645-getActualHeight()), 5, raylib::Color::Blue());
}

void Cannon::update(float dt) {

}

int Cannon::getHeight() const {
    return height;
}

void Cannon::setHeight(float h) {
    height = Clamp(h, 0, 500);
    base.SetY(640-height);
    boom.SetY(630-height);
}

int Cannon::getAngle() const {
    return angle;
}

void Cannon::setAngle(float a) {
    this->angle = Clamp(a, -90, 0);
}

float Cannon::getActualHeight() const {
    return sin(-angle*DEG2RAD)*40+height;
}

float Cannon::getShootX() const {
    return cos(angle*DEG2RAD)*40;
}
