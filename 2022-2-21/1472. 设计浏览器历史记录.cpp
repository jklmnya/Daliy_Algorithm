class BrowserHistory {

    int len, idx;
    vector<string> his;

public:
    BrowserHistory(string homepage) : len(1), idx(0) {
        his.push_back(move(homepage));
    }
    
    void visit(string url) {
        if (idx < his.size() - 1) {
            his[idx + 1] = move(url);
        } else {
            his.push_back(move(url));
        }
        ++idx;
        len = idx + 1;
    }
    
    string back(int steps) {
        if (idx < steps)
            idx = 0;
        else
            idx -= steps;
        return his[idx];
    }
    
    string forward(int steps) {
        if (idx + steps >= len)
            idx = len - 1;
        else
            idx += steps;
        return his[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */