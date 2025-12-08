#include <iostream>

using namespace std;
int maxSubArray(vector<int>& nums) {
    auto dp = vector<tuple<int, int, int>>();

    dp.push_back({nums[0], nums[0], nums[0]});
    for (int index = 1; index < nums.size(); index += 1) {
        auto currentValue = nums[index];
        auto v0 = get<0>(dp[index - 1]);
        auto v1 = get<1>(dp[index - 1]);
        auto tempMax = max(v0, v1);
        dp.push_back({currentValue,  tempMax + currentValue, max(currentValue, tempMax + currentValue)});
    }

    auto maxValue = *max_element(dp.begin(), dp.end(), [](auto a, auto b) {
        return get<2>(a) < get<2>(b);
    });
    return get<2>(maxValue);
};