#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int answer = 0;
        while (left < right) {
            answer = max(answer, (right - left) * min(height[left], height[right]));
            
            if (height[left] < height[right]) {    
                left += 1;
            }else {
                right -= 1;
            }
        }
        return answer;
    }
    int maxArea2(vector<int>& height) {
        auto rHeight = vector(height);
        reverse(rHeight.begin(), rHeight.end());
        return max(travel(height), travel(rHeight));
    }

    int travel(vector<int> nums) {
        int left = 0; 
        int right = nums.size() - 1;
        int answer = -1;
        while (left< right){
            int tempRight = right;
            
            while (nums[tempRight] < nums[left] and left < tempRight) {
                tempRight -= 1;
            }
            
            if (left == tempRight) {
                left += 1;
                continue;
            }
            answer = max(answer, (tempRight - left) * min(nums[tempRight], nums[left]));
            right = tempRight;
            left += 1;
        }
        return answer;
    }
};

int main() {
    auto v = vector({1,2,1});
    auto answer = Solution().maxArea(v);
    cout << answer << endl;
}