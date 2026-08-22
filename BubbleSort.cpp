#include "BubbleSort.hpp"
#include "RandomArray.hpp"
#include <random>

BubbleSort::BubbleSort(int size) {
    this->size = size;
    arr = new int[size];
    numSwaps = 0;
    numComparisons = 0;
	i = 0;
	j = 0;
    finished = false;
    arr = RandomArray::generateArray(size);
}

const int* BubbleSort::getArr() {
    return arr;
}

int BubbleSort::getNumSwaps() {
    return numSwaps;
}

int BubbleSort::getNumComparions() {
    return numComparisons;
}

int BubbleSort::getI() {
	return i;
}

int BubbleSort::getJ() {
	return j;
}

bool BubbleSort::isFinished() {
    return finished;
}

void BubbleSort::step() {
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