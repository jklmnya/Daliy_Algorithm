int vv[200010];

class RandomizedSet {

    unordered_map<int, int> ss; // val -> idx
    int f = 0;

public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (ss.count(val))
            return false;
        ss.emplace(val, f);
        vv[f] = val;
        ++f;
        return true;
    }
    
    bool remove(int val) {
        if (!ss.count(val))
            return false;
        int idx = ss[val];
        vv[idx] = vv[f - 1];
        ss[vv[idx]] = idx;
        --f;
        ss.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % f;
        return vv[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */