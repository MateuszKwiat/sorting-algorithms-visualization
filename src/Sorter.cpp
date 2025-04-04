//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#include "Sorter.h"

#include <iostream>

void Sorter::update_color(const ValuesVectorController& values_vector, ValueSprite &value_sprite, ExtendedRenderWindow &window, const sf::Color &color) {
    value_sprite.setFillColor(sf::Color::Green);
    window.handle_events();
    if (!window.isOpen()) {
        return;
    }
    window.update(values_vector);
}

void Sorter::after_sort_animation(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    std::ranges::for_each(values_vector.get_vector(), [&](ValueSprite &value_sprite) ->void {
        update_color(values_vector, value_sprite, window, sf::Color::Green);
    });

    std::ranges::for_each(values_vector.get_vector(), [&](ValueSprite &value_sprite) -> void {
        value_sprite.setFillColor(sf::Color::White);
    });
}

void Sorter::bubble_sort(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    const size_t n = values_vector.size();
    bool swapped{};
    int frames_counter = 0;

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;

        for (size_t j = 0; j < n - i - 1; ++j) {
            window.handle_events();
            if (!window.isOpen()) {
                return;
            }

            values_vector[j].setFillColor(sf::Color::Red);
            values_vector[j + 1].setFillColor(sf::Color::Red);
            if (values_vector.more_than(j, j + 1)) {
                values_vector.swap(j, j + 1);
                swapped = true;
            }
            if (frames_counter++ >= Config::frames_to_skip) {
                window.update(values_vector);
                frames_counter = 0;
            }

            values_vector[j].setFillColor(sf::Color::White);
            values_vector[j + 1].setFillColor(sf::Color::White);
        }

        if (!swapped) break;
    }
    after_sort_animation(values_vector, window);
    values_vector = true;
    Config::sort = false;
}
