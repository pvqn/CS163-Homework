#include <iostream>
#include <fstream>
void DFS(int** a, int* visited, int vertex, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[vertex][i] && visited[i] != 1)
		{
			visited[i] = 1;
			std::ofstream fout;
			fout.open("Output.txt", std::ios::app);
			fout << i + 1 << " ";
			fout.close();
			DFS(a, visited, i, n);
			fout.open("Output.txt", std::ios::app);
			fout << i + 1 << " ";
			fout.close();
		}
	}
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
			a[i][j] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int t; fin >> t;
			if (!a[j][i])
			{  
				a[i][j]=t; 
			}
		}
	fin.close();

	int* visited; visited = new int[n];
	for (int i = 0; i < n; ++i)
		visited[i] = 0;

	std::cout << "Enter the start vertex: "; int vertex; std::cin >> vertex;

	std::ofstream fout;

	fout.open("Output.txt", std::ios::app);
	fout << vertex + 1 << " ";
	fout.close();

	DFS(a, visited, vertex, n);

	fout.open("Output.txt", std::ios::app);
	fout << vertex + 1 << " ";
	fout.close();
	for (int i = 0; i < n; ++i)
		delete[]a[i];
	delete[]a;
}