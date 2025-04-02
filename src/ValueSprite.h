//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

class ValueSprite final : public sf::RectangleShape {
private:
    float value {};
    float window_height{};

public:
    ValueSprite(float val, const sf::Vector2f& size, const sf::Vector2f& position);
    ValueSprite(const ValueSprite& value_sprite) noexcept;
    ValueSprite() = default;
    ValueSprite& operator=(float val) noexcept;
    explicit operator float() const noexcept { return value; }
};



