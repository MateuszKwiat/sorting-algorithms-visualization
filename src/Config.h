//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#pragma once

class Config {
public:
    Config() = delete;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    Config(Config&&) = delete;
    Config& operator=(Config&&) = delete;

    inline static bool sort = false;
    inline static int frames_to_skip = 0;
    inline static int sort_choice = 0;
    inline static bool shuffle = false;
    inline static bool apply = false;
};

