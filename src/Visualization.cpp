//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "Visualization.h"

Visualization::Visualization() {
    window = std::make_unique<ExtendedRenderWindow>(sf::VideoMode({1200, 800}), "Sorting algorithms visualization");
    window->setFramerateLimit(120);

    vector_controller = std::make_unique<ValuesVectorController>(70, window->getSize());
}

void Visualization::run() const {
    while (window->isOpen())
    {
        if (!static_cast<bool>(*vector_controller)) {
            Sorter::bubble_sort(*vector_controller, *window);
        }
        else {
            window->handle_events();
            window->update(*vector_controller);
        }
    }
}


