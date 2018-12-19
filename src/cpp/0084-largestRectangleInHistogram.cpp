#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int maxRect = 0;
        stack<int> stack;
        for (unsigned i = 0; i <= heights.size(); )
        {
            if (stack.empty() || i < heights.size() && heights[i] >= heights[stack.top()])
            {
                stack.push(i++);
                continue;
            }

            const int currentHeight = heights[stack.top()];
            stack.pop();
            const int rect = currentHeight * (i - (stack.empty() ? -1 : stack.top()) - 1);
            if (rect > maxRect)
            {
                maxRect = rect;
            }
        }
        return maxRect;
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
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().largestRectangleArea(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
