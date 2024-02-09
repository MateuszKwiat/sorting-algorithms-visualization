#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ImGuiController {
private:
	sf::Clock deltaClock;
	ImFont* mainFont;

	void menu(bool& apply, bool& start, int* sortChoice, int* dataSize, int* speed);

public:
	ImGuiController();
	~ImGuiController();
	void initialize(sf::RenderWindow& window);
	void eventProcessing(sf::Event& event);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, bool& apply, bool& start, int* sortChoice, int* dataSize, int* speed);
};

