#pragma once

class Algorithm {
public:
	Algorithm(int size);
	virtual void step() = 0;
	virtual const int* getArr();
	virtual bool isFinished();
	virtual int getNumSwaps();
	virtual int getNumComparisons();
protected:
	int numSwaps;
	int numComparisons;
	int size;
	int* arr;
	bool finished;
};