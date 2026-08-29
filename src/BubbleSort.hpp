#pragma once

#include "Algorithm.hpp"
#include <string>

class BubbleSort : public Algorithm {
public:
	BubbleSort(int size, std::string timeComplexity);
	void step() override;
private:
	int i;
	int j;
};