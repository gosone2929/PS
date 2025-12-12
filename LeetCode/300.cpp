#include <iostream>
using namespace std;

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> rv(nums);
        reverse(rv.begin(), rv.end());
        vector<int> v = {rv[0]};

        for(auto val: rv) {
            for (auto t: v) cout << t << " " ; cout << endl;
            if (v.size() < 2) {
                if (val < v.back()) {
                    v.push_back(val);
                }else {
                    v.pop_back();
                    v.push_back(val);
                }
                continue;
            }else if (val < v.back()) {
                v.push_back(val);
                continue;
            }
            
            

            int left = -1, right = int(v.size());
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (v[mid] < val) {
                    right = mid;
                }else {
                    left = mid;
                }
            }
            if (left != -1 and v[left] == val) {
                continue;
            }

            v[right] = val;
        }
        
        return v.size();
    }
};
int main() {
    auto x = vector({3, 1, 2});
    auto p = Solution().lengthOfLIS(x);
    cout << p << endl;
}
