//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "ValueSprite.h"

class ExtendedRenderWindow final : public sf::RenderWindow {
public:
    using sf::RenderWindow::draw;
    ExtendedRenderWindow(sf::VideoMode video_mode, const char * str);
    ExtendedRenderWindow() = default;
    void draw(const ValueSprite & sprite);
};
