//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>
#include <ranges>

#include "ValuesVectorController.h"

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

ValueSprite& ValuesVectorController::prepare_value_sprite(ValueSprite& value_sprite, sf::Vector2f& value_sprite_position) const {
    value_sprite_position.x += value_sprite_position_shift;
    value_sprite.setPosition(value_sprite_position);
    value_sprite.setSize(value_sprite_size);
    value_sprite = (*value_distribution)(*gen);

    return value_sprite;
}


void ValuesVectorController::initialize_vector(const int unsigned amount, const sf::Vector2u& window_size) {
    sf::Vector2f value_sprite_position {-value_sprite_position_shift, static_cast<float>(window_size.y)};
    ValueSprite temp_value_sprite {(*value_distribution)(*gen), value_sprite_size, value_sprite_position};

    std::ranges::for_each(std::views::iota(0u, amount), [&](int i) -> void {
        this->emplace_back(
            std::make_unique<ValueSprite>(this->prepare_value_sprite(temp_value_sprite, value_sprite_position)));
    });

    (*this)[0]->setFillColor(sf::Color::Magenta);
    (*this)[amount - 1]->setFillColor(sf::Color::Magenta);
}

bool ValuesVectorController::more_than(unsigned int i, unsigned int j) const {
    return static_cast<float>(*(*this)[i]) > static_cast<float>(*(*this)[j]);
}

void ValuesVectorController::swap(unsigned int i, unsigned int j) const {
    const ValueSprite temp_value_sprite(*(*this)[i]);
    *(*this)[i] = static_cast<float>(*(*this)[j]);
    *(*this)[j] = static_cast<float>(temp_value_sprite);
}
