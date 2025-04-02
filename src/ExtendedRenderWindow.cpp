//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ExtendedRenderWindow.h"

ExtendedRenderWindow::ExtendedRenderWindow(const sf::VideoMode video_mode, const char *str) : sf::RenderWindow(video_mode, *str) {
    if (!ImGui::SFML::Init(*this))
        return;
}

void ExtendedRenderWindow::draw(const ValueSprite &sprite) {
    RenderWindow::draw(sprite);
}

void ExtendedRenderWindow::draw(const ValuesVectorController& controller) {
    for (const auto& val : controller) {
        RenderWindow::draw(val);
    }
}

void ExtendedRenderWindow::handle_events() {
    while (const auto event = this->pollEvent())
    {
        ImGui::SFML::ProcessEvent(*this, *event);
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
    ImGui::SFML::Update(*this, Gui::delta_clock.restart());
    Gui::gui(*this);

    this->clear();
    this->draw(controller);
    ImGui::SFML::Render(*this);

    this->display();
}
