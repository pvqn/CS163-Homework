#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
#include <vector>
#include <algorithm>
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
struct xy
{
    int val;
    int x=0, y=0;
    
};
   static bool compare(xy cur, xy curr)
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
void traverseTree(Node* root, xy cur, std::vector<xy> &map)
{
    if (!root) return;
    cur.val = root->data;
    map.push_back(cur);
    xy left = cur; xy right = cur; ++right.x; --left.x; ++right.y, ++left.y;
    traverseTree(root->left, left, map);
    traverseTree(root->right, right, map);
    
}
void topView(Node* root)
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

}; //End of Solution