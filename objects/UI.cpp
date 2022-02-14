//
// Created by bendi on 2022. 02. 12..
//

#include "UI.h"

void GUI::render() {
    if (open) {
        open = !GuiWindowBox(settingsWindow, "Settings");
        DrawText("Move Speed: " + std::to_string(platformMoveSpeed), 220, 130, 20, raylib::Color::Black());
        platformMoveSpeed = GuiSlider(platformSpeedSlider, "10", "2000", platformMoveSpeed, 10, 2000);
        DrawText("Rotate Speed: " + std::to_string(rotateSpeed), 220, 180, 20, raylib::Color::Black());
        rotateSpeed = GuiSlider(rotateSpeedSlider, "1", "500", rotateSpeed, 1, 500);
        DrawText("Adjust Speed: " + std::to_string(adjustSpeed), 220, 230, 20, raylib::Color::Black());
        adjustSpeed = GuiSlider(adjustSpeedSlider, "0", "100", adjustSpeed, 0, 100);
        DrawText("Update Density: " + std::to_string(updateDensity), 220, 280, 20, raylib::Color::Black());
        updateDensity = GuiSlider(updateDensitySlider, "0", "100", updateDensity, 1, 120);
    } else {
        open = GuiButton(settingsBtn, "Settings");
    }
}

void GUI::update(float dt) {

}
