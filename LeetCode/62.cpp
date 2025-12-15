#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int m = m - 1;
        int n = n - 1;
        if (m < n) {
            swap(m, n);
        }
        int ans = 1;
        for(int i = 1; i <= n; i += 1) {
            ans = ans * (m + n - i + 1) / (i);
        }
        return ans;
    }
};