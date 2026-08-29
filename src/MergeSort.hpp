#pragma once

#include "Algorithm.hpp"
#include <string>
#include <vector>

class MergeSort : public Algorithm {
public:
	MergeSort(int size, std::string timeComplexity);
	void step() override;
private:
	int width;
	int leftStart;
	int left, mid, right, rightEnd;
	bool merging;
	std::vector<int> temp;
};