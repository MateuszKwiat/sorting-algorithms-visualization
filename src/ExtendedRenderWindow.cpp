//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ExtendedRenderWindow.h"

ExtendedRenderWindow::ExtendedRenderWindow(const sf::VideoMode video_mode, const char *str,
                                           ValuesVectorController &controller) : sf::RenderWindow(video_mode, *str),
    controller(controller) {
    if (!ImGui::SFML::Init(*this))
        return;
}

void ExtendedRenderWindow::draw(const ValueSprite &sprite) {
    RenderWindow::draw(sprite);
}

void ExtendedRenderWindow::draw() {
    for (const auto& val : controller) {
        RenderWindow::draw(val);
    }
}

void ExtendedRenderWindow::handle_events() {
    while (const auto event = this->pollEvent()) {
        ImGui::SFML::ProcessEvent(*this, *event);
        if (event->is<sf::Event::Closed>())
            this->close();
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                this->close();
        }
        else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
            const unsigned int new_width = std::max(resized->size.x, Config::minimal_window_size_u.x);
            const unsigned int new_height = std::max(resized->size.y, Config::minimal_window_size_u.y);
            this->setSize(sf::Vector2u(new_width, new_height));
        }
    }
}

void ExtendedRenderWindow::update() {
    ImGui::SFML::Update(*this, Gui::delta_clock.restart());
    Gui::gui(*this);

    this->clear();
    this->draw();
    ImGui::SFML::Render(*this);

    this->display();
}
