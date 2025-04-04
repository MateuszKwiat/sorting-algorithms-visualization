//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#pragma once
#include <vector>

#include "ValuesVectorController.h"
#include "ExtendedRenderWindow.h"


class Sorter {
private:
    static void after_sort_animation(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
    static void update_color(const ValuesVectorController& values_vector, ValueSprite& value_sprite, ExtendedRenderWindow& window, const sf::Color& color);
public:
    Sorter() = delete;

    static void bubble_sort(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
};
