#include <iostream>
#include <math.h>
#include <string>
using namespace std;

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
int findKey(int n, int size)
{
	return n % size;
}
void generate(int a[], int size)
{
	for (int i = 0; i < size; ++i)
		a[i] = -1;
}
void add(int a[], int size)
{
	int i = -1;
	while (i)
	{
		cout << "enter the number: ";
		cin >> i;
		if (!i) break;
		int position = findKey(i, size);
		if (position!= size && a[position] != -1)
		{	
			while (a[position] != -1)
			{
				++position;
			}
			if (position != size )
				a[position] = i;
			else cout << "could not generate key";
		}
		else
			a[position] = i;
	}
}
string searchkey(int i, int a[], int size)
{
	int position = findKey(i, size);
	if (a[position] != i)
	{
		while (position != size && a[position] != i)
			++position;
		if (position != size) return "found, " + to_string(position);
		else return "not found";
	}
	else
		return "found, " + to_string(position);
}
int main()
{
	int* a;
	cout << "enter the number of elements: ";
	int n; cin >> n;
	n = findprime(2 * n);
	a = new int[n];
	generate(a,n);
	add(a, n);
	cout << searchkey(1, a, n);
	//for (int i = 0; i < n; ++i)
		//cout << a[i] << " ";
	return 0;
}