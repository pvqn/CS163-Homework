#include <iostream>
#include <vector>
int calculate(int n)
{
	if (n % 2) return (n - 1) / 2;
	else return (n- 2) / 2;
}
void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void upheap(std::vector<int>& cur)
{
	int position_old=cur.size()-1, position_new = calculate(cur.size() - 1);
	while (position_old && cur[position_new] < cur[position_old])
	{
		swap(cur[position_new], cur[position_old]);
		position_old = position_new;
		position_new = calculate(position_old);
	}

}
void insert(std::vector<int>& cur, int n)
{
	cur.push_back(n);
	upheap(cur);
}
int getPosition(int position_cur, std::vector<int>& cur, int n)
{
	int position1 = position_cur * 2 + 1;
	int position2 = position_cur * 2 + 2;
	if (position2 <= n)
	{
		if (cur[position1] < cur[position2]) return position2;
		else return position1;
	}
	if (position1 <= n) return position1;
	return 0;
}
void downheap(std::vector<int>& cur, int n)
{
	if (n==0) return;
	int position_cur = 0;
	int position = getPosition(position_cur, cur,n );
	while (position)
	{
		if (cur[position_cur] < cur[position]) swap(cur[position_cur], cur[position]); else return;
		position_cur = position;
		position = getPosition(position_cur, cur,n);
	}

}
void deleteRoot(std::vector<int>& cur, int &n)
{
	swap(cur[0], cur[n]);
	--n;
	downheap(cur,n);
	
}
void HeapSort(std::vector<int>& cur)
{
	int n = cur.size() - 1;
	while (n)
	{
		deleteRoot(cur, n);
		
	}
}
int main()
{
	std::vector<int> heap;
	
	insert(heap, 13);
	insert(heap, 9);
	insert(heap, 5);
	insert(heap, 6);
	insert(heap, 0);
	insert(heap, 10);
	insert(heap, 1);
	insert(heap, 12);
	for (int i = 0; i < heap.size(); ++i)
		std::cout << heap[i] << " ";
	std::cout << "\n";
	HeapSort(heap);
	for (int i = 0; i < heap.size(); ++i)
		std::cout << heap[i] << " ";
	return 0;
}