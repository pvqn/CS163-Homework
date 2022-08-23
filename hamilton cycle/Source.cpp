#include <iostream>
#include<fstream>
bool isConnected(bool* visited, int index, int* path, int** a,int n)
{
	if (index == 0)
		return true;
	if (visited[n]== false && a[path[index - 1]][n])
		return true;
	return false;
}
bool HamiltonCycle(int* path, int n, int** a, int index, bool* visited)
{
	if (index == n)
	{ 
		if (a[path[n - 1]][path[0]])
			return true;
		else return false;
	}
	if (index == 0)
	{
		for (int i = 0; i < n; ++i)
		{
			path[i] = -1;
			visited[i] = false;

		}
		//visited[0] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		if (isConnected(visited,index,path,a,i))
		{
			
					path[index] = i;
					visited[i] = true;

					if (HamiltonCycle(path, n, a, index+1, visited))
						return true;
					else
					{
						visited[i] = false;
						path[index] = -1;
					}
		}		
	}
	return false;
}
int main()
{
	int** a=nullptr;
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
	//for (int i = 0; i < n; ++i)
	//{
		//for (int j = 0; j < n; ++j)
			//std::cout << a[i][j] << " ";
		//std::cout << std::endl;
	//}
	visited = new bool[n];
	path = new int[n];
	if (HamiltonCycle(path, n, a, 0, visited))
	{
		for (int i = 0; i < n; ++i)
			std::cout << path[i] << " ";
	}
	else std::cout << "no cycle";
}