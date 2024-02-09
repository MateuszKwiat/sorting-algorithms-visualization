#include "ImGuiController.h"

ImGuiController::ImGuiController() {
}

ImGuiController::~ImGuiController() {
	ImGui::SFML::Shutdown();
}

void ImGuiController::menu(bool& start, int* sortChoice, int* dataSize, int* speed) {

	ImGui::Begin("Data and sorting settings");
	ImGui::RadioButton("Sort1", sortChoice, 0);
	ImGui::RadioButton("Sort2", sortChoice, 1);
	ImGui::RadioButton("Sort3", sortChoice, 2);
	ImGui::SliderInt("Data Size", dataSize, 1, 1820);
	ImGui::SliderInt("Animation speed", speed, 1, 20);
	ImGui::Button("Apply");
	if (ImGui::Button("Start"))
		start = false;
	ImGui::End();
}

void ImGuiController::initialize(sf::RenderWindow& window) {
	ImGui::SFML::Init(window);
}

void ImGuiController::eventProcessing(sf::Event& event) {
	ImGui::SFML::ProcessEvent(event);
}

void ImGuiController::update(sf::RenderWindow& window) {
	ImGui::SFML::Update(window, this->deltaClock.restart());
}

void ImGuiController::render(sf::RenderWindow& window, bool& start, int* sortChoice, int* dataSize, int* speed) {
	this->menu(start, sortChoice, dataSize, speed);
	ImGui::SFML::Render(window);
}