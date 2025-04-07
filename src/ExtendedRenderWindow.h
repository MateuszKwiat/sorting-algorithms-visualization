//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "ValueSprite.h"
#include "ValuesVectorController.h"
#include "Gui.h"

class ExtendedRenderWindow final : public sf::RenderWindow {
private:
    ValuesVectorController& controller;

    void draw(const ValueSprite & sprite);
    void draw();

public:
    using sf::RenderWindow::draw;
    ExtendedRenderWindow(sf::VideoMode video_mode, const char * str, ValuesVectorController& controller);
    ExtendedRenderWindow() = delete;
    void handle_events();
    void update();
};
