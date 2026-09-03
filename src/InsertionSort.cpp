#include "Algorithm.hpp"
#include "InsertionSort.hpp"
#include "RandomArray.hpp"
#include <utility>
#include <string>
#include <vector>

InsertionSort::InsertionSort(int size, std::string timeComplexity) : Algorithm(size, timeComplexity) {
	i = 1;
	j = 0;
	key = 0;
	inserting = false;
}

void InsertionSort::step() {
    if (finished) return;

    if (i >= size) {
        finished = true;
        return;
    }

    if (!inserting) {
        key = arr[i];
        j = i - 1;
        inserting = true;
    }

    if (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        numSwaps++;
        j--;
        numComparisons++;
    }
    else {
        if (j >= 0) numComparisons++;  // count the failed comparison that ended the loop
        arr[j + 1] = key;
        inserting = false;
        i++;
    }
}