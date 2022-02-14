//
// Created by bendi on 2022. 02. 03..
//

#include "Game.h"

void Game::loop() {
    spdlog::info("Started.");
    while (!window.ShouldClose()) {
        window.ClearBackground(raylib::Color::RayWhite());
        window.BeginDrawing();

        this->update(this->window.GetFrameTime());
        this->render();

        window.EndDrawing();
    }
}

const raylib::Vector2 heightTxtPos(10, 40);
const raylib::Vector2 angleTxtPos(10, 70);
const raylib::Vector2 launchTxtPos(10, 100);
const raylib::Vector2 pathTxtPos(10, 130);

raylib::Rectangle testRec(10, 10, 10, 10);

void Game::render() {
    this->grass.render();
    this->cannon.render();
    this->ui.render();
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].render();
    }
    testRec.Draw(raylib::Color::Black());
    defaultFont.DrawText("Height: " + std::to_string(cannon.getHeight()) + "m", heightTxtPos, 26, 1, raylib::Color::Black());
    defaultFont.DrawText("Angle: " + std::to_string(-cannon.getAngle()) + "°", angleTxtPos, 26, 1, raylib::Color::Black());
    defaultFont.DrawText("Launch Velocity: " + std::to_string(launchVelocity), launchTxtPos, 26, 1, raylib::Color::Black());
    if (!bullets.empty()) defaultFont.DrawText("Last Path: " + std::to_string(bullets[bullets.size()-1].getTotalPathX()) + "m", pathTxtPos, 26, 1, raylib::Color::Black());
    this->defaultFont.DrawText("FPS: " + std::to_string(window.GetFPS()), raylib::Vector2(10, 10), 26, 1, raylib::Color::Black());
}

void Game::update(float dt) {
    if (IsKeyDown(KEY_W)) {
        this->grass.setHeight(this->grass.getHeight()+(ui.platformMoveSpeed*dt));
        this->cannon.setHeight(this->cannon.getHeight()+(ui.platformMoveSpeed*dt));
    } else if (IsKeyDown(KEY_S)) {
        this->grass.setHeight(this->grass.getHeight()-(ui.platformMoveSpeed*dt));
        this->cannon.setHeight(this->cannon.getHeight()-(ui.platformMoveSpeed*dt));
    }
    if (IsKeyDown(KEY_Q)) {
        this->cannon.setAngle(this->cannon.getAngle()-(ui.rotateSpeed*dt));
    } else if (IsKeyDown(KEY_A)) {
        this->cannon.setAngle(this->cannon.getAngle()+(ui.rotateSpeed*dt));
    }

    if (IsKeyDown(KEY_E)) {
        this->launchVelocity = Clamp(this->launchVelocity+dt*ui.adjustSpeed, 0, 100);
    } else if (IsKeyDown(KEY_D)) {
        this->launchVelocity = Clamp(this->launchVelocity-dt*ui.adjustSpeed, 0, 100);
    }

    if (IsKeyPressed(KEY_SPACE)) {
        bullets.insert(bullets.cbegin(), Bullet(
                190,
                645-cannon.getHeight(),
                cos(-cannon.getAngle()*DEG2RAD)*launchVelocity,
                sin(cannon.getAngle()*DEG2RAD)*launchVelocity)
                );
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        bullets.clear();
    }

    testRec.SetPosition(cannon.getShootX(), cannon.getHeight()-cannon.getActualHeight());

    this->cannon.update(dt);
    this->ui.update(dt);

    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].update(dt, ui.updateDensity);
    }
}
