//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#include <ranges>

#include "Sorter.h"

void Sorter::update_color(ValueSprite &value_sprite, ExtendedRenderWindow &window, const int i) {
    value_sprite.setFillColor(sf::Color::Green);
    window.handle_events();
    if (!window.isOpen()) {
        return;
    }
    if (i % (Config::frames_to_skip + 1) == 0) {
        window.update();
    }
}

void Sorter::after_sort_animation(ValuesVectorController &values_vector, ExtendedRenderWindow &window) {
    std::ranges::for_each(std::views::iota(0, static_cast<int>(values_vector)), [&](const int i) ->void {
        update_color(values_vector[i], window, i);
    });

    std::ranges::for_each(values_vector.get_vector(), [&](ValueSprite &value_sprite) -> void {
        value_sprite.setFillColor(sf::Color::White);
    });
}