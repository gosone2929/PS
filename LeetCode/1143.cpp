#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1s = text1.size();
        int t2s = text2.size();
        vector<vector<int>> dp = vector(t1s, vector(t2s, 0));

        dp[0][0] = text1[0] == text2[0];
        for (int j = 1; j < t2s; j += 1) {
            dp[0][j] = max(int(text1[0]==text2[j]), dp[0][j - 1]);
        }
        for (int i = 1; i < t1s; i += 1) {
            dp[i][0] = max(int(text1[i]==text2[0]), dp[i - 1][0]);
        }
        for (int i = 1 ; i < t1s; i += 1) {
            for (int j = 1; j < t2s; j += 1) {
                int w = text1[i] == text2[j];
                if (w == 1) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                
            }
        }

        for (auto row: dp) {
            for (auto val: row) {
                cout << val << " ";
            }
            cout << endl;
        }
        
        return dp[t1s - 1][t2s - 1];
    }
    
};

int main() {
    auto t = Solution().longestCommonSubsequence("ezupkr", "ubmrapg");
    cout << t << endl;
}