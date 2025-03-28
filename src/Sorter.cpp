//
// Created by Mateusz Kwiatkowski on 28/03/2025.
//

#include "Sorter.h"

void Sorter::bubble_sort(const ValuesVectorController &values_vector, const ExtendedRenderWindow &window) {
    const size_t n = values_vector.size();
    bool swapped{};

    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;

        for (size_t j = 0; j < n - i - 1; ++j) {
            if (values_vector.more_than(j, j + 1)) {
                values_vector.swap(j, j + 1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}
