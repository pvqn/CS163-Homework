#include <iostream>
#include <fstream>
#include <time.h> 
#include <iomanip>
int main()
{
	std::ifstream fin;
	int a[10000];
	fin.open("random.txt");
	for (int i = 0; i < 10000; ++i)
		fin >> a[i];
	fin.close();
	time_t start, end;
	time(&start);
	for (int i=0;i<10000; ++i)
		for (int j=i; j<10000;++j)
		if (a[j]<a[i])
		{
			int t = a[j];
			for (int h = j; h >i; --h)
				a[h] = a[h-1];
			a[i] = t;
		}
	time(&end);
	double time_taken = double(end - start);
	std::cout << "Time taken by program is : " << std::fixed
		<< time_taken << std::setprecision(5);
	std::cout << " sec " << std::endl;

}