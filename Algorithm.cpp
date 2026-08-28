#include "Algorithm.hpp"
#include "RandomArray.hpp"
#include <string>

Algorithm::Algorithm(int size, std::string timeComplexity) {
	this->size = size;
	arr = RandomArray::generateArray(size);

	numSwaps = 0;
	numComparisons = 0;
	finished = false;
	this->timeComplexity = timeComplexity;
}

const std::vector<int>& Algorithm::getArr() {
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

std::string Algorithm::getTimeComplexity() {
	return timeComplexity;
}