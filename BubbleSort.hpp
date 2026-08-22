#pragma once

class BubbleSort {
public:
	BubbleSort(int size);
	void step();
	int getI();
	int getJ();
	const int* getArr();
	bool isFinished();
	int getNumSwaps();
	int getNumComparions();
private:
	int numSwaps;
	int numComparisons;
	int i;
	int j;
	int size;
	int* arr;
	bool finished;
};