#include "RandomArray.hpp"
#include <random>
#include <vector>

std::vector<int> RandomArray::generateArray(int numElements) {
	std::vector<int> arr;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(1, 100);

	for (int i = 0; i < numElements; i++) {
		arr.push_back(distrib(gen));
	}

	return arr;
}