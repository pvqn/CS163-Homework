#include <iostream>
#include <vector>
#include <algorithm>
long long NCR(long long n, long long r)
{
	if (r == 0) return 1;
 
	if (r > n / 2) return NCR(n, n - r);
 
	long long res = 1;
 
	for (long k = 1; k <= r; ++k)
	{
		res *= n - k + 1;
		res /= k;
	}
 
	return res;
}
int main()
{
	long long n; std::cin >> n;
	while (n--)
	{
		std::vector<long long> a;
		long long n1; std::cin >> n1;
		for (long long i = 0; i < n1; ++i)
		{
			long long t; std::cin >> t;
			a.push_back(t - i);
		}
		std::sort(a.begin(), a.end());
		long long count = 0;
		long long i = 0;
		while (i<a.size())
		{
			if (i)
			{
				long long count1 = 0;
				if (a[i] == a[i - 1])
				{
					++count1;
					while (i < a.size() && a[i] == a[i - 1])
					{
						++count1;
						++i;
					}
					count += NCR(count1, 2);
				}
				else ++i;
			}
			else ++i;
		}
		std::cout << count << "\n";
	}
}