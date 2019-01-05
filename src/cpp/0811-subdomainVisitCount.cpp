class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string, int> subdomainCnt;
        for (string cpdomain : cpdomains) {
            int spaceIdx = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, spaceIdx));
            string rem = cpdomain.substr(spaceIdx + 1);
            for (int i = 0; i < rem.size(); ++i) {
                if (rem[i] == '.') {
                    subdomainCnt[rem.substr(i + 1)] += cnt;
                }
            }
            subdomainCnt[rem] += cnt;
        }
        for (auto a : subdomainCnt) {
            res.push_back(to_string(a.second) + " " + a.first);
        }
        return res;
    }
};
