//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "Visualization.h"

#include <iostream>

#include "Sorter.h"
#include "Config.h"

Visualization::Visualization() {
    window = std::make_unique<ExtendedRenderWindow>(
        sf::VideoMode({Config::sfml_window_size_u.x, Config::sfml_window_size_u.y}),
        "Sorting algorithms visualization");
    window->setFramerateLimit(Config::framerate_limit);

    vector_controller = std::make_unique<ValuesVectorController>();
    Gui::set_style();
}

void Visualization::run() const {
    while (window->isOpen())
    {
        if (Config::sort) {
            Sorter::bubble_sort(*vector_controller, *window);
        }
        else if (Config::shuffle) {
            vector_controller->shuffle();
        }
        else if (Config::apply_changes) {
            if (Config::amount != static_cast<int>(*vector_controller)) {
                vector_controller->apply_new_size();
            }
            Config::apply_changes = false;
        }
        else {
            window->handle_events();
            window->update(*vector_controller);
        }
    }
    ImGui::SFML::Shutdown();
}


