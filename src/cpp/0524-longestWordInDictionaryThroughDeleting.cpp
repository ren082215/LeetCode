class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b){
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        for (string str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size()) return str;
        }
        return "";
    }
};
