//
// Created by Mateusz Kwiatkowski on 07/04/2025.
//

#include "../Sorter.h"

void Sorter::selection_sort(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    const std::size_t n = values_vector.size();
    int frames_counter = 0;

    for (std::size_t i = 0; i < n - 1; ++i) {
        std::size_t min_index = i;
        window.handle_events();
        if (!window.isOpen()) {
            return;
        }

        for (std::size_t j = i + 1; j < n; ++j) {
            if (values_vector.more_than(min_index, j)) {
                min_index = j;
            }
        }

        values_vector[min_index].setFillColor(sf::Color::Red);
        values_vector[i].setFillColor(sf::Color::Red);

        values_vector.swap(i, min_index);

        if (frames_counter++ >= Config::frames_to_skip) {
            window.update();
            frames_counter = 0;
        }

        values_vector[i].setFillColor(sf::Color::White);
        values_vector[min_index].setFillColor(sf::Color::White);
    }
    after_sort_animation(values_vector, window);
    values_vector = true;
    Config::sort = false;
}
