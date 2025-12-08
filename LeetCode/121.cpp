#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> d = {};
        int answer = INTMAX_MAX;
        for (int i = 0; i < prices.size(); i ++) {
            auto price = prices[i];
            if (d.empty()) {
                d.push_back(price);
                continue;
            }
            if (d.front() < price) {
                answer = answer < price - d.front() ? answer : price - d.front();
            }
            while (!d.empty() && price < d.back()) {
                d.pop_back();
            }
            d.push_back(price);
        }
    }
};