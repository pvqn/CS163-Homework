#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
int findpivot(int* a, int left, int right)
{
	int smaller = left - 1;
	for (int i = left; i < right; ++i)
	{
		
		if (a[i] < a[right])
		{
			++smaller;
			swap(a[i], a[smaller]);
		}
	}
	swap(a[right], a[smaller + 1]);
	return smaller + 1;
}
void quicksort(int* a, int left, int right)
{
	if (left < right)
	{
		int pivot = findpivot(a, left, right);
		quicksort(a, left, pivot - 1);
		quicksort(a, pivot + 1, right);
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
	quicksort(a, 0, 10000 - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;
}