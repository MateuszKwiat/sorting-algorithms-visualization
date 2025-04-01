//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#include "Sorter.h"

void Sorter::bubble_sort(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    const size_t n = values_vector.size();
    bool swapped{};

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;

        for (size_t j = 0; j < n - i - 1; ++j) {
            window.handle_events();
            if (!window.isOpen()) {
                return;
            }

            values_vector[j]->setFillColor(sf::Color::Red);
            values_vector[j + 1]->setFillColor(sf::Color::Red);
            if (values_vector.more_than(j, j + 1)) {
                values_vector.swap(j, j + 1);
                swapped = true;
            }

            window.update(values_vector);

            values_vector[j]->setFillColor(sf::Color::White);
            values_vector[j + 1]->setFillColor(sf::Color::White);
        }

        if (!swapped) break;
    }
    values_vector = true;
}
