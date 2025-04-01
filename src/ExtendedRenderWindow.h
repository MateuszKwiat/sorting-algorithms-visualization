//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "ValueSprite.h"
#include "ValuesVectorController.h"

class ExtendedRenderWindow final : public sf::RenderWindow {
private:
    void draw(const ValueSprite & sprite);
    void draw(const ValuesVectorController & controller);

public:
    using sf::RenderWindow::draw;
    ExtendedRenderWindow(sf::VideoMode video_mode, const char * str);
    ExtendedRenderWindow() = default;
    void handle_events();
    void update(const ValuesVectorController & controller);
};
