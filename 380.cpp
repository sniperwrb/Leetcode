class RandomizedSet {
public:
	unordered_set<int> a;
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		int x = a.size();
		a.insert(val);
		return(a.size() != x);
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		int x;
		x = a.erase(val);
		return (x != 0);
	}

	/** Get a random element from the set. */
	int getRandom() {
		auto it = a.begin();
		int x = a.size();
		int y = rand() % x;
		int i;
		for (i = 0; i<y; i++)
		{
			++it;
		}
		return *it;
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/