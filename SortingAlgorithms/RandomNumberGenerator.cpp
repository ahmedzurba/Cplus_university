#include "RandomNumberGenerator.h"

/**
*/
RandomNumberGenerator::RandomNumberGenerator(long n)
{
	data = new long[n];
	for (long i=0; i<n; i++)
		data[i] = 0L;

	size = n;

}

/**
*/
RandomNumberGenerator::~RandomNumberGenerator(void)
{
	delete[] data;
	data = nullptr;
	size = 0;

}

/**
*/
long * RandomNumberGenerator::generate(long min, long max)
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator : Mersenne twister random number engine
    std::uniform_int_distribution<> distr(min, max); // define the range

	for (long i=0; i<size; i++)
		data[i] = distr(eng);

	return data;
}

/**
*/
long * RandomNumberGenerator::generate()
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator : Mersenne twister random number engine
    std::uniform_int_distribution<> distr(LONG_MIN, LONG_MAX); // define the range

	for (long i=0; i<size; i++)
		data[i] = distr(eng);

	return data;
}

/**
*/
void RandomNumberGenerator::display()
{

	for(long i=0; i<size; i++)
		std::cout << data[i] << " " ;
	std::cout << std::endl;
}

/**
*/
long * RandomNumberGenerator::getData()
{
	return data;
}

/**
*/
long RandomNumberGenerator::getSize()
{
	return size;
}
