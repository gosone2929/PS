#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin() + m, nums1.end());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 and j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j -= 1;

            }else {
                nums1[k] = nums1[j];
                i -=1;
            }
            k -= 1;
        }

        while (i > )
    }

};