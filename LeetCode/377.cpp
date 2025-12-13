#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> tnums;
    int curVal = 0;
    int tv;
    int ans = 0;
    void dfs() {
        if (curVal == tv) {
            ans += 1;
            return;
        }
        for (int num: tnums) {
            if (curVal + num > tv) {
                continue;
            }
            curVal += num;
            dfs();
            curVal -= num;
        }

    }
    int combinationSum42(vector<int>& nums, int target) {
        tv = target;
        tnums = nums;
        dfs();
        return ans;
    }
    int combinationSum4(vector<int>& nums, int const target) {
        vector<int> dp = vector(target + 1, 0);
        vector<int> tn = {};
        for (auto num: nums) {
            if (num <= target) {
                tn.push_back(num);
            }
        }
        nums = vector(tn);
        for (auto num: nums) {
            dp[num] += 1;
        }
        
        sort(nums.begin(), nums.end());
        for (int cur = 1; cur <= target; cur += 1) {
            for (auto num: nums) {
                if (cur < num) {
                    continue;
                }
                dp[cur] += dp[cur - num];
            }
        }
        for(auto v: dp) cout << v << " ";

        return dp[target];
    }
};

int main() {
    vector<int> num = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    cout << Solution().combinationSum4(num, 999) << endl;
}