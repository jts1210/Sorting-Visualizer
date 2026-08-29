#include "Algorithm.hpp"
#include "MergeSort.hpp"
#include "RandomArray.hpp"
#include <utility>
#include <vector>
#include <string>

MergeSort::MergeSort(int size, std::string timeComplexity) : Algorithm(size, timeComplexity) {
	width = 1;
	leftStart = 0;
    left = 0;
    mid = 0;
    right = 0;
    rightEnd = 0;
	merging = false;
}

void MergeSort::step() {
	if (finished) return;

	if (width >= size) {
		finished = true;
		return;
	}

    if (!merging) {
        left = leftStart;
        mid = std::min(leftStart + width, size);
        right = mid;
        rightEnd = std::min(leftStart + 2 * width, size);
        temp.clear();
        merging = true;
    }

    if (left < mid && right < rightEnd) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            temp.push_back(arr[right++]);
        }
        numComparisons++;
    }
    else if (left < mid) {
        temp.push_back(arr[left++]);
    }
    else if (right < rightEnd) {
        temp.push_back(arr[right++]);
    }
    else {
        for (size_t k = 0; k < temp.size(); k++) {
            arr[leftStart + k] = temp[k];
            numSwaps++;
        }
        merging = false;
        leftStart += 2 * width;
        if (leftStart >= size) {
            leftStart = 0;
            width *= 2;
        }
    }
}