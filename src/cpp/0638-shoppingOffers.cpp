class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size();
        for (int i = 0; i < n; ++i) {
            res += price[i] * needs[i];
        }
        for (auto offer : special) {
            bool isValid = true;
            for (int j = 0; j < n; ++j) {
                if (needs[j] - offer[j] < 0) isValid = false;
                needs[j] -= offer[j];
            }
            if (isValid) {
                res = min(res, shoppingOffers(price, special, needs) + offer.back());
            }
            for (int j = 0; j < n; ++j) {
                needs[j] += offer[j];
            }
        }
        return res;
    }
};
