#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) 
    {
        int len = nums.size();
        if (len < 2)
            return len;

        int i = 0;
        int j = 1;
        int tmp;

        while (j<len)
        {

            while (j<len && (nums[j] != nums[i]))
            {
                i++;
                j++;
            }
            while (j < len && nums[j] == nums[i])
                j++;

            if (j - i > 2)
            {
                if (j == len)
                    return i+2;
                tmp = j;
                while (tmp < len)
                {
                    nums[tmp-(j-i)+2] = nums[tmp];
                    tmp++;
                }
                len = len - (j - i)+2;
                i = i + 1;
                j = i + 1;
            }
            else
            {
                if (j == len)
                    return len;
                i=j;
                j++;
            }
        }
        return len;
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}
