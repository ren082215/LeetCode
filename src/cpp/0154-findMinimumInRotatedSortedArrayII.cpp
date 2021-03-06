class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1, res = nums[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                res = min(res, nums[right]);
                right = mid;
            } else ++left;
        }
        res = min(res, nums[left]);
        res = min(res, nums[right]);
        return res;
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
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
