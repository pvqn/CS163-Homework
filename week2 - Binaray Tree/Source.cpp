#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
struct node
{
	int val;
	node* pleft = nullptr;
	node* pright = nullptr;
};
void insert(node* &phead, int val)
{
	if (!phead)
	{
		phead = new node;
		phead->val = val;
		return;
	}
	node* ptemp = phead;
	while (true)
	{
		
		if (ptemp->val < val)
		{
			if (!ptemp->pright)
			{
				ptemp->pright = new node;
				ptemp = ptemp->pright;
				ptemp->val = val;
				return;
			}
			else
			{
				ptemp = ptemp->pright;
			}
		}
		if (ptemp->val > val)
		{
			if (!ptemp->pleft)
			{
				ptemp->pleft = new node;
				ptemp = ptemp->pleft;
				ptemp->val = val;
				return;
			}
			else
			{
				ptemp = ptemp->pleft;
			}
		}
		else
		if (ptemp->val==val) return;
	}
}
void deleteWholeTree(node* &head)
{
	if (!head) return;
	deleteWholeTree(head->pleft);
	deleteWholeTree(head->pright);
	delete head;
	head = nullptr;
}
/*void deleteWholeTree(node*& head)
{
	deleteTree(head);
	head = nullptr;
	/*
	* if (!root)
	*	return;
	* deleteWholeTree(root->pleft);
	* deleteWholeTree(root->pright);
	* delete root;
	* rot=nullptr;
	
}
*/
void traverseDFSLnR(node* phead)
{
	if (!phead) return;                                                                                                                                                
	traverseDFSLnR(phead->pleft);
	std::cout << phead->val << " ";
	traverseDFSLnR(phead->pright);

}
void traverseDFSRnL(node* phead)
{
	if (!phead) return;
	traverseDFSRnL(phead->pright);
	std::cout << phead->val << " ";
	traverseDFSRnL(phead->pleft);

}
void printRange(node *root, int x, int y)
{
	while (!(root->val > x && root->val < y))
		if (root->val < x && root->val < y)
			root = root->pleft;
		else root = root->pright;
	traverseDFSRnL(root);
}
void traveseBFSnLR(node* phead)
{
	std::queue<node*> q;
	q.push(phead);
	while (!q.empty())
	{
		node* cur = q.front();
		if (cur->pleft)
			q.push(cur->pleft);
		if (cur->pright)
			q.push(cur->pright);
		std::cout << cur->val <<" ";
		q.pop();
	}
}
void traverseBFS(node* phead, int &k)
{
	std::queue <node*> q;
	if (!phead && k<=0) return;
	q.push(phead);
	int temp = k;
	k = 1;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			node* cur = q.front();
			if (cur->pleft)
				q.push(cur->pleft);
			if (cur->pright)
				q.push(cur->pright);
			q.pop();
		}
		++k;
		if (k == temp)
		{
			while (!q.empty())
			{
				std::cout << q.front()->val << " ";
				q.pop();
			}
			return;
		}
	}
	std::cout << "There is no level k in this tree";
}
node* findX(node* phead, int x)
{
	while (phead && x!=phead->val)
	{
		if (x > phead->val)
			phead = phead->pright;
		else
			phead = phead->pleft;
	}
	return phead;
}
void searchClosest(node* phead, int x, node* &min, int min_dis)
{
	if (!phead) return;

	while (phead)
	{
		if (phead->val == x)
		{
			min = phead;
			return;
		}
		if (abs(phead->val - x) < min_dis)
		{
			min_dis = abs(phead->val - x);
			min = phead;
		}
		if (phead->val > x)
			phead = phead->pleft;
		else phead = phead->pright;
	}
}
node* LCA(node* proot, node* first, node* second)
{
	int a, b;
	a = first->val;
	b = second->val;
	while (proot)
	{
		if (a < proot->val && b < proot->val)
			proot = proot->pleft;
		else
			if (a > proot->val && b > proot->val)
				proot = proot->pright;
			else
				return proot;
	}
	return proot;
}
void eraseNode(node* root, int k)
{
	while (root)
	{
		if (k == root->val)
		{
			break;
		}
		else if (k < root->val)
			root = root->pleft;
		else root = root->pright;
	}
	if (root)
	{
		node* temp = root;
		root = root->pright;
		while (root->pleft && root->pleft->pleft)
			root = root->pleft;
		temp->val = root->pleft->val;
		delete root->pleft;
		root->pleft = nullptr;
	}
}
void printBT(const std::string& prefix, node *root, bool isLeft)
{
	if (root != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "L--");

		// print the value of the node
		std::cout << root->val << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), root->pleft, true);
		printBT(prefix + (isLeft ? "│   " : "    "), root->pright, false);
	}
}

void printBT(node *root)
{
	printBT("", root, false);
}
void deletion(node* root, int val)
{

}
struct xy
{
	int val;
	int x=0, y=0;
	
};
void traverseTree(node* root, xy cur, std::vector<xy> &map)
{
	if (!root) return;
	cur.val = root->val;
	map.push_back(cur);
	xy left = cur; xy right = cur; ++right.x; --left.x; ++right.y, ++left.y;
	traverseTree(root->pleft, left, map);
	traverseTree(root->pright, right, map);
	
}
bool compare(xy cur, xy curr)
{
	if (cur.x < curr.x)
		return true;
	
		if (cur.x > curr.x)
			return false;
		
			if (cur.y < curr.y)
			return true;
			if (cur.y > curr.y)
				return false;
			if (cur.val < curr.val)
				return true;
			return false;
}
void topView(node* root)
{
	xy cur;
	std::vector<xy>map;
	traverseTree(root, cur, map);
	std::sort(map.begin(), map.end(), compare);
	int i = 0;
	while (i < map.size())
	{
		if (i)
		{
			if (map[i].x != map[i - 1].x)
				std::cout << map[i].val << " ";
		}
		else
			std::cout << map[i].val<< " ";
		++i;
	}
}
bool isBST(node* root)
{
	bool check1=true, check2=true;
	if (!root->pleft && !root->pright) return true;
	if (root->pleft)
		if (root->pleft->val < root->val) check1=isBST(root->pleft);
	if (root->pright)
		if (root->pright->val> root->val) check2=isBST(root->pright);
	return(check1 && check2);
}
void traverse(node* root, std::stack<int> &q, int k)
{
	if (!root) return;
	if (q.size() > k) return;
	traverse(root->pleft,q,k);
	if (q.size() == k) return;

	if (q.size() > k) return;
	q.push(root->val);
	if (q.size() == k) return;
	if (q.size() > k) return;
	traverse(root->pright,q,k);
	if (q.size() == k) return;


}
int kthsmallest(node* A, int B) {
	std::stack<int>q;
	traverse(A, q, B);
	return q.top();
}
void getValue(node* phead, std::queue<int> &result, bool con)
{
	std::queue <node*> q;
	if (!phead ) return;
	q.push(phead);
	while (!q.empty())
	{
		if (con)
		{
			node* cur = q.front();
			if (cur->pleft)
				q.push(cur->pleft);
			if (cur->pright)
				q.push(cur->pright);
			result.push(cur->val);
		}
		else
		{
			node* cur = q.front();
			if (cur->pright)
				q.push(cur->pright);
			if (cur->pleft)
				q.push(cur->pleft);
			result.push(cur->val);
		}
			q.pop();
			
		
		
	}
	//std::cout << "There is no level k in this tree";
}
bool isSymmetric(node* root)
{
	std::queue<int> cur1, cur2;
	getValue(root, cur1, 1);
	getValue(root, cur2, 0);
	if (cur1.size() == cur2.size())
	{
		while (!cur1.empty())
		{
			if (cur1.front() == cur2.front())
			{
				cur1.pop();
				cur2.pop();
			}
		}
	}
	else return 0;
	return 1;
}
int main()
{
	node* root=nullptr;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t; std::cin >> t;
		insert(root, t);
	}
	std::cout << std::endl;
	std::cout << kthsmallest(root, 2);
	//traverseDFSRnL(root);
	//std::cout << std::endl;
	//std::cout << std::endl;
	//traverseDFSLnR(root);
	//printBT(root);
	//std::cout << std::endl;
	//topView(root);
	//traveseBFSnLR(root);
	//deleteTree(root);
}