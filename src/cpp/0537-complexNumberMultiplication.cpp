class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        auto p1 = a.find_last_of("+"), p2 = b.find_last_of("+");
        int a1 = stoi(a.substr(0, p1)), b1 = stoi(b.substr(0, p2));
        int a2 = stoi(a.substr(p1 + 1, n1 - p1 - 2));
        int b2 = stoi(b.substr(p2 + 1, n2 - p2 - 2));
        int r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
