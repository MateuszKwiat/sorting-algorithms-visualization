//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#include "Gui.h"
#include "Config.h"

sf::Clock Gui::delta_clock = sf::Clock();

void Gui::set_style() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 5.f;
    style.FrameRounding = 5.f;
    style.GrabRounding = 5.f;
    style.ItemSpacing = ImVec2(10, 10);
}


void Gui::gui(sf::RenderWindow &window) {
    ImVec2 button_size = ImVec2(60.f, 20.f);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(220, 90), ImGuiCond_Always);
    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoResize);

    ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::SetNextItemWidth(200.f);
    ImGui::SliderInt("##Frames_to_skip", &Config::frames_to_skip, 0, 120, "Frames to skip: %d");

    if (ImGui::Button("Sort", button_size)) {

    }
    ImGui::SameLine();
    if (ImGui::Button("Shuffle", button_size)) {

    }
    ImGui::SameLine();
    if (ImGui::Button("Apply", button_size)) {

    }
    ImGui::End();
}