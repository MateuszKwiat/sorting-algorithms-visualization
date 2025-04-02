//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ValueSprite.h"

ValueSprite::ValueSprite(const float val, const sf::Vector2f &size, const sf::Vector2f &position) : window_height(size.y) {
    this->value = val;
    this->setSize({size.x, size.y * value});
    this->setOrigin({0.f, this->getSize().y});
    this->setPosition(position);
    this->setFillColor(sf::Color::White);

}

ValueSprite::ValueSprite(const ValueSprite &value_sprite) noexcept : RectangleShape(value_sprite),
                                                                     window_height(value_sprite.window_height) {
    this->value = value_sprite.value;
}

ValueSprite &ValueSprite::operator=(const float val) noexcept {
    value = val;
    this->setSize({this->getSize().x, window_height * value});
    this->setOrigin({0.f, this->getSize().y});
    return *this;
}

void swap(ValueSprite& lhs, ValueSprite& rhs) noexcept {
    const ValueSprite temp_value_sprite = lhs;
    lhs = static_cast<float>(rhs);
    rhs = static_cast<float>(temp_value_sprite);
}



