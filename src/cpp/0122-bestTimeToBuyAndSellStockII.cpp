#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int buyPrice = prices[0];
        int buyPricePoi =0;
        int profit =0;
        while(buyPricePoi < prices.size()-1){
            if(prices[buyPricePoi+1] > buyPrice){
                profit += prices[buyPricePoi+1] - buyPrice;
                buyPrice = prices[buyPricePoi+1];
                buyPricePoi ++;;
            }else{
                buyPrice = prices[++buyPricePoi];
            }
        }
    return profit;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
