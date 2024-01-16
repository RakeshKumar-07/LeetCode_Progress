class RandomizedSet {
public:
    map<int, int> m;
    int size = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        m[val]++;
        size++;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        m.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        auto itr = m.begin();
        int r = rand()%size;
        for(int i=0;i<r;i++) ++itr;
        return itr->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */