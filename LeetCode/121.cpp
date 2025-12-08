#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> d = {};
        int answer = -100000;
        for (int i = 0; i < prices.size(); i ++) {
            auto price = prices[i];
            if (d.empty()) {
                d.push_back(price);
                continue;
            }
            if (d.front() < price) {
                answer = answer < price - d.front() ? price - d.front(): answer;
            }
            while (!d.empty() && price < d.back()) {
                d.pop_back();
            }
            d.push_back(price);
        }
        return answer < 0 ? 0 : answer;
    }

    int sol2(vector<int>& prices) {
        int currentMin = prices[0];
        auto answer = 0;

        for (int index = 1; index < prices.size() ; index ++) {
            auto price = prices[index];
            
            if (answer < price - currentMin) {
                answer = price - currentMin;
            }
            if (price < currentMin) {
                currentMin = price;
            }
        }
        return answer;
    }
};