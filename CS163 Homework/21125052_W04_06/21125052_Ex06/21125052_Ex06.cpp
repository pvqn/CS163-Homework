#include <iostream>
#include <math.h>
void primeTable(bool Prime[], int N)
{
	for (int i = 2; i <= N; i++) {
		Prime[i] = true;
	}
	for (int i = 2; i <= N; i++) {
		if (Prime[i] == true) {
			for (int j = 2 * i; j <= N; j += i) {
				Prime[j] = false;
			}
		}
	}
}
int main()
{
	long long n;
	std::cin >> n;
	bool Prime[1000001];
	primeTable(Prime, 1000001);
	while (n--)
	{
		long long t; std::cin >> t;
		if (t == 1 || t == 2) std::cout << "NO \n";
		else
		{
			long long x = sqrt(t);
			if (Prime[x] && x*x==t) std::cout << "YES \n"; else std::cout << "NO \n";
		}
	}
	return 0;
}