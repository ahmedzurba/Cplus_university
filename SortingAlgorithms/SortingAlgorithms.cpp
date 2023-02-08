#include "SortingAlgorithms.h"

/**
*/
void SortingAlgorithms::InsertionSort(long *data, long size)
{
	// assume the first element as sorted start from the secound
		for (long firstun = 1; firstun<size; firstun++){
			long item = data[firstun];
			long current = firstun;
			for (; data[current - 1]>item&&current>0; current--){
				data[current] = data[current - 1];
			}
			data[current] = item;
		}
	
}

/**
*/
void merge1(long *data, long first, long mid, long last){
	long temp[11];
	long first1 = first, last1 = mid, first2 = mid + 1, last2 = last;
	long index = first1;

	while ((first1 <= last1) && (first2 <= last2)){
		if (data[first1] <= data[first2]){
			temp[index] = data[first1];
			first1++;
		}
		else{
			temp[index] = data[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1){
		temp[index] = data[first1];
		first1++;
		index++;
	}
	while (first2 <= last2){
		temp[index] = data[first2];
		first2++;
		index++;
	}
	for (index = first; index <= last; index++)
		data[index] = temp[index];
}


void SortingAlgorithms::MergeSort(long *data, long first, long last)
{

	
		if (first<last){
			long mid = first + (last - first) / 2;
			MergeSort(data, first, mid);
			MergeSort(data, mid + 1, last);
			merge1(data, first, mid, last);
		}
	
}

/**
*/
void swap(long& i, long& j)
{
	int temp = i;
	i = j;
	j = temp;
}
void sortmedian(long a[], long first, long mid, long last){
	if (a[first]>a[mid])
		swap(a[first], a[mid]);
	if (a[mid]>a[last])
		swap(a[mid], a[last]);
	if (a[first]>a[mid])
		swap(a[first], a[mid]);
}
long pivots(long a[], long first, long last){
	long mid = first + (last - first) / 2;
	sortmedian(a, first, mid, last);
	// now the middle eleminte is our pivot
	swap(a[mid], a[last - 1]);
	long pivotin = last - 1;
	long pivot = a[pivotin];

	long right = last - 2, left = first + 1;
	bool done = false;
	while (!done){
		while (a[left]<pivot)
			left++;
		while (a[right]>pivot)
			right--;

		if (left<right){
			swap(a[left], a[right]);
			left++;
			right--;
		}
		else done = true;
	}
	swap(a[pivotin], a[left]);
	pivotin = left;
	return pivotin;
}

void SortingAlgorithms::QuickSort(long *data, long first, long last)
{
	
	///////////////////////////////////////////////////////////////////////////////
	

	
		if (last - first + 1<4){
			InsertionSort(data, last - first + 1);
		}
		else{

			long pivotin = pivots(data, first, last);
			QuickSort(data, first, pivotin - 1);
			QuickSort(data, pivotin + 1, last);
		}
	
}

/**
*/
void SortingAlgorithms::RadixSort(long *data, long size)
{
}
