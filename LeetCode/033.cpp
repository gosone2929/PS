#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // 경계값 즉시 확인
        if (target == nums[left]) return left;
        else if(target == nums[right]) return right;

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            auto leftValue = nums[left], rightValue = nums[right], midValue = nums[mid];

            // 1. 현재 구간에 회전축(Split Index)이 포함된 경우
            if (rightValue < leftValue) {
                // 타겟이 오른쪽 구간[mid ~ right]에 존재하는 3가지 조건
                if (
                    (leftValue <= midValue && midValue <= target) or  // Case 1
                    (target <= rightValue && rightValue <= midValue) or // Case 2
                    (midValue <= target && target <= rightValue)      // Case 3
                ) { 
                    left = mid;
                } else {
                    right = mid;
                }
            } 
            // 2. 현재 구간이 정상 정렬된 경우
            else { 
                if (target <= midValue) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
        }

        // 최종 수렴 후 확인
        if (target == nums[left]) return left;
        else if(target == nums[right]) return right;

        return -1;
    }
};