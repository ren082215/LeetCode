#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, mx = -1, start = 0;
        for (int i = gas.size() - 1; i >= 0; --i) {
            total += gas[i] - cost[i];
            if (total > mx) {
                start = i;
                mx = total;
            }
        }
        return (total < 0) ? -1 : start;
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
        vector<int> gas = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> cost = stringToIntegerVector(line);
        
        int ret = Solution().canCompleteCircuit(gas, cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
