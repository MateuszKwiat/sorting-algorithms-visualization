//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ValueSprite.h"

ValueSprite::ValueSprite(const sf::Vector2f &size, const sf::Vector2f &position) {
    this->value = value;
    this->setSize(size);
    this->setOrigin({0.f, size.y});
    this->setPosition(position);
    this->setFillColor(sf::Color::White);
}

ValueSprite::ValueSprite(const ValueSprite &value_sprite) noexcept : RectangleShape(value_sprite) {
    this->value = value_sprite.value;
}

ValueSprite &ValueSprite::operator=(const float val) noexcept {
    value = val;
    this->setSize({this->getSize().x, this->getSize().y * value});
    this->setOrigin({0.f, this->getSize().y});
    return *this;
}


