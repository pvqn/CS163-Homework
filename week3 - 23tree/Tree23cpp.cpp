/*#include <fstream>
#include <iostream>
using namespace std;

class Node {
  int *keys;
  int t;
  Node **C;
  int n;
  bool leaf;

   public:
  Node(int _t, bool _leaf);

  void insertNonFull(int k);
  void splitChild(int i, Node *y);
  void traverse();

  friend class BTree;
};

class BTree {
  Node *root;
  int t;

   public:
  BTree(int _t) {
    root = NULL;
    t = _t;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  void insert(int k);
};

Node::Node(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new Node *[2 * t];

  n = 0;
}

void Node::traverse() {
    ofstream fout;
   
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    fout.open("Output.txt", ios::app);
    std::cout << " " << keys[i];
    fout << " " << keys[i];
    fout.close();
  }

  if (leaf == false)
    C[i]->traverse();
}


void BTree::insert(int k) {
  if (root == NULL) {
    root = new Node(t, true);
    root->keys[0] = k;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      Node *s = new Node(t, false);

      s->C[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k);

      root = s;
    } else
      root->insertNonFull(k);
  }
}


void Node::insertNonFull(int k) {
  int i = n - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }

    keys[i + 1] = k;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;

    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);

      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k);
  }
}

void Node::splitChild(int i, Node *y) {
  Node *z = new Node(y->t, y->leaf);
  z->n = t - 1;

  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  C[i + 1] = z;

  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  keys[i] = y->keys[t - 1];
  n = n + 1;
}

int main() {
  BTree t(3);
  t.insert(8);
  t.insert(9);
  t.insert(10);
  t.insert(11);
  t.insert(15);
  t.insert(16);
  t.insert(17);
  t.insert(18);
  t.insert(20);
  t.insert(23);

  cout << "The B-tree is: ";
  t.traverse();
}
*/
//
//  TernarySearchTree.hpp
//  TST
//

#ifndef TernarySearchTree_hpp
#define TernarySearchTree_hpp

#include <queue>
#include <string>
#include <stdio.h>


struct TreeNode {
    char data;
    std::string def;

    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;

    TreeNode() : data(), def(""), left(nullptr), mid(nullptr), right(nullptr) {};

    TreeNode(char& _data, std::string _def) : data(_data), def(_def), left(nullptr), mid(nullptr), right(nullptr) {};

};

class TernarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int index, std::string& s, std::string& def) {
        if (index == s.length()) return nullptr;

        if (!root) {
            root = new TreeNode(s[index], ((index == s.length() - 1) ? def : ""));
            root->mid = insert(root->mid, index + 1, s, def);
            return root;
        }

        if (root->data == s[index]) root->mid = insert(root->mid, index + 1, s, def);

        if (root->data > s[index]) root->left = insert(root->left, index, s, def);

        if (root->data < s[index]) root->right = insert(root->right, index, s, def);

        return root;
    }
    int deleteNode(TreeNode*& root, int index, std::string s)
    {
        if (!root)
            return 0;
        if (s[index + 1] == '\0')
        {
            //if the string is in the tst
            if (!root->def.empty())
            {
                return (!root->left && !root->right && !root->mid);
            }
            else return 0;
        }
        else
        {
            if (s[index] < root->data)
                return deleteNode(root->left, index, s);
            else
                if (s[index] < root->data)
                    return deleteNode(root->right, index, s);
                else
                    if (s[index] == root->data)
                    {
                        if (deleteNode(root->mid, index + 1, s))
                        {
                            delete root->mid;
                            root->mid = nullptr;
                            // delete root if root doesnt have children
                            return root->def.empty() && (!root->left && !root->mid && !root->right);
                        }
                    }
        }
        return 0;
    }

public:
    TernarySearchTree() : root(nullptr) {};

    void insert(std::string key, std::string def) {
        root = insert(root, 0, key, def);
    }

    void erase(std::string key) {
        deleteNode(root, 0, key);
    }

    /*TreeNode* search(string key) {

    }

    void update(string key, string def) {

    }**/

    ~TernarySearchTree() {
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode*& t = q.front(); q.pop();
            if (t->left) q.push(t->left);
            if (t->mid) q.push(t->mid);
            if (t->right) q.push(t->right);
            delete t;
        }
    }
};

#endif /* TernarySearchTree_hpp */
