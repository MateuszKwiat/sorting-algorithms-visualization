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