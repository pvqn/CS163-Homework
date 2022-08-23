#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
struct node
{
	int i;
	node* ptr = nullptr;
};
bool isPrime(int n)
{
	bool check = false;
	for (int i = 2; i < sqrt(n); ++i)
		if (!(n % i)) return check;
	check = true;
	return check;
}
int findprime(int doubleN)
{
	while (true)
	{
		if (isPrime(doubleN))
		{
			return doubleN;
		}
		else
			++doubleN;
	}
}
void generate(node** a, int n)
{
	n = findprime(2 * n);
	a = new node*[n];
	for (int i = 0; i < n; ++i)
		a[i] = nullptr;
}
int findKey(int n, int size)
{
	return n % size;
}
void add(node **a, int size)
{
	int i = -1;
	while (i)
	{
		cout << "enter the number: ";
		cin >> i;
		if (!i) break;
		int position = findKey(i, size);
		node* temp = new node;
		temp->i = i;
		temp->ptr = a[position];
		a[position] = temp;
		delete temp;

	}
}
node* searchkey(int i, node **a, int size)
{
	int position = findKey(i, size);
	node* phead = a[position];
	while (phead)
	{
		if (phead->i == i)
		{
			return phead;
		}
		else
			phead = phead->ptr;
	}
}
void deletedata(node** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		while (a[i])
		{
			node* temp = a[i];
			a[i] = a[i]->ptr;
			delete temp;
		}
	}
	delete []a;
}
int main()
{

}