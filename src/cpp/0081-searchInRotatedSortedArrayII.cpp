#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
       
    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return false;
        
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums[left] == target || nums[right] == target) return true;
        
        while(left <= right) { 
            int mid = (left + right) >> 1;
            
            if(nums[mid] == target) return true;
            
            if(nums[left] <= target && nums[mid] > target) { // this would be a normal situation...
                right = mid - 1;
            } else if(nums[right] >= target && nums[mid] < target) { 
                left = mid + 1;              
            } else if(nums[right] >= target && nums[mid] > target){ 
                left++;
            } else { 
                right--;
            }
        }
        
        return false;                     
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
