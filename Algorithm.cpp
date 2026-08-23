#include "Algorithm.hpp"
#include "RandomArray.hpp"

Algorithm::Algorithm(int size) {
	this->size = size;
	arr = RandomArray::generateArray(size);

	numSwaps = 0;
	numComparisons = 0;
	finished = false;
}

const int* Algorithm::getArr() {
	return arr;
}

bool Algorithm::isFinished() {
	return finished;
}

int Algorithm::getNumSwaps() {
	return numSwaps;
}

int Algorithm::getNumComparisons() {
	return numComparisons;
}