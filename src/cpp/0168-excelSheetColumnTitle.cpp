#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
