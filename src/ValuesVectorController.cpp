//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>
#include <ranges>

#include "ValuesVectorController.h"
#include "Config.h"

ValuesVectorController::ValuesVectorController() : is_sorted(false) {
    gen = std::make_unique<std::mt19937>(rd());
    value_distribution = std::make_unique<std::uniform_real_distribution<float>>(0.0f, 1.0f);

    this->calculate_value_sprite_params();
    this->initialize_vector();
}

void ValuesVectorController::calculate_value_sprite_params() {
    float value_sprite_width;
    // check if columns can be created with 1px gap between them
    if (static_cast<float>(Config::amount) * 2 >= Config::sfml_window_size_f.x) {
        value_sprite_width = Config::sfml_window_size_f.x / static_cast<float>(Config::amount);
        value_sprite_position_shift = value_sprite_width;
    }
    else {
        value_sprite_width = (Config::sfml_window_size_f.x - (static_cast<float>(Config::amount) - 1)) / static_cast<float>(Config::amount);
        value_sprite_position_shift = value_sprite_width + 1.f;
    }
    value_sprite_size = {value_sprite_width, Config::sfml_window_size_f.y};
}

ValueSprite& ValuesVectorController::prepare_value_sprite(ValueSprite& value_sprite, sf::Vector2f& value_sprite_position) const {
    value_sprite_position.x += value_sprite_position_shift;
    value_sprite.setPosition(value_sprite_position);
    value_sprite.setSize(value_sprite_size);
    value_sprite = (*value_distribution)(*gen);

    return value_sprite;
}


void ValuesVectorController::initialize_vector() {
    sf::Vector2f value_sprite_position {-value_sprite_position_shift, Config::sfml_window_size_f.y};
    ValueSprite temp_value_sprite {(*value_distribution)(*gen), value_sprite_size, value_sprite_position};

    std::ranges::for_each(std::views::iota(0u, static_cast<unsigned int>(Config::amount)), [&](int i) -> void {
        this->emplace_back(
            std::make_unique<ValueSprite>(this->prepare_value_sprite(temp_value_sprite, value_sprite_position)));
    });

    (*this)[0]->setFillColor(sf::Color::Magenta);
    (*this)[Config::amount - 1]->setFillColor(sf::Color::Magenta);
}

bool ValuesVectorController::more_than(const unsigned int i, const unsigned int j) const {
    return static_cast<float>(*(*this)[i]) > static_cast<float>(*(*this)[j]);
}

void ValuesVectorController::swap(const unsigned int i, const unsigned int j) const {
    const ValueSprite temp_value_sprite(*(*this)[i]);
    *(*this)[i] = static_cast<float>(*(*this)[j]);
    *(*this)[j] = static_cast<float>(temp_value_sprite);
}

ValuesVectorController &ValuesVectorController::operator=(const bool val) noexcept {
    is_sorted = val;
    return *this;
}
