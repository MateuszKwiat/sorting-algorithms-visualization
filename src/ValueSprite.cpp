//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ValueSprite.h"

ValueSprite::ValueSprite(float value, const sf::Vector2f &size, const sf::Vector2f &position) {
    this->value = value;
    this->setSize(size);
    this->setOrigin(sf::Vector2f(0.f, size.y));
    this->setPosition(position);
    this->setFillColor(sf::Color::White);
}
