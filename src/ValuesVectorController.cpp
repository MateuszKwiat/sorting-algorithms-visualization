//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "ValuesVectorController.h"

ValuesVectorController::ValuesVectorController(const int amount, const sf::Vector2u& window_size) {
    gen = std::make_unique<std::mt19937>(rd());
    value_distribution = std::make_unique<std::uniform_real_distribution<float>>(0.0f, 1.0f);

    this->initialize_vector(amount, window_size);
}

void ValuesVectorController::initialize_vector(const int amount, const sf::Vector2u& window_size) {
    float val_width = window_size.x / amount;
    float temp_pos = 0.f;
    float temp_height = 10.f;
    for (int i = 0; i < amount; i++) {
        float temp_value = value_distribution->operator()(*gen);
        this->push_back(std::make_unique<ValueSprite>(temp_value, sf::Vector2f(val_width, temp_value * static_cast<float>(window_size.y)),
                                                      sf::Vector2f(temp_pos, static_cast<float>(window_size.y))));
        temp_pos += val_width + 1.f;
        temp_height += 10.f;
    }
}
