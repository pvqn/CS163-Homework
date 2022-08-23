#include <iostream>
#include <utility>
#include <vector>
#include <queue>
struct edge
{
	int length=INT_MAX;
	std::pair<int, int> vertices=std::make_pair(-1,-1);
	
};
int left(int parent, int n)
{
	int left = parent * 2 + 1;
	if (left < n) return left; else return 0;
}

int right(int parent, int n)
{
	int right = parent * 2 + 2;
	if (right < n) return right; else return 0;
}
int compare(std::vector<edge> edges, int i)
{
	int left_val = left(i, edges.size());
	int right_val = right(i, edges.size());
	if (!left_val && !right_val)return 0;
	if (left_val && right_val)
	{
		if (edges[left_val].length < edges[right_val].length) return left_val;
		else return right_val;
	}
	if (left_val) return left_val; else return right_val;
}
void swap(edge& a, edge& b)
{
	edge t = a;
	a = b;
	b = t;
}
void minHeapify(std::vector<edge>& edges,int i)
{
	int position_new = compare(edges,i);
	int position_cur = i;
	while (position_new && edges[position_cur].length > edges[position_new].length)
	{
		swap(edges[position_cur], edges[position_new]);
		position_cur = position_new;
		position_new = compare(edges, position_cur);
	}
}
void buildMinHeap(std::vector<edge>&edges)
{
	for (int i = edges.size() / 2 - 1; i >= 0; --i)
		minHeapify(edges,i);
}
void deleteRoot(std::vector<edge>& edges)
{
	swap(edges[0], edges[edges.size()-1]);
	edges.pop_back();
	minHeapify(edges, 0);
}
void insert(int** a, int n, std::vector<edge> &edges)
{
	a = { 0 };
	for (int i = 0; i < n; ++i)
		for (int j=0; j < n; ++j)
		{
			int t; std::cin >> t;
			if (!a[i][j] && t)
			{
				a[j][i] = a[i][j];
				edge temp;
				temp.length = t;
				temp.vertices.first = i;
				temp.vertices.second = j;
				edges.push_back(temp);

			}
			
		}
	
	buildMinHeap(edges);
}
int findPosition(std::vector<int>vertex, int n)
{
	for (int i = 0; i < vertex.size(); ++i) if (n == vertex[i]) return i;
	return 0;
}
bool isCycle(int **a, std::vector<int> vertex, int n)
{
	int* b = new int[vertex.size()]; 
	b = { 0 };
	int position;
	for (int j = 0; j < vertex.size(); ++j)
	{
		int position = findPosition(vertex, vertex[j]);
		if (!b[position])
		{
			std::queue<int> v; v.push(vertex[j]);
			while (!v.empty())
			{
				for (int i = j+1; i < vertex.size(); ++i)
				{
					if (a[v.front()][i])
						{
							int position1= findPosition(vertex, i);
							if(!b[position1] && position1!=position)
							{
								v.push(i);
								b[position1] = v.front(); 
							}
							else return true;
						}
					}
				v.pop();
			}
		}
	}
	delete[]b;
	return false;
	
}
void Include(std::vector<int>&vertex, edge a)
{
	if (vertex.empty())
	{
		vertex.push_back(a.vertices.first);
		vertex.push_back(a.vertices.second);
	}
	else
	{
		bool check1 = true;
		bool check2 = true;
		for (int i = 0; i < vertex.size(); ++i)
		{
			if (vertex[i] == a.vertices.first)
				check1 = false;
			if (vertex[i] == a.vertices.second)
				check2 = false;
		}
		if (check1) vertex.push_back(a.vertices.first);
		if (check2) vertex.push_back(a.vertices.second);
	}
}
int findMinimumCost_Kruskal(std::vector<edge>edges, int n, int **a)
{
	std::vector<int> vertex, result;
	while (!edges.empty())
	{
		Include(vertex, edges[0]);
		deleteRoot(edges);
		if (isCycle(a, vertex, n))
		{
			vertex.clear();
			vertex = result;
		}
	}
	int sum = 0;
	for (int i = 1; i < result.size(); ++i)
	{
		sum += a[findPosition(vertex, vertex[i])][findPosition(vertex, vertex[i - 1])];
	}
	return sum;
}
int findMinimumCost_Prim(std::vector<edge>edges, int n, int** a)
{
	edge temp;
	std::vector<int>vertex;
	Include(vertex, edges[0]);
	int sum = 0; sum += edges[0].length;
	a[edges[0].vertices.first][edges[0].vertices.second] = 0;
	a[edges[0].vertices.second][edges[0].vertices.first] = 0;
	while (vertex.size() != n)
	{
		edge temp;
		for (int i = 0; i < vertex.size(); ++i)
		{
			for (int j = 0; j < n; ++j)
				if (a[i][j] < temp.length)
				{
					temp.length = a[i][j];
					temp.vertices.first = i;
					temp.vertices.second = j;
				}
		}
		sum += temp.length;
		a[temp.vertices.first][temp.vertices.second] = 0;
		a[temp.vertices.second][temp.vertices.first] = 0;

	}
	return sum;
}