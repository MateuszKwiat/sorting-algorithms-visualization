//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ExtendedRenderWindow.h"

ExtendedRenderWindow::ExtendedRenderWindow(sf::VideoMode video_mode, const char *str) : sf::RenderWindow(video_mode, *str) {}

void ExtendedRenderWindow::draw(const ValueSprite &sprite) {
    RenderWindow::draw(sprite);
}

void ExtendedRenderWindow::draw(const ValuesVectorController& controller) {
    for (const auto& val : controller) {
        RenderWindow::draw(*val);
    }
}

void ExtendedRenderWindow::handle_events() {
    while (const std::optional event = this->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            this->close();
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                this->close();
        }
    }
}

void ExtendedRenderWindow::update(const ValuesVectorController &controller) {
    this->clear();
    this->draw(controller);
    this->display();

}
