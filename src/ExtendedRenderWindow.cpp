//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include "ExtendedRenderWindow.h"

ExtendedRenderWindow::ExtendedRenderWindow(sf::VideoMode video_mode, const char *str) : sf::RenderWindow(video_mode, *str) {}

void ExtendedRenderWindow::draw(const ValueSprite &sprite) {
    RenderWindow::draw(sprite);
}
