class Cashier {

    int n, discount;
    int cnt = 0;

    unordered_map<int, int> vv;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for (int i = 0;i<products.size();++i)
            vv.emplace(products[i], prices[i]);
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res = 0;
        for (int i = 0;i<product.size();++i)
            res += amount[i] * vv[product[i]];
        if (++cnt == n) {
            cnt = 0;
            res -= discount * res / (double)100;
        }
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */