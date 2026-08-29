#pragma once

#include <string>
#include <vector>

class Algorithm {
public:
	Algorithm(int size, std::string timeComplexity);
	virtual void step() = 0;
	virtual const std::vector<int>& getArr();
	virtual bool isFinished();
	virtual int getNumSwaps();
	virtual int getNumComparisons();
	std::string getTimeComplexity();
protected:
	int numSwaps;
	int numComparisons;
	int size;
	std::vector<int> arr;
	bool finished;
	std::string timeComplexity;
};