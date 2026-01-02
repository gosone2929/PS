#include <iostream>

using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        auto visited = vector<bool>(10000, false);
        for (const auto n: nums) {
            if (visited[n]) {
                return  n;
            }
            visited[n] = true;
        }
        return -1;
    }
};