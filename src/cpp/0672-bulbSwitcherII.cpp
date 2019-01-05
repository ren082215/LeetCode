class Solution {
public:
    int flipLights(int n, int m) {
        n == (n <= 6) ? n : (n % 6 + 6);
        int start = (1 << n) - 1;
        unordered_set<int> s;
        queue<int> q{{start}};
        for (int i = 0; i < m; ++i) {
            int len = q.size();
            s.clear();
            for (int k = 0; k < len; ++k) {
                int t = q.front(); q.pop();
                vector<int> next{flipAll(t, n), flipEven(t, n), flipOdd(t, n), flip3k1(t, n)};
                for (int num : next) {
                    if (s.count(num)) continue;
                    q.push(num);
                    s.insert(num);
                }
            }
        }
        return q.size();
    }
    
    int flipAll(int t, int n) {
        int x = (1 << n) - 1;
        return t ^ x;
    }
    
    int flipEven(int t, int n) {
        for (int i = 0; i < n; i += 2) {
            t ^= (1 << i);
        }
        return t;
    }
    
    int flipOdd(int t, int n) {
        for (int i = 1; i < n; i += 2) {
            t ^= (1 << i);
        }
        return t;
    }
    
    int flip3k1(int t, int n) {
        for (int i = 0; i < n; i += 3) {
            t ^= (1 << i);
        }
        return t;
    }
};
