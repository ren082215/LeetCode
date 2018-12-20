#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size(), k = 0;
        unordered_set<int> s;
        queue<int> q{{0}};
        while (!q.empty() && k < n3) {
            int len = q.size();
            for (int t = 0; t < len; ++t) {
                int i = q.front() / n3, j = q.front() % n3; q.pop();
                if (i < n1 && s1[i] == s3[k]) {
                    int key = (i + 1) * n3 + j;
                    if (!s.count(key)) {
                        s.insert(key);
                        q.push(key);
                    }
                }
                if (j < n2 && s2[j] == s3[k]) {
                    int key = i * n3 + j + 1;
                    if (!s.count(key)) {
                        s.insert(key);
                        q.push(key);
                    }
                }
            }
            ++k;
        }
        return !q.empty() && k == n3;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);
        
        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
