#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.begin(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           if(n==0)
            return ;
        for(int i=m+n-1;i>0;i--){
          if(n-1>=0 && m-1>=0){
                if(nums1[m-1]>=nums2[n-1]){
                std::swap(nums1[i],nums1[m-1]);
                m--;
            }
            else{
                std::swap(nums1[i],nums2[n-1]);
                n--;
            }
          }
        else
            break;
        }
        if(m-1<0)
        {
            for(int i=0;i<n;i++)
                nums1[i]=nums2[i];
        }
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        Solution().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}
