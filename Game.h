//
// Created by bendi on 2022. 02. 03..
//

#ifndef ROCKET_SCIENCE2_GAME_H
#define ROCKET_SCIENCE2_GAME_H
#include <spdlog/spdlog.h>
#include <raylib-cpp.hpp>
#include <raylib.h>
#include "objects/Cannon.h"
#include "objects/Grass.h"
#include "objects/UI.h"
#include "objects/Bullet.h"


class Game {
private:
    raylib::Window window;
    raylib::Font defaultFont;
    Cannon cannon;
    Grass grass;
    GUI ui;
    std::vector<Bullet> bullets;
    float launchVelocity = 25;
public:
    Game(): window(1280, 720, "Rocket Science"), defaultFont(), cannon(0), bullets() {
        window.SetTargetFPS(60);
    }

    void loop();

    void render();

    void update(float dt = 0);
};

#endif //ROCKET_SCIENCE2_GAME_H
