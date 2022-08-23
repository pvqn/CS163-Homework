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
    #include <queue>
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {std::queue<TreeNode*> result;
	result.push(root);
	while (!result.empty())
	{
		TreeNode* temp = result.front(); result.pop();
        if (temp->left || temp->right )
            {
                TreeNode* temp1 = temp->left;
                temp->left = temp->right;
                temp->right = temp1;
            }
		if (temp->left) result.push(temp->left);
		if (temp->right) result.push(temp->right);
	}}
	//traveseBFSnLR(root);
	return root;

    }
};