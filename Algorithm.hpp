#pragma once

#include <string>

class Algorithm {
public:
	Algorithm(int size, std::string timeComplexity);
	virtual void step() = 0;
	virtual const int* getArr();
	virtual bool isFinished();
	virtual int getNumSwaps();
	virtual int getNumComparisons();
	std::string getTimeComplexity();
protected:
	int numSwaps;
	int numComparisons;
	int size;
	int* arr;
	bool finished;
	std::string timeComplexity;
};