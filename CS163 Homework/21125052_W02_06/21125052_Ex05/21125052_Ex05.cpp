#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct node
{
	int val = 0;
	string word;
};
int main()
{
	vector <vector<node>>dict;
	for (int i = 0; i < 1000; ++i)
	{
		vector<node> a;
		dict.push_back(a);
	}
	int n, m; cin >> n >> m;
	string word;
	if (n < m)
	{
		cout << "No";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> word;
		int sum = 0;
		for (int j = 0; j < word.length(); ++j)
			sum += (int)word[j];
		bool check = true;
		for (int j = 0; j < dict[sum].size(); ++j)
		{
			if (dict[sum][j].word == word)
			{
				check = false;
				++dict[sum][j].val;
				break;
			}
		}
		if (check)
		{
			node temp; temp.word = word; temp.val = 1;
			dict[sum].push_back(temp);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> word;
		int sum = 0;
		for (int j = 0; j < word.length(); ++j)
			sum += (int)word[j];
		bool check = true;
		for (int j = 0; j < dict[sum].size(); ++j)
		{
			if (dict[sum][j].word == word)
			{
				--dict[sum][j].val;
				if (dict[sum][j].val >= 0) check = false;
				break;
			}
		}
		if (check)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;

}