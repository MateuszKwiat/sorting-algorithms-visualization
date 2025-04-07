//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

#include "ValuesVectorController.h"
#include "ExtendedRenderWindow.h"

class Visualization {
private:
    std::unique_ptr<ExtendedRenderWindow> window;
    std::unique_ptr<ValuesVectorController> vector_controller;
    std::unordered_map<std::string, std::function<void()>> sorting_algorithms_map;

    void prepare_sorting_algorithms_map();

public:
    Visualization();
    ~Visualization() = default;
    void run() const;
};