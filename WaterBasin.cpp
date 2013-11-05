// WaterBasin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <assert.h>

void FillUpMap(std::map<int, size_t>& map, int curr, int max)
{
	for (int i = curr; i < max; ++i)
		map[i] = map[i] + 1;
}

// Better then original because can read input from cin or stream.
int FindBasinSizeOneWay(int arr[], const int size)
{
	if (size < 3) 
		return 0;

	int max = arr[0], prev = arr[0];
	int nBasin = 0;
	std::map<int, size_t> map;

	for (size_t i = 1; i < size; prev = arr[i], ++i)
	{
		if (arr[i] > max)
			max = arr[i];

		FillUpMap(map, arr[i], max);

		if (prev < arr[i])
		{
			for (int j=prev; j<arr[i]; ++j)
			{
				nBasin += map[j];
				map[j] = 0;
			}
		}
	}

	return nBasin;
}

int FindBasinSize(int arr[], const int size)
{
	if (size < 3) 
		return 0;


	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int LEN(9);
	int arr[LEN] = {2,5,1,2,3,4,7,7,6};
	int arr1[LEN] = {1,4,2,1,5,0,4,4,5};
	int arr2[LEN+1] = {2,5,1,3,1,2,1,7,7,6};
	int arr3[] = {1,2,3,1,5,1,3,1,7,1,7,1,3,1,5,3,1,1};
	assert(FindBasinSizeOneWay(arr, LEN) == 10);
	assert(FindBasinSizeOneWay(arr1, LEN) == 12);
	assert(FindBasinSizeOneWay(arr2, LEN+1) == 17);
	assert(FindBasinSizeOneWay(arr3, 18) == 28);

// 	assert(FindBasinSize(arr, LEN) == 10);
// 	assert(FindBasinSize(arr1, LEN) == 12);
// 	assert(FindBasinSize(arr2, LEN+1) == 17);
// 	assert(FindBasinSize(arr3, 18) == 28);

	return 0;
}

