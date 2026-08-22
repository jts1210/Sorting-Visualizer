#include "RandomArray.hpp"
#include <random>

int* RandomArray::generateArray(int numElements) {
	int* arr = new int[numElements];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(1, 100);

	for (int i = 0; i < numElements; i++) {
		arr[i] = distrib(gen);
	}

	return arr;
}