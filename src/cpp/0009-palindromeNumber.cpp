#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        return reverse(x) == x;
    }
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
