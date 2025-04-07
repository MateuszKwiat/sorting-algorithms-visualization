//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#pragma once
#include "imgui.h"

class Config {
public:
    Config() = delete;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    Config(Config&&) = delete;
    Config& operator=(Config&&) = delete;

    // general
    inline static bool sort = false;
    inline static int frames_to_skip = 0;
    inline static int max_frames_to_skip = 360;
    inline static int amount = 70;
    inline static int sort_choice = 0;
    inline static bool shuffle = false;
    inline static bool apply_changes = false;

    // GUI
    constexpr static auto gui_window_size = ImVec2(220, 120);
    constexpr static auto button_size = ImVec2(60.f, 20.f);
    constexpr static float slider_width = 200.f;

    // SFML
    inline static auto sfml_window_size_f = sf::Vector2f(1200.f, 800.f);
    inline static auto sfml_window_size_u = sf::Vector2u(1200u, 800u);
    inline static auto minimal_window_size_u = sf::Vector2u(400u, 300u);
    constexpr static unsigned int framerate_limit = 120u;
};

