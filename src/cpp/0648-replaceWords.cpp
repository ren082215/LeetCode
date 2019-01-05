class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res = "", t = "";
        vector<vector<string>> v(26);
        istringstream is(sentence);
        sort(dict.begin(), dict.end(), [](string &a, string &b) {return a.size() < b.size();});
        for (string word : dict) {
            v[word[0] - 'a'].push_back(word);
        }
        while (is >> t) {
            for (string word : v[t[0] - 'a']) {
                if (t.substr(0, word.size()) == word) {
                    t = word;
                    break;
                }
            }
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};
