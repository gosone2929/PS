#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dp = {};
    int dfs(int v) {
        if (dp[v] != -1) {
            return dp[v];
        }

        int left = dfs(v - 2);
        int right = dfs(v - 1);
        dp[v] = left + right;
        return dp[v];
    }
    int climbStairs(int n) {
        dp = vector(n + 1, -1);
        if (n == 1){
            return 1;
        }else if (n == 2) {
            return 2;
        }
        dp[1] = 1;
        dp[2] = 2;

        
        return dfs(n);
    }
};

int main() {
    auto output = Solution().climbStairs(1);

    cout << output << endl;
}

