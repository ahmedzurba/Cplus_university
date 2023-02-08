#pragma once
class SortingAlgorithms
{
public:
	static void InsertionSort(long *data, long size);
	static void MergeSort(long *data, long first, long last);
	static void QuickSort(long *data, long first, long last);
	static void RadixSort(long *data, long size);
};

