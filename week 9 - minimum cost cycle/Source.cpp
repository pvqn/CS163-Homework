#include <iostream>
#include <fstream>
#include <vector>
int findMin(bool* visited, int** a, int n, int *key)
{
	int min = INT_MAX, position;
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false && key[i] < min)
		{
			min = key[i]; position = i;
		}
	}
	return position;
}
void Prim(int** a, bool* visited, int* path,int *key, int n)
{	
	for (int i = 0; i < n; ++i)
		key[i] = INT_MAX;
	key[0] = 0;
	path[0] = -1;
	for (int i = 0; i < n; ++i)
	{
		int position = findMin(visited, ia, n, key);
		visited[position] = true;
		for (int j=0; j<n;++j)
			if (a[position][j] && visited[j] == false && a[position][j] < key[j])
			{
				path[j] = position;
				key[j] = a[position][j];
			}
	}
}
int main()
{
	int** a = nullptr;
	bool* visited;
	int* path;
	int n;
	std::ifstream fin;
	fin.open("input.txt");
	fin >> n;
	a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> a[i][j];
	fin.close();
	visited = new bool[n];
	path = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		path[i] = -1;
	}
}