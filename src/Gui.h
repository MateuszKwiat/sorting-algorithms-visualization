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
private:
    static void make_gui_window();
    static void make_frames_skip_slider();
    static void make_amount_slider();
    static void make_drop_down_list();
    static void make_buttons();
    static void make_sorting_text_animation();

public:
    Gui() = delete;
    Gui(const Gui&) = delete;
    Gui& operator=(const Gui&) = delete;
    Gui(Gui&&) = delete;
    Gui& operator=(Gui&&) = delete;

    static void set_style();
    static void gui(sf::RenderWindow &window);

    static sf::Clock delta_clock;
};
