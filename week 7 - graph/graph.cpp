#include <iostream>
#include <queue>
bool isCheck(int* a[], int n)
{
	int* b = new int[n]; 
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	}
	
	for (int j = 0; j < n; ++j)
	{
		if (!b[j]) 
		{
			++count;
			if (count == 2) return false;
			std::queue<int> v; v.push(j);
			while (!v.empty())
			{
				for (int i = 0; i < n; ++i)
				{
					if (a[v.front()][i] && !b[i])
					{
						v.push(i);
						b[i] = v.front();
					}

				}


				v.pop();
			}
		}
	}
	delete[] b;
	return true;
}
void printCGraph(int* a[], int n)
{
	int* b = new int[n];
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	}
	for (int j = 0; j < n; ++j)
	{
		if (!b[j]) 
		{
			std::queue<int> v; v.push(j);
			while (!v.empty())
			{
				for (int i = 0; i < n; ++i)
				{
					if (a[v.front()][i] && !b[i])
					{
						v.push(i);
						b[i] = v.front();
						std::cout << i << " ";
					}

				}
				v.pop();
			}
			std::cout << "\n";
		}
		
	}
}