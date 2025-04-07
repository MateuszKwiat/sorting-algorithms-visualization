//
// Created by Mateusz Kwiatkowski on 07/04/2025.
//

#include "../Sorter.h"

void Sorter::insertion_sort(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    const std::size_t n = values_vector.size();
    int frames_counter = 0;

    for (std::size_t i = 1; i < n; ++i) {
        auto key = values_vector[i];
        std::size_t j = i;

        while (j > 0 && values_vector[j - 1] > key) {
            window.handle_events();
            if (!window.isOpen()) {
                return;
            }

            values_vector[j].setFillColor(sf::Color::Red);
            values_vector[j - 1].setFillColor(sf::Color::Red);

            values_vector[j] = static_cast<float>(values_vector[j - 1]);

            if (frames_counter++ >= Config::frames_to_skip) {
                window.update();
                frames_counter = 0;
            }

            values_vector[j].setFillColor(sf::Color::White);
            values_vector[j - 1].setFillColor(sf::Color::White);
            --j;
        }
        values_vector[j] = static_cast<float>(key);
    }
    after_sort_animation(values_vector, window);
    values_vector = true;
    Config::sort = false;
}
