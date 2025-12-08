using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <map>

class Solution {
public:
    struct MapValue{
       vector<int> value = vector<int>();
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        int n = nums.size();
        for (int i = 0; i < n; i ++){
            int curTarget = target - nums[i];

            if (d.count(curTarget)) {
                return vector({i, d[i]});
            }
            d[curTarget] = i;
        }
        return vector<int>();
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector sn(nums);
        sort(sn.begin(), sn.end());
        vector<int> result({});
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

int main() {
    auto s = Solution();

    auto v = vector({2,1,9,4,4,56,90,3});
    auto target(8);
    auto result = s.twoSum(v, target);
    for (auto x: result) {
        cout << x << endl;
    }
}