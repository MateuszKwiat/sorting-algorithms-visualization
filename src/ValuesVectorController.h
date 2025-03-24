//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <vector>
#include <random>

#include "ValueSprite.h"


class ValuesVectorController : private std::vector<std::unique_ptr<ValueSprite>> {
private:
    std::random_device rd;
    std::unique_ptr<std::mt19937> gen;
    std::unique_ptr<std::uniform_real_distribution<float>> value_distribution;

    void initialize_vector(int amount, const sf::Vector2u& window_size);

public:
    ValuesVectorController(int amount, const sf::Vector2u& window_size);
    ~ValuesVectorController() = default;

    friend class ExtendedRenderWindow;
};
