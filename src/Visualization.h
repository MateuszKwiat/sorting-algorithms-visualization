//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "ValueSprite.h"
#include "ExtendedRenderWindow.h"

class Visualization {
private:
    ExtendedRenderWindow* window = nullptr;

    ValueSprite* test_val = nullptr;

public:
    Visualization();
    ~Visualization();
    void run() const;
};