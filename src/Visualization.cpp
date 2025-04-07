//
// Created by Mateusz Kwiatkowski on 24/03/2025.
//

#include <memory>

#include "Visualization.h"
#include "Sorter.h"
#include "Config.h"

Visualization::Visualization() {
    vector_controller = std::make_unique<ValuesVectorController>();
    window = std::make_unique<ExtendedRenderWindow>(
        sf::VideoMode({Config::sfml_window_size_u.x, Config::sfml_window_size_u.y}),
        "Sorting algorithms visualization", *vector_controller);
    window->setFramerateLimit(Config::framerate_limit);
    this->prepare_sorting_algorithms_map();
    Gui::set_style();
}

void Visualization::prepare_sorting_algorithms_map() {
    sorting_algorithms_map[Config::sorting_algorithms[0]] = [&]() -> void { Sorter::bubble_sort(*vector_controller, *window); };
    sorting_algorithms_map[Config::sorting_algorithms[1]] = [&]() -> void { Sorter::insertion_sort(*vector_controller, *window); };
    sorting_algorithms_map[Config::sorting_algorithms[2]] = [&]() -> void { Sorter::selection_sort(*vector_controller, *window); };
    sorting_algorithms_map[Config::sorting_algorithms[3]] = [&]() -> void { Sorter::quick_sort(*vector_controller, *window); };
}

void Visualization::run() const {
    while (window->isOpen())
    {
        if (Config::sort) {
            if (auto map_iterator = sorting_algorithms_map.find(Config::selected_sort);
                map_iterator != sorting_algorithms_map.end()) {
                map_iterator->second();
            }
        }
        else if (Config::shuffle) {
            vector_controller->shuffle();
        }
        else if (Config::apply_changes) {
            if (Config::amount != static_cast<int>(*vector_controller)) {
                vector_controller->apply_new_size();
            }
            Config::apply_changes = false;
        }
        else {
            window->handle_events();
            window->update();
        }
    }
    ImGui::SFML::Shutdown();
}


