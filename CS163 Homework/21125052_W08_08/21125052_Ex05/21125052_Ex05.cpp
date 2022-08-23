#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
int main()
{
	std::ifstream fin;
	int a[10000];
	fin.open("random.txt");
	for (int i = 0; i < 10000; ++i)
		fin >> a[i];
	fin.close();
	auto start = high_resolution_clock::now();
	int frequency[20001]{ 0 };
	for (int i = 0; i < 10000; ++i)
		++frequency[a[i]];
	int n = 0;
	for (int i=0; i<20001;++i)
		if (frequency[i])
		{
			while (frequency[i]--)
			{
				a[n] = i;
				++n;
			}
		}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;
}