#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
void counting(std::vector<int>* b, int k, int *a)
{
	for (int i = 0; i < 10000; ++i)
	{
		b[(a[i] % k) / (k/10)].push_back(a[i]);
	}
}
void radix(int* a)
{
	bool check = true;
	int k = 10;
	while (check)
	{
		std::vector<int> b[10];
		counting(b, k, a);
		int n=0;
		for (int i = 0; i < 10; ++i)
		{
			if (b[i].size())
				for (int j = 0; j < b[i].size(); ++j)
				{
					a[n] = b[i][j];
					++n;
				}
		}
		if (b[0].size() == 10000) return;
		k = k * 10;
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
	radix(a);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;
}