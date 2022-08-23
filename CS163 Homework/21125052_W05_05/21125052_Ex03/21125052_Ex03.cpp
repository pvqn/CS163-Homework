/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * @input B : Root pointer of the tree 
 * 
 * @Output Integer
 */
int isSameTree(treenode* A, treenode* B) { 
    if (!A && !B) return 1;
    if ((!A && B) || (!B &&A) ) return 0;
    if (A->val == B->val)
    {
        return isSameTree(A->left, B->left) && isSameTree (A->right, B->right);
    }
    return 0;
}
