//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#include "Gui.h"

sf::Clock Gui::delta_clock = sf::Clock();

void Gui::gui(sf::RenderWindow &window) {
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Always);
    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoResize);
    ImGui::Text("Hello");
    ImGui::End();
}