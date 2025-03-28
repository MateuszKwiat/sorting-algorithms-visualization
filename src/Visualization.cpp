//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "Visualization.h"

Visualization::Visualization() {
    window = std::make_unique<ExtendedRenderWindow>(sf::VideoMode({1200, 800}), "Sorting algorithms visualization");
    window->setFramerateLimit(60);

    controller = std::make_unique<ValuesVectorController>(250, window->getSize());
}

void Visualization::run() const {
    int i = 0;
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window->close();
            }
        }

        window->clear();

        window->draw(*controller);

        if (i == 0) {
            Sorter::bubble_sort(*controller, *window);
            i++;
        }

        window->display();
    }
}


