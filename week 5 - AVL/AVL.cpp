#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <fstream>
struct node
{
	int val;
	int height = 0;
	int balance = 0;
	node* left = nullptr;
	node* right = nullptr;
};
int height(node* head) 
{
	if (head == NULL) return 0;
	return head->height;
}
void calculate_height(node* &cur)
{
	if (!cur->left && !cur->right)
		return;
	else
		if (cur->left && !cur->right)
		{
			
			cur->height = cur->left->height +1;
			cur->balance =-cur->height;
		}
	else
			if (cur->right && !cur->left)
			{
				
				cur->height = cur->right->height + 1;
				cur->balance = cur->height;
			}
		else
		{
				cur->height = std::max(cur->right->height, cur->left->height)+1;
				cur->balance = cur->right->height - cur->left->height;
		}
}
void left_rotate(node* &head)
{
	node* temp = head;
	node* newhead = temp->right;
	temp->right = newhead->left;
	newhead->left = temp;
	if (!temp->left && !temp->right)
		temp->height = 0;
	else
		temp->height = 1 + std::max(height(temp->left), height(temp->right));
	if (!newhead->left && !newhead->right)
		newhead->height = 0;
	else	newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));
	head = newhead;

	
}
void right_rotate(node* &head)
{
	node* temp = head;
	node* newhead = temp->left;
	temp->left = newhead->right;
	newhead->right = temp;
	if (!temp->left && !temp->right)
		temp->height = 0;
	else
		temp->height = 1 + std::max(height(temp->left), height(temp->right));
	if (!newhead->left && !newhead->right)
		newhead->height = 0;
	else	newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));
	head = newhead;

}
void rebalance(node* &cur)
{
	if (cur->balance == 2)
	{
		if (cur->right->balance >0)
		{
			left_rotate(cur);
		}
		else
		{
			right_rotate(cur->right);
			left_rotate(cur);
		}
	}
	else
		if (cur->balance == -2)
		{
			if (cur->left->balance < 0)
			{
				right_rotate(cur);
			}
			else
			{
				left_rotate(cur->left);
				right_rotate(cur);
			}
		}	
}
void insert_helper(int val, node* &root)
{	

	
	if (root->val < val)
	{
		if (root->right)
			insert_helper(val, root->right);
		else
		{
			root->right = new node;
			root->right->val = val;
			
		}
	}
	else
		if (root->val > val)
	{
		if (root->left)
			insert_helper(val, root->left);
		else
		{
			root->left = new node;
			root->left->val = val;
			
		}
	}
	calculate_height(root);
	if (abs(root->balance) == 2)
	{
		rebalance(root);
		//insert_helper(val, root);
		
	}
	

}
void printBT(const std::string& prefix, node* root, bool isLeft)
{
	if (root != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "L--");

		// print the value of the node
		std::cout << root->val << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), root->left, true);
		printBT(prefix + (isLeft ? "|   " : "    "), root->right, false);
	}
}
void printBT(node* root)
{
	printBT("", root, false);
}
void insert(int val, node*& root)
{
	if (!root)
	{
		root = new node;
		root->val=val;
		std::cout << val << " is added \n";
		return;
	}
	else
		insert_helper(val, root);
	printBT(root);
	std::cout << val << " is added \n";
}
void deleteTree(node* head)
{
	if (!head) return;
	deleteTree(head->left);
	delete head->left;
	deleteTree(head->right);
	delete head->right;
}
void traverse(node* root, std::queue<int>& q)
{
	if (!root) return;
	traverse(root->left, q);
	q.push(root->val);
	traverse(root->right, q);
}
int main()
{
	node* root = nullptr;
	std::ifstream fin;
	int t;
	fin.open("Input.txt");
	while (fin >> t)
	{
		insert(t, root);
	}
	fin.close();
	/*insert(10, root);
	insert(85, root);
	insert(15, root);
	insert(70, root);
	insert(20, root);
	insert(60, root);
	insert(30, root);
	insert(50, root);
	insert(65, root);
	insert(80, root);
	insert(90, root);
	insert(40, root);
	insert(5, root);
	insert(55, root);*/
	printBT(root);
	std::queue<int> cur;
	traverse(root, cur);
	std::ofstream fout;
	fout.open("Output.txt");
	while (!cur.empty())
	{
		fout << cur.front() << " ";
		cur.pop();
	}
	fout.close();
	deleteTree(root);
}