#include "ImGuiController.h"

ImGuiController::ImGuiController() {
}

ImGuiController::~ImGuiController() {
	ImGui::SFML::Shutdown();
}

void ImGuiController::menu(bool& apply, bool& start, int* sortChoice, int* dataSize, int* speed) {

	ImGui::Begin("Data and sorting settings");
	ImGui::RadioButton("Bubble Sort", sortChoice, 0);
	ImGui::SameLine();
	ImGui::RadioButton("Selection Sort", sortChoice, 1);
	ImGui::SameLine();
	ImGui::RadioButton("Quick Sort", sortChoice, 2);
	ImGui::SliderInt("Data Size", dataSize, 1, 1820);
	ImGui::SliderInt("Animation speed", speed, 1, 20);
	if (ImGui::Button("Apply"))
		apply = true;
	ImGui::SameLine();
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

void ImGuiController::render(sf::RenderWindow& window, bool& apply, bool& start, 
	int* sortChoice, int* dataSize, int* speed) {
	this->menu(apply, start, sortChoice, dataSize, speed);
	ImGui::SFML::Render(window);
}