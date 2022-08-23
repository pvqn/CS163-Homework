#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
void printCGraph(int* a[], int n)
{
	int* b = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	}
	for (int j = 0; j < n; ++j)
	{
		if (!b[j])
		{
			std::vector<int> vertices;
			std::queue<int> v; v.push(j);
			vertices.push_back(j);
			while (!v.empty())
			{
				for (int i = 0; i < n; ++i)
				{
					if (a[v.front()][i] && !b[i])
					{
						v.push(i);
						b[i] = 1;
						vertices.push_back(i);
					}

				}
				v.pop();
			}
			std::ofstream fout; fout.open("Output.txt", std::ios::app);
			fout << vertices.size() << "\n";
			for (int i = 0; i < vertices.size(); ++i)
				fout << vertices[i]+1 << " ";
			fout << "\n";
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
			fin >> a[i][j];
	fin.close();

	printCGraph(a, n);

	for (int i = 0; i < n; ++i)
		delete[]a[i];
	delete[]a;
}