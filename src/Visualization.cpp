//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "Visualization.h"

Visualization::Visualization() {
    window = new ExtendedRenderWindow(sf::VideoMode({1200, 800}), "Sorting algorithms visualization");
    window->setFramerateLimit(60);

    test_val = new ValueSprite(0.5f, sf::Vector2f(100.f, 50.f), sf::Vector2f(0.f, 800.f));
}

Visualization::~Visualization() {
    delete test_val;
    delete window;
}

void Visualization::run() const {
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }

        window->clear();

        window->draw(*test_val);

        window->display();
    }
}


