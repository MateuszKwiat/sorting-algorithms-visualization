//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#pragma once

#include "imgui.h"
#include "imgui-SFML.h"
#include "Config.h"
#include "ExtendedRenderWindow.h"
#include "SFML/System/Clock.hpp"

class Gui {
public:
    Gui() = delete;
    static void gui(sf::RenderWindow &window);

    static sf::Clock delta_clock;
};
