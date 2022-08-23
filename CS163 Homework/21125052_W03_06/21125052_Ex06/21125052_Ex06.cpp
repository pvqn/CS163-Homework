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
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int val=root->val;
        return isTrue(root, val);
    }
    bool isTrue(TreeNode* root, int val)
    {
        if (!root) return true;
        bool check1, check2;
        if (root->val==val)
        {
            check1=isTrue(root->left, val);
            check2=isTrue(root->right, val);
            return check1&&check2;
        }
        else return false;
        
    }
};