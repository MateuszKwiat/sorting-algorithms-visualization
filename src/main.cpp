#include "Visualization.h"

// https://tailwindcss.com/docs/colors
// for nicer colors

int main() {
    const Visualization visualization;

    visualization.run();
}

// class GUI holding imgui window
//
// class without constructors Settings holding:
// bool sort;
// bool frames_to_skip
// sort_choice
// bool shuffle
// bool applya


// New methods: extend_vector: (recalc value_sprite_position, use initialize_vector
//
// shrink_vector: erase last n elems from vec, calculate n based on config::amount and this->size()


// Initialize_vector:
// Value_sprite_position-> move to class def, calc in calculate_value_sprite_params