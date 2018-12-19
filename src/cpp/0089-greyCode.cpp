#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int N = pow(2,n);
        for(int i = 0; i < N; i++) result.push_back(i>>1 ^ i);
        return result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
