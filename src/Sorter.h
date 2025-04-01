//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#pragma once
#include <vector>

#include "ValuesVectorController.h"
#include "ExtendedRenderWindow.h"


class Sorter {
public:
    Sorter() = delete;

    static void bubble_sort(ValuesVectorController& values_vector, ExtendedRenderWindow& window);
};
