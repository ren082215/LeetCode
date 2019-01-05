class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) {
            m[word.size()].push_back(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (string str : m[word.size()]) {
            int cnt = 0, i = 0;
            for (; i < word.size(); ++i) {
                if (word[i] == str[i]) continue;
                if (word[i] != str[i] && cnt == 1) break; 
                ++cnt;
            }
            if (i == word.size() && cnt == 1) return true;
        }
        return false;
    }

private:
    unordered_map<int, vector<string>> m;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
