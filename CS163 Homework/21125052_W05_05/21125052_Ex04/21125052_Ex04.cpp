/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <stack>
 void traverse(TreeNode* root, std::stack<int> &q, int k)
{
	if (!root) return;
	if (q.size() > k) return;
	traverse(root->left,q,k);
	if (q.size() == k) return;
	if (q.size() > k) return;
	q.push(root->val);
	if (q.size() == k) return;
	if (q.size() > k) return;
	traverse(root->right,q,k);
	if (q.size() == k) return;
}

int Solution::kthsmallest(TreeNode* A, int B) {
    std::stack<int>q;
	traverse(A, q, B);
	return q.top();
}