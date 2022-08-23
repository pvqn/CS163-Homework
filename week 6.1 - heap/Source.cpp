#include <iostream>
int parent(int child)
{
	int parent;
	if (child % 2) parent=(child - 1) / 2;
	else parent=(child- 2) / 2;
	if (parent < 0) parent = 0;
	return parent;
}

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

int compare(int a[], int n, int i)
{
	int left_val = left(i, n);
	int right_val = right(i, n);
	if (!left_val && !right_val)return 0;
	if (left_val && right_val)
	{
		if (a[left_val] > a[right_val]) return left_val;
		else return right_val;
	}
	if (left_val) return left_val; else return right_val;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void maxHeapify(int a[], int n, int i)
{
	int position_new = compare(a, n, i);
	int position_cur = i;
	while (position_new && a[position_cur] < a[position_new])
	{
		swap(a[position_cur], a[position_new]);
		position_cur = position_new;
		position_new = compare(a, n, position_cur);
	}
}

void buildMaxHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
		maxHeapify(a, n, i);
}
void heapSort(int a[], int n)
{
	buildMaxHeap(a, n);
	for (int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		maxHeapify(a, i, 0);
	}
}
int main()
{
	int n;
	std::cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	heapSort(a, n);
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << " ";
}