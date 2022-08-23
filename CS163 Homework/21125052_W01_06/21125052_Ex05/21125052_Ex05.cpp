#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		long long a, b;
		cin >> a >> b;
		if (a > b)
		{
			long long t = a;
			a = b;
			b = t;
		}
		if (a * 2 <= b)
		{
			cout << a << endl;
		}
		else cout << (a + b) / 3 <<endl;
			
		
	}
	return 0;
}