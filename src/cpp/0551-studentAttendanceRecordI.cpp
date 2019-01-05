class Solution {
public:
    bool checkRecord(string s) {
        return (s.find("A") == string::npos || s.find("A") == s.rfind("A")) && s.find("LLL") == string::npos;
    }
};
