//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#pragma once

class Config final {
public:
    Config() = delete;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    Config(Config&&) = delete;
    Config& operator=(Config&&) = delete;

    static bool sort;
    static int frames_to_skip;
    static int sort_choice;
    static bool shuffle;
    static bool apply;
};