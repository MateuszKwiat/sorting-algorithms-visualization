//
// Created by Mateusz Kwiatkowski on 07/04/2025.
//

#include "../Sorter.h"

int Sorter::partition(ValuesVectorController& values_vector, const int low, const int high, ExtendedRenderWindow& window) {
    int i = low - 1;
    int frames_counter = 0;

    for (int j = low; j < high; ++j) {
        window.handle_events();
        if (!window.isOpen()) {
            return -1;
        }

        values_vector[j].setFillColor(sf::Color::Red);
        values_vector[high].setFillColor(sf::Color::Red);

        if (values_vector.more_than(high, j)) {
            values_vector.swap(++i, j);
        }

        if (frames_counter++ >= Config::frames_to_skip) {
            window.update();
            frames_counter = 0;
        }

        values_vector[j].setFillColor(sf::Color::White);
        values_vector[j + 1].setFillColor(sf::Color::White);
    }
    values_vector.swap(i + 1, high);
    return i + 1;
}

void Sorter::quick_sort(ValuesVectorController& values_vector, const int low, const int high, ExtendedRenderWindow& window) {
    if (low < high) {
        if (const int pivot_index = partition(values_vector, low, high, window); pivot_index != -1) {
            quick_sort(values_vector, low, pivot_index - 1, window);
            quick_sort(values_vector, pivot_index + 1, high, window);
        }
        else {
            return;
        }
    }
}

void Sorter::quick_sort(ValuesVectorController& values_vector,  ExtendedRenderWindow& window) {
    quick_sort(values_vector, 0, static_cast<int>(values_vector) - 1, window);

    after_sort_animation(values_vector, window);
    values_vector = true;
    Config::sort = false;
}