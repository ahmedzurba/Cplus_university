#pragma once
#include <random>
#include <climits>
#include <iostream>

class RandomNumberGenerator
{
public:
	RandomNumberGenerator(long size);
	~RandomNumberGenerator();
	void display();
	long * generate(long min, long max);
	long * generate();
	long * getData();
	long getSize();

private:
	long * data;
	long size;

	
};


