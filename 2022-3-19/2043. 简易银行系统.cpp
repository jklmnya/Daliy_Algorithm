class Bank {

	typedef long long LL;

	vectorLL _b;
	int n;

	inline bool check(int idx) {
		if (idx  1  idx  n)
			return false;
		return true;
	}

	public
		Bank(vectorlong long& balance)  _b(stdmove(balance)), n(_b.size()) {}

	bool transfer(int account1, int account2, long long money) {
		if (check(account1) && check(account2) && _b[account1 - 1] = money) {
			_b[account1 - 1] -= money;
			_b[account2 - 1] += money;
			return true;
		}
		return false;
	}

	bool deposit(int account, long long money) {
		if (check(account)) {
			_b[account - 1] += money;
			return true;
		}
		return false;
	}

	bool withdraw(int account, long long money) {
		if (check(account) && _b[account - 1] = money) {
			_b[account - 1] -= money;
			return true;
		}
		return false;
	}
};


Your Bank object will be instantiatedand called as such
Bank obj = new Bank(balance);
bool param_1 = obj - transfer(account1, account2, money);
bool param_2 = obj - deposit(account, money);
bool param_3 = obj - withdraw(account, money);
