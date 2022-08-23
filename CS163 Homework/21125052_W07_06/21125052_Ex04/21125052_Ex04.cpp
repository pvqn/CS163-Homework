#include <iostream>
#include <fstream>
#include <queue>
void BFS(int** a, int* visited, int vertex, int n)
{
	std::queue<int> q;
	q.push(vertex);
	std::ofstream fout;
	fout.open("Output.txt");
	while (!q.empty())
	{
		fout << q.front() + 1 << " ";
		for (int i = 0; i < n; ++i)
		{
			if (a[q.front()][i] && visited[i] != 1)
			{
				visited[i] = 1;
				q.push(i);
			}
		}
		q.pop();
	}
	fout.close();
}
int main()
{
	int n; int** a;
	std::ifstream fin;

	fin.open("Input.txt");
	fin >> n;
	a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> a[i][j];
	fin.close();

	int* visited; visited = new int[n];
	for (int i = 0; i < n; ++i)
		visited[i] = 0;

	std::cout << "Enter the start vertex: "; int vertex; std::cin >> vertex;

	BFS(a, visited, vertex, n);	

	for (int i = 0; i < n; ++i)
		delete[]a[i];
	delete[]a;
}