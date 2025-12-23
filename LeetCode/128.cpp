#include <iostream>
#include  <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet = unordered_set<int>(nums.begin(), nums.end());
        int answer = 0;
        for (int num: numSet) {
            if (!numSet.count(num - 1)) {
                int length = 1;
                while (numSet.count(num + length)) {
                    length += 1;
                }
                answer = max(answer, length);
            }
        }
        return answer;
    }
};