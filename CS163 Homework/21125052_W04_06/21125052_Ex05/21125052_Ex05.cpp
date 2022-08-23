#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	std::vector<int> a;
	double max = -1;
	long long n, l; std::cin >> n >> l;
	while (n--)
	{
		long long t;
		std::cin >> t;
		a.push_back(t);
	}
	std::sort(a.begin(), a.end());
	for (long long i = 1; i < a.size(); ++i)
	{
		double t = (a[i] - a[i - 1]) / (2.00);
		if (max < t) max = t;
	}
	if (a[0] != 0)
	{
		double t = a[0];
		if (max < t) max = t;
	}
	if (a[a.size() - 1] != l)
	{
		double t = l - a[a.size() - 1];
		if (max < t) max = t;
	}
	std::cout << std::fixed <<max;
	return 0;
}