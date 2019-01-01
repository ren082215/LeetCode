#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// DP
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        vector<int> dp = {num[0], max(num[0], num[1])};
        for (int i = 2; i < num.size(); ++i) {
            dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
