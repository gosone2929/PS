#include <iostream>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (nums.front() < nums.back()) {
        return nums.front();
    }
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        int leftVal = nums[left], rightVal = nums[right], midVal = nums[mid];

        if (leftVal < midVal) {
            left = mid;
        }else {
            right = mid;
        }
    }
    return nums[right];
}