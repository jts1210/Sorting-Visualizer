#pragma once

#include "Algorithm.hpp"

class BubbleSort : public Algorithm {
public:
	BubbleSort(int size);
	void step() override;
private:
	int i;
	int j;
};