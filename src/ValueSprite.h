//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

class ValueSprite final : public sf::RectangleShape {
private:
    float value {};

public:
    ValueSprite(float value, const sf::Vector2f& size, const sf::Vector2f& position);
};



