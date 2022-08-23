void preOrder(Node *root) {

    if (!root) return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);


    }