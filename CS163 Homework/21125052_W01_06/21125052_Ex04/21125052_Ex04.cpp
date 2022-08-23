#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>a, count;
	int n; cin >> n;
	while (n--)
	{
		int t;
		cin >> t; a.push_back(t);
		if (a.size()<=1 || a[a.size() - 1] == a[a.size() - 2])
		{
			if (count.empty())
			{
				count.push_back(1);
			}
			else
				++count[count.size() - 1];
		}
		else
			if (a.empty() || a[a.size() - 1] != a[a.size() - 2])
				count.push_back(1);

	}
	int max = -1;
	for (int i = 0; i < count.size(); ++i)
	{
		if (i != 0)
		{
			int t = min(count[i], count[i-1]);
			if (t > max) max = t;
		}
	}
	cout << max * 2;
}