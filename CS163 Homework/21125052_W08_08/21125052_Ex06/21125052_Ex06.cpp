#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
void mergesort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	int size1 = mid - left + 1;
	int size2 = right - mid;
	int* array1 = new int[size1];
	int* array2 = new int[size2];

	for (int i = 0; i < size1; ++i)
		array1[i] = a[left + i];
	for (int i = 0; i < size2; ++i)
		array2[i] = a[mid + i + 1];
	int i = left;
	int iLeft = 0;
	int iRight = 0;
	while (iLeft < size1 && iRight < size2)
	{
		
		if (array1[iLeft] <= array2[iRight])
		{
			a[i] = array1[iLeft];
			++iLeft;
		}
		else
			{
				a[i] = array2[iRight];
				++iRight;
			}
		++i;
	}
	while (iLeft < size1)
	{
		
		a[i] = array1[iLeft];
		++iLeft;
		++i;
	}
	while (iRight < size2)
	{
		a[i] = array2[iRight];
		++iRight;
		++i;
	}
}
int main()
{
	std::ifstream fin;
	int a[10000];
	fin.open("random.txt");
	for (int i = 0; i < 10000; ++i)
		fin >> a[i];
	fin.close();
	auto start = high_resolution_clock::now();
	mergesort(a, 0, 10000 - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;
}