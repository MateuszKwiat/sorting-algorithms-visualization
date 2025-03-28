//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "ValuesVectorController.h"

#include <iostream>

ValuesVectorController::ValuesVectorController(const unsigned int amount, const sf::Vector2u& window_size) {
    gen = std::make_unique<std::mt19937>(rd());
    value_distribution = std::make_unique<std::uniform_real_distribution<float>>(0.0f, 1.0f);

    this->calculate_value_sprite_params(amount, window_size);
    this->initialize_vector(amount, window_size);
}

void ValuesVectorController::calculate_value_sprite_params(const unsigned int amount, const sf::Vector2u &window_size) {
    float value_sprite_width;
    // check if columns can be created with 1px gap between them
    if (amount * 2 >= window_size.x) {
        value_sprite_width = static_cast<float>(window_size.x) / static_cast<float>(amount);
        value_sprite_position_shift = value_sprite_width;
    }
    else {
        value_sprite_width = (static_cast<float>(window_size.x) - (static_cast<float>(amount) - 1)) / static_cast<float>(amount);
        value_sprite_position_shift = value_sprite_width + 1.f;
    }
    value_sprite_size = {value_sprite_width, static_cast<float>(window_size.y)};
}

void ValuesVectorController::initialize_vector(const int unsigned amount, const sf::Vector2u& window_size) {
    sf::Vector2f value_sprite_position {0.f, static_cast<float>(window_size.y)};
    ValueSprite temp_value_sprite {value_sprite_size, value_sprite_position};
    for (int i = 0; i < amount; i++) {
        temp_value_sprite = (*value_distribution)(*gen);
        this->push_back(std::make_unique<ValueSprite>(temp_value_sprite));

        value_sprite_position.x += value_sprite_position_shift;
        temp_value_sprite.setPosition(value_sprite_position);
        temp_value_sprite.setSize(value_sprite_size);
    }

    (*this)[amount - 1]->setFillColor(sf::Color::Magenta);
}
