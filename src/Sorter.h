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
    static void update_color(ValueSprite& value_sprite, ExtendedRenderWindow& window, int i);
    static int partition(ValuesVectorController& values_vector, int low, int high, ExtendedRenderWindow& window);
    static void quick_sort(ValuesVectorController& values_vector, int low, int high, ExtendedRenderWindow& window);

public:
    Sorter() = delete;

    static void bubble_sort(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
    static void quick_sort(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
    static void selection_sort(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
};
