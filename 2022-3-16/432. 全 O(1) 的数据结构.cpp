class AllOne {

    unordered_map<string, int> v1;
    map<int, unordered_set<string>> v2;

public:
    AllOne() { }
    
    void inc(string key) {
        bool f = v1.count(key);
        if (f) {
            v2[v1[key]].erase(key);
            if (v2[v1[key]].size() == 0)
                v2.erase(v1[key]);
            ++v1[key];
            v2[v1[key]].insert(move(key));
        } else {
            ++v1[key];
            v2[v1[key]].insert(move(key));
        }
    }
    
    void dec(string key) {
        v2[v1[key]].erase(key);
        if (v2[v1[key]].size() == 0)
            v2.erase(v1[key]);
        if (--v1[key] == 0) {
            v1.erase(key);
        } else {
            v2[v1[key]].insert(move(key));
        }  
    }
    
    string getMaxKey() {
        if (v2.size() && (v2.rbegin()->second).size() > 0)
            return *(v2.rbegin()->second).begin();
        else
            return "";
    }
    
    string getMinKey() {
        if (v2.size() && (v2.begin()->second).size() > 0)
            return *(v2.begin()->second).begin();
        else
            return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */