#pragma once
#include "Algorithm.hpp"

class InsertionSort : public Algorithm {
public:
	InsertionSort(int size, std::string timeComplexity);
	void step() override;
private:
	int i;
	int j;
	int key;
	bool inserting;
};