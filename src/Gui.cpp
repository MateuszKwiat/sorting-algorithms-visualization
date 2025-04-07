//
// Created by Mateusz Kwiatkowski on 02/04/2025.
//

#include "Gui.h"
#include "Config.h"

sf::Clock Gui::delta_clock = sf::Clock();

void Gui::make_gui_window() {
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(Config::gui_window_size, ImGuiCond_Always);
    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoResize);
}

void Gui::make_frames_skip_slider() {
    ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::SetNextItemWidth(Config::max_gui_element_width);
    ImGui::SliderInt("##Frames_to_skip", &Config::frames_to_skip, 0, Config::max_frames_to_skip, "Frames to skip: %d");
}

void Gui::make_amount_slider() {
    ImGui::SetCursorPos(ImVec2(10, 60));
    ImGui::SetNextItemWidth(Config::max_gui_element_width);
    ImGui::SliderInt("##Amount_of_values", &Config::amount, 2, static_cast<int>(Config::sfml_window_size_u.x),
                     "Amount of values: %d");
}

void Gui::make_drop_down_list() {
    ImGui::SetCursorPos(ImVec2(10, 90));
    ImGui::SetNextItemWidth(Config::max_gui_element_width);
    if (ImGui::BeginCombo("##Select_sorting_algorithm", Config::selected_sort.c_str())) {
        for (const auto& sorting_algorithm : Config::sorting_algorithms) {
            const bool is_selected = (Config::selected_sort == sorting_algorithm);
            if (ImGui::Selectable(sorting_algorithm.c_str(), is_selected)) {
                Config::selected_sort = sorting_algorithm;
            }
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}

void Gui::make_buttons() {
    if (ImGui::Button("Apply", Config::button_size)) {
        Config::apply_changes = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Shuffle", Config::button_size)) {
        Config::shuffle = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Sort", Config::button_size)) {
        Config::sort = true;
    }
}

void Gui::make_sorting_text_animation() {
    const ImVec2 text_size = ImGui::CalcTextSize("Sorting...");
    ImGui::SetCursorPos(ImVec2((Config::gui_window_size.x - text_size.x) * 0.5f,
                               (Config::gui_window_size.y - text_size.y) * 0.5f));

    static float timer = 0.0f;
    timer += ImGui::GetIO().DeltaTime;
    const int dots = static_cast<int>(timer * 3.0f) % 4;
    std::string loadingText = "Sorting";
    for (int i = 0; i < dots; ++i) {
        loadingText += ".";
    }
    ImGui::Text("%s", loadingText.c_str());
}


void Gui::set_style() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 5.f;
    style.FrameRounding = 5.f;
    style.GrabRounding = 5.f;
    style.ItemSpacing = ImVec2(10, 10);
}

void Gui::gui(sf::RenderWindow &window) {
    make_gui_window();
    make_frames_skip_slider();

    if (!Config::sort) {
        make_amount_slider();
        make_drop_down_list();
        make_buttons();
    }
    else {
        make_sorting_text_animation();
    }


    ImGui::End();
}