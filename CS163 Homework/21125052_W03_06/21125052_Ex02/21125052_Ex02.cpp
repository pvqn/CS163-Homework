

Node* insert(Node* &phead, int val)
{
    if (!phead)
    {
        phead = new Node(val);
        //phead->data = val;
        return phead;
    }
    Node* ptemp = phead;
    while (true)
    {
        
        if (ptemp->data < val)
        {
            if (!ptemp->right)
            {
                ptemp->right = new Node(val);
                ptemp = ptemp->right;
                ptemp->data = val;
                return phead;
            }
            else
            {
                ptemp = ptemp->right;
            }
        }
        if (ptemp->data > val)
        {
            if (!ptemp->left)
            {
                ptemp->left = new Node(val);
                ptemp = ptemp->left;
                ptemp->data = val;
                return phead;
            }
            else
            {
                ptemp = ptemp->left;
            }
        }
        else
        if (ptemp->data==val) return phead;
    }
}


