#include "Algorithm.hpp"
#include "BubbleSort.hpp"
#include "RandomArray.hpp"
#include <utility>

BubbleSort::BubbleSort(int size) : Algorithm(size) {
	i = 0;
    j = 0;
}

void BubbleSort::step() {
    if (finished) return;
    
    if (j >= size - i - 1) {
        j = 0;
        i++;
        if (i >= size - 1) {
            finished = true;
            return;
        }
    }

    if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        numSwaps++;
    }
    numComparisons++;
    j++;
}