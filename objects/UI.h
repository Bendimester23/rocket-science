//
// Created by bendi on 2022. 02. 12..
//

#ifndef ROCKET_SCIENCE2_UI_H
#define ROCKET_SCIENCE2_UI_H

#include <raylib-cpp.hpp>
#include "../raygui.h"
#include "GameObject.h"

static raylib::Rectangle settingsBtn(10, 690, 50, 20);
static raylib::Rectangle settingsWindow(200, 100, 500, 500);
static raylib::Rectangle platformSpeedSlider(220, 150, 460, 20);
static raylib::Rectangle rotateSpeedSlider(220, 200, 460, 20);
static raylib::Rectangle adjustSpeedSlider(220, 250, 460, 20);
static raylib::Rectangle updateDensitySlider(220, 300, 460, 20);

class GUI: public GameObject {
    bool open;

public:
    float platformMoveSpeed = 1000.0f;
    float rotateSpeed = 100.0f;
    float adjustSpeed = 5.0f;
    int updateDensity = 10;
    GUI(): open(false) {
    }

    void render();

    void update(float dt);
};

#endif //ROCKET_SCIENCE2_UI_H
