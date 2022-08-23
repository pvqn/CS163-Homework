#include <iostream>
using namespace std;
int main()
{
	int minutes, n;
	cin >> n >> minutes;
	minutes = 4 * 60 - minutes;
	int number = 0;
	int count = 0;
	while (count <= minutes && number < n)
	{
		++number;
		count += 5 * number;
	}
	if (count == minutes || (number ==n &&count <= minutes))
		cout << number;
	else cout << number - 1;
	return 0;
}