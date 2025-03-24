//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "ValueSprite.h"
#include "ValuesVectorController.h"
#include "ExtendedRenderWindow.h"

class Visualization {
private:
    std::unique_ptr<ExtendedRenderWindow> window;
    std::unique_ptr<ValuesVectorController> controller;

public:
    Visualization();
    ~Visualization() = default;
    void run() const;
};