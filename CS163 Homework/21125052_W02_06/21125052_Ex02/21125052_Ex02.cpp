class MyHashSet {
public:
    struct node
    {
        int val;
        node* ptr = nullptr;
        node(int val)
        {
            this->val = val;
        }
    };
    int getKey(int key)
    {
        return key % 101;
    }
    node* a[101];
    MyHashSet() {
        for (int i = 0; i < 101; ++i)
            a[i] = nullptr;
    }

    void add(int key) {
        int number = getKey(key);
        node* pcur = a[number];
        if (pcur)
        {
            while (pcur->ptr && pcur->val != key)
                pcur = pcur->ptr;
            if (!pcur->ptr && pcur->val!=key)
            {
                pcur->ptr = new node(key);
            }
        }
        else {
            a[number] = new node(key);
        }
    }

    void remove(int key) {
        int number = getKey(key);
        node* pcur = a[number];
        node* dummy = new node(-1);
        dummy->ptr = pcur;
        pcur = dummy;
        while (pcur->ptr)
        {
            if (pcur->ptr->val == key)
            {
                node* temp = pcur->ptr;
                pcur->ptr = pcur->ptr->ptr;
                delete temp;
                a[number] = dummy->ptr;
                return;
            }
            pcur = pcur->ptr;
        }
    }

    bool contains(int key) {
        node* pcur = a[getKey(key)];
        while (pcur)
        {
            if (pcur->val == key)
                return true;
            pcur = pcur->ptr;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */