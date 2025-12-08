#include <iostream>
using namespace std;


int maxProduct(vector<int>& nums) {
    vector<vector<int>> dp = {};
    dp.push_back({nums[0], nums[0], nums[0]});

    for (int index = 1; index < nums.size() ; index += 1) {
        int currentValue = nums[index];
        auto prev = dp[index - 1];
        auto minMaxValue = minmax({prev[0] * currentValue, prev[1] * currentValue, prev[2] * currentValue});
        auto nextValue = minMaxValue.second;
        auto thirdValue = minMaxValue.first;
        dp.push_back({currentValue, nextValue, thirdValue});
    }
    int answer = nums[0];
    for (auto x: dp) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
        auto tempMax = max({x[0], x[1], x[2]});
        if (answer < tempMax) {
            answer = tempMax;
        }
    }

    return answer;
}

int main() {
    auto v = vector({1,0,-1,2,3,-5,-2});
    auto x = maxProduct(v);
    cout << x << endl;
}