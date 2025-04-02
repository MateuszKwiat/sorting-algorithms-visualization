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
    constexpr auto button_size = ImVec2(60.f, 20.f);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(Config::gui_window_size, ImGuiCond_Always);
    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoResize);

    ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::SetNextItemWidth(200.f);
    ImGui::SliderInt("##Frames_to_skip", &Config::frames_to_skip, 0, 120, "Frames to skip: %d");

    if (!Config::sort) {
        ImGui::SetCursorPos(ImVec2(10, 60));
        ImGui::SetNextItemWidth(200.f);
        ImGui::SliderInt("##Amount_of_values", &Config::amount, 0, 2000, "Amount of values: %d");

        if (ImGui::Button("Sort", button_size)) {
            Config::sort = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Shuffle", button_size)) {
            Config::shuffle = true;
        }
        ImGui::SameLine();
        if (ImGui::Button("Apply", button_size)) {

        }
    }
    else {
        const ImVec2 text_size = ImGui::CalcTextSize("Sorting...");
        ImGui::SetCursorPos(ImVec2((Config::gui_window_size.x - text_size.x) * 0.5f, 60));

        static float timer = 0.0f;
        timer += ImGui::GetIO().DeltaTime;
        const int dots = static_cast<int>(timer * 3.0f) % 4;
        std::string loadingText = "Sorting";
        for (int i = 0; i < dots; ++i) {
            loadingText += ".";
        }
        ImGui::Text("%s", loadingText.c_str());
    }


    ImGui::End();
}