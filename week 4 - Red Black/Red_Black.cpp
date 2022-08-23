#define red 0
#define black 1
#define double_black 2
#include <iostream>
#include <string>

struct TreeNode
{
	// 0 red 1 black 2 double black
	int key;
	int color=0;
	TreeNode* left=nullptr;
	TreeNode* right = nullptr;
	TreeNode* parent = nullptr;
	//std::string* pWord;
};
void coutColor(int key)
{
	//std::string result;
	switch (key)
	{
	case 0:
		std::cout<< "red";
		break;
	case 1:
		std::cout<<"black";
		break;
	default:
		break;
	}
	//return result;
}
void printBT(const std::string& prefix, TreeNode* root, bool isLeft)
{
	if (root != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "L--");

		// print the value of the node
		std::cout << root->key << " "; coutColor(root->color); std::cout<< std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), root->left, true);
		printBT(prefix + (isLeft ? "│   " : "    "), root->right, false);
	}
}
void printBT(TreeNode* root)
{
	printBT("", root, false);
}
void setColor(TreeNode* &cur, int color)
{
	if (!cur) return;
	cur->color = color;
}
bool isDoubleBlack(TreeNode* cur)
{
	if (cur->color < 2) return false;
	return true;
}
int getColor(TreeNode* cur)
{
	if (!cur) return black;
	return cur->color;
}
TreeNode* findCandidate(TreeNode* cur)
{
	while (cur->left != nullptr)
		cur = cur->left;
	return cur;
}
TreeNode* deleteTree(TreeNode* &cur, int key)
{
	if (cur == nullptr)
		return cur;
	else
		if (cur->key < key)
			return deleteTree(cur->right, key);
		else
			if (cur->key > key)
				return deleteTree(cur->left, key);
			else if (!cur->left || !cur->right)
				return cur;
	TreeNode* temp = findCandidate(cur->right);
	cur->key = temp->key;
	return deleteTree(cur->right, temp->key);
}
void rotateRight(TreeNode* &cur, TreeNode*& root)
{
	//rotate pointer
	TreeNode* temp = cur->left;
	cur->left = temp->right;
	
	//rotate parent
	if (cur->left != nullptr)
		cur->left->parent = cur;
	temp->parent = cur->parent;
	if (cur->parent == nullptr)
		root = temp;
	else
	if (cur->parent->left == cur)
		cur->parent->left = temp;
	else cur->parent->right = temp;

	//rotate pointer
	temp->right = cur;
	cur->parent = temp;
}
void rotateLeft(TreeNode*& cur, TreeNode*&root)
{
	//rotate pointer
	TreeNode* temp = cur->right;
	cur->right = temp->left;

	//rotate parent
	if (cur->right != nullptr)
		cur->right->parent = cur;
	temp->parent = cur->parent;
	if (cur->parent == nullptr)
		root = temp;
	else
	if (cur->parent->right == cur)
		cur->parent->right = temp;
	else cur->parent->left = temp;

	//rotate pointer
	temp->left = cur;
	cur->parent = temp;
}
void delete_helper(TreeNode*& cur, TreeNode*& root)
{
	if (!cur) return;
	if (cur == root) {
		root = nullptr;
		return;
	}
	if (getColor(cur) == red || getColor(cur->left) == red || getColor(cur->right) == red)
	{
		TreeNode* temp = nullptr;
		if (!cur->left && cur->right) temp = cur->right;
		else if (!cur->right && cur->left) temp = cur->left;
		if (cur == cur->parent->left)
			cur->parent->left = temp;
		else cur->parent->right = temp;
		if (temp)
		{
			temp->parent = cur->parent;
			setColor(temp, black);
			delete cur;
		}
	}
	else
	{
		TreeNode* uncle = nullptr;
		TreeNode* parent = nullptr;
		TreeNode* temp = cur;
		setColor(temp, double_black);
		while (temp != root && getColor(temp) != double_black)
		{
			if (temp == temp->parent->right)
			{
				parent = temp->parent;
				uncle = parent->left;
				if (getColor(uncle) == red)
				{
					setColor(uncle, black);
					setColor(parent, red);
					rotateRight(parent,root);
				}
				else 
					if (getColor(uncle) == black && getColor(uncle->left) == black)
					{
						setColor(uncle, red);
						setColor(temp, black);
						if (getColor(parent) == red)
						{
							setColor(parent, black);
						}
						else if (parent != root)
						{
							setColor(parent, double_black);
							temp = parent;
						}
					}
					else
						if (getColor(uncle) == black && getColor(uncle->left) == red)
						{
							setColor(uncle->left, black);
							setColor(temp, black);
							setColor(uncle, parent->color);
							setColor(parent, black);
							rotateRight(parent,root);
							break;
						}
						
			}
			else
			{
				parent = temp->parent;
				uncle = parent->right;
				if (getColor(uncle) == red)
				{
					setColor(uncle, black);
					setColor(parent, red);
					rotateLeft(parent,root);
				}
				else
					if (getColor(uncle) == black && getColor(uncle->right) == black)
					{
						setColor(uncle, red);
						setColor(temp, black);
						if (getColor(parent) == red)
						{
							setColor(parent, black);
						}
						else if (parent != root)
						{
							setColor(parent, double_black);
							temp = parent;
						}
					}
					else
						if (getColor(uncle) == black && getColor(uncle->right) == red)
						{
							setColor(uncle->right, black);
							setColor(temp, black);
							setColor(uncle, parent->color);
							setColor(parent, black);
							rotateLeft(parent,root);
							break;
						}
			}
		}
		if (temp == temp->parent->left)
			temp->parent->left = nullptr;
		else temp->parent->right = nullptr;
		delete cur;
		setColor(root, black);
	}	
}
void deleteValueRB(TreeNode*& root, int key)
{
	TreeNode* temp = deleteTree(root, key);
	delete_helper(temp, root);
}
TreeNode* insertTree(TreeNode*& phead, int key)
{
	if (!phead)
	{
		phead = new TreeNode;
		phead->key=key;
		return phead;
	}
	TreeNode* ptemp = phead;
	while (true)
	{

		if (ptemp->key < key)
		{
			if (!ptemp->right)
			{
				ptemp->right = new TreeNode;
				//ptemp = ptemp->right;
				ptemp->right->key = key;
				ptemp->right->parent = ptemp;
				ptemp = ptemp->right;
				break;
			}
			else
			{
				ptemp = ptemp->right;
			}
		}
		if (ptemp->key > key)
		{
			if (!ptemp->left)
			{
				ptemp->left = new TreeNode;
				//ptemp = ptemp->left;
				ptemp->left->key = key;
				ptemp->left->parent = ptemp;
				ptemp = ptemp->left;
				break;
			}
			else
			{
				ptemp = ptemp->left;
			}
		}
		
		//	if (ptemp->key == key) return;
	}
	return ptemp;
}
void insert_helper(TreeNode*& cur, TreeNode*&root)
{
	if (cur != root)
	{
		TreeNode* parent = cur->parent;
		if (getColor(parent) == black)
		{
			return;
		}
		else
		{
			TreeNode* grandparent = parent->parent;
			if (parent->left == cur)
			{
				TreeNode* uncle = nullptr;
				if (grandparent->left == parent)
					uncle = grandparent->right;
				else uncle = grandparent->left;
				if (getColor(uncle) == black)
				{

					//setColor(parent, black);
					//setColor(grandparent, red);
					if (grandparent->right == parent)
					{
						rotateRight(parent, root);
						parent = parent->parent;
						grandparent = parent->parent;
						int color = parent->color;
						grandparent->color = parent->color;
						rotateLeft(grandparent, root);
						setColor(root, black);
						return;
						
					}
					int color = parent->color;
					grandparent->color = parent->color;
					parent->color = color;
					rotateRight(grandparent, root);

				}
				else
					if (getColor(uncle) == red)
					{
						setColor(parent, black);
						setColor(uncle, black);
						setColor(grandparent, red);
						insert_helper(grandparent, root);
					}
			}
			else {
				TreeNode* uncle = nullptr;
				if (grandparent->left == parent)
					uncle = grandparent->right;
				else uncle = grandparent->left;
				if (getColor(uncle) == black)
				{
					setColor(parent, black);
					setColor(grandparent, red);
					if (grandparent->left == parent)
					{
						rotateLeft(parent,root);
						parent = parent->parent;
						grandparent = parent->parent;
						int color = parent->color;
						grandparent->color = parent->color;
						rotateRight(grandparent,root);
						setColor(root, black);
						return;
					}
					int color = parent->color;
					grandparent->color = parent->color;
					parent->color = color;
					rotateLeft(grandparent,root);
					//rotateLeft(grandparent);
				}
				else
					if (getColor(uncle) == red)
					{
						setColor(parent, black);
						setColor(uncle, black);
						setColor(grandparent, red);
						insert_helper(grandparent, root);
					}
			}
		}
	}
	setColor(root, black);
}
void insertValueRB(TreeNode*& root, int key)
{
	TreeNode* temp = insertTree(root, key);
	insert_helper(temp, root);
	//printBT(root);
	std::cout << key << " is added \n";
}
void deleteWholeTree(TreeNode*& head)
{
	if (!head) return;
	deleteWholeTree(head->left);
	deleteWholeTree(head->right);
	delete head;
	head = nullptr;
}

int main()
{
	TreeNode* root = nullptr;
	insertValueRB(root, 10);
	insertValueRB(root, 85);
	insertValueRB(root, 15);
	insertValueRB(root, 70);
	insertValueRB(root, 20);
	insertValueRB(root, 60);
	insertValueRB(root, 30);
	insertValueRB(root, 50);
	insertValueRB(root, 65);
	insertValueRB(root, 80);
	insertValueRB(root, 90);
	insertValueRB(root, 40);
	insertValueRB(root, 5);
	insertValueRB(root, 55);
	//deleteValueRB(root,40);
	std::cout << "\n";
	printBT(root);
	std::cout << "\n";
	deleteValueRB(root, 30);
	printBT(root);
	deleteWholeTree(root);
	return 0;
}