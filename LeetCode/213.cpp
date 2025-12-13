#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = vector(nums.size(), 0);
        if (nums.size() <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        // 맨 앞집을 털고, 맨 뒷집을 안털기
        dp[0] = nums[0];
        for (int i = 2; i < nums.size() - 1; i += 1) {
            dp[i] = max(dp[i - 2], dp[i]);
            if (i >= 3) {
                dp[i] = max(dp[i], dp[i - 3]);
            }
            dp[i] += nums[i];
        }
        // 맨 앞집을 안털고, 맨 뒷집을 털기

        vector<int> dp2 = vector(nums.size(), 0);
        dp2[1] = nums[1];
        dp2[2] = nums[2];
        for (int i = 3; i < nums.size(); i += 1) {
            dp2[i] = max(dp2[i - 2], dp2[i - 3]) + nums[i];
        }
        
        int dp1MaxValue = *max_element(dp.end() - 3, dp.end());
        int dp2MaxValue = *max_element(dp2.end() - 3, dp2.end());

        for (auto x: dp) cout << x << " "; cout << endl;
        for (auto x: dp2) cout << x << " "; cout << endl;
        return max(dp1MaxValue, dp2MaxValue);
    }
};

int main() {
    auto v = vector({1,7,9,2});
    auto x = Solution().rob(v);
    cout << x << endl;
}