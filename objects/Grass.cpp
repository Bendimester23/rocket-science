//
// Created by bendi on 2022. 02. 05..
//

#include "Grass.h"

void Grass::render() {
    ground.Draw(raylib::Color::DarkGreen());
    hill.Draw(raylib::Color::DarkGreen());
}

void Grass::update(float dt) {

}

void Grass::setHeight(float h) {
    this->height = Clamp(h, 0, 500);
    this->hill.SetY(720-50-h);
}

int Grass::getHeight() {
    return height;
}
