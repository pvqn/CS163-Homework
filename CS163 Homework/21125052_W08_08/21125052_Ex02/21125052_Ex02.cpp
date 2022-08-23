#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
int findmin(std::vector<int>& distance, std::vector<int> &visited)
{
	int min = INT_MAX;
	int min_position = 0;
	for (int i=0; i< distance.size(); ++i)
		if (min > distance[i] && !visited[i]) {
			min = distance[i];
			min_position = i;
		}
	visited[min_position] = 1;
	return min_position;
}
void printOutShortestPath(std::vector<int> path, int position_cur)
{
	if (position_cur)
	
		printOutShortestPath(path, path[position_cur]);
	
	std::cout << position_cur+1 << " ";
}
void dijsktra(int** a, int n,  int destination)
{
	std::vector<int>distance, path, visited;
	for (int i = 0; i < n; ++i)
		distance.push_back(INT_MAX);
	for (int i = 0; i < n; ++i)
	{
		path.push_back(0);
		visited.push_back(0);
	}
	distance[0] = 0;
	while (true)
	{
		int i = findmin(distance, visited);
		if (i == destination-1) break;
		for (int j=0; j<n;++j)
			if (a[i][j])
			if (distance[j] >= (distance[i] + a[i][j]))
			{
				distance[j] = distance[i] + a[i][j];
				path[j] = i;
			}
	}
	printOutShortestPath(path, destination-1);
}

int main()
{
	std::ifstream fin;
	fin.open("input.txt");
	int n; fin >> n;
	int **a;
	a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> a[i][j];
	fin.close();
	dijsktra(a, n, n);
	for (int i = 0; i < n; ++i)
		delete[]a[i];
	delete[]a;
}