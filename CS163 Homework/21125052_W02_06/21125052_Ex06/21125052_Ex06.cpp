#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		vector<int> a[10001];
		int money, size; cin >> money >> size;
			
		for (int i = 0; i < size; ++i)
		{
		
			int t; cin >> t;
			a[t].push_back(i);
		}
		for (int i = 0; i < 10001; ++i)
		{
			if (a[i].size())
			{
				if (money-i>0 && a[money - i].size())
				{
					if (money - i == i)
					{
						cout << ++a[i][0] << " " << ++a[i][1] << "\n";
					}
					else
					{
						if (a[i][0]>a[money-i][0])
						cout << ++a[money-i][0] << " " << ++a[i][0] << "\n";
						else
							cout << ++a[i][0] << " " << ++a[money-i][0] << "\n";
					}

					break;
				}
			}
		}
	}
	return 0;
}