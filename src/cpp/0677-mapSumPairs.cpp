class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        int diff = val - m[key].first, n = key.size();
        m[key].first = val;
        for (int i = n - 1; i > 0; --i) {
            m[key.substr(0, i)].second += diff;
        }
    }
    
    int sum(string prefix) {
        return m[prefix].first + m[prefix].second;
    }

private:
    unordered_map<string, pair<int, int>> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
