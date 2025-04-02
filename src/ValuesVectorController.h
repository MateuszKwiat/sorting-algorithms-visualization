//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <vector>
#include <random>

#include "ValueSprite.h"


class ValuesVectorController : private std::vector<ValueSprite> {
private:
    std::random_device rd;
    std::unique_ptr<std::mt19937> gen;
    std::unique_ptr<std::uniform_real_distribution<float>> value_distribution;
    sf::Vector2f value_sprite_size;
    float value_sprite_position_shift{};
    bool is_sorted;

    void initialize_vector();
    void calculate_value_sprite_params();
    ValueSprite& prepare_value_sprite(ValueSprite& value_sprite, sf::Vector2f& value_sprite_position) const;
    std::vector<ValueSprite>& get_vector() { return *this; }
    [[nodiscard]] const std::vector<ValueSprite>& get_vector() const { return *this; }
public:
    ValuesVectorController();
    ~ValuesVectorController() = default;
    [[nodiscard]] bool more_than(unsigned int i, unsigned int j) const;
    void swap(unsigned int i, unsigned int j);
    explicit operator bool() const noexcept { return is_sorted; }
    ValuesVectorController& operator=(bool val) noexcept;
    void shuffle();

    friend class ExtendedRenderWindow;
    friend class Sorter;
};
