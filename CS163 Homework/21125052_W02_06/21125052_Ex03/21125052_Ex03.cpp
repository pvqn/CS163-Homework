class MyHashSet {
public:
    int a[104729];
    int getKey(int key)
    {
        return key % 104729;
    }
    MyHashSet() {
        for (int i = 0; i < 104729; ++i)
            a[i] = -1;
    }

    void add(int key) {
        int number = getKey(key);
        if (a[number]!=-1)
        {
            while (a[number]!=-1 && a[number]!=key)
                ++number;
            if (a[number] == key) return;
            a[number] = key;
        }
        else a[number] = key;
    }

    void remove(int key) {
        int number = getKey(key);
        if (a[number] != key)
        {
            while (number < 104729 && a[number] != key)
                ++number;
            if (number < 104729)
            a[number] = 0;
        }
        else a[number] = 0;
    }

    bool contains(int key) {
        int number = getKey(key);
        if (a[number] != key)
        {
            while (a[number]!=-1 && a[number] != key)
                ++number;
            if (a[number]!=-1) return true;
            else return false;
        }
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */