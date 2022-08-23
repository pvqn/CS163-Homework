/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
class Solution {
public:
    bool check(TreeNode* root1, TreeNode*root2)
    {
        if (!root1 && !root2) return 1;
        if ((!root1 && root2) || (!root2 && root1)) return 0;
        if (root1->val== root2->val)
            return check(root1->left, root2->right) && check(root1->right, root2->left);
        return 0;
    }
bool isSymmetric(TreeNode* root)
{
	return check(root->left, root->right);
}
};