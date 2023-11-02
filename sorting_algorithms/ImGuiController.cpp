#include "ImGuiController.h"

ImGuiController::ImGuiController() {
}

ImGuiController::~ImGuiController() {
	ImGui::SFML::Shutdown();
}

void ImGuiController::menu(bool& start) {
	int a = 0;
	int b = 0;
	ImGui::Begin("Data and sorting settings");
	ImGui::RadioButton("Sort1", 0);
	ImGui::RadioButton("Sort2", 0);
	ImGui::RadioButton("Sort3", 0);
	ImGui::SliderInt("Data Size", &a, 1, 1820);
	ImGui::SliderInt("Animation speed", &b, 1, 20);
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

void ImGuiController::render(sf::RenderWindow& window, bool& start) {
	this->menu(start);
	ImGui::SFML::Render(window);
}