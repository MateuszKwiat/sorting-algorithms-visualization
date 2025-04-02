//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "Visualization.h"

#include "Sorter.h"
#include "Config.h"

Visualization::Visualization() {
    window = std::make_unique<ExtendedRenderWindow>(sf::VideoMode({1200, 800}), "Sorting algorithms visualization");
    window->setFramerateLimit(120);

    vector_controller = std::make_unique<ValuesVectorController>(Config::amount, window->getSize());
    Gui::set_style();
}

void Visualization::run() const {
    while (window->isOpen())
    {
        if (Config::sort) {
            Sorter::bubble_sort(*vector_controller, Config::frames_to_skip, *window);
        }
        else {
            window->handle_events();
            window->update(*vector_controller);
        }
    }
    ImGui::SFML::Shutdown();
}


