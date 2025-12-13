#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        
        vector<int> dp = vector(nums.size(), 0);

        int numSize = nums.size();
        if (nums.size() <= 2) {
            int res = *max_element(nums.begin(), nums.end());
            return res;
        }
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        for(int i = 3; i < nums.size(); i += 1) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }

        return max({dp[nums.size() - 1], dp[nums.size() - 2], dp[nums.size() - 3]});
    }
};