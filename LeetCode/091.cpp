#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool flag = false;
    unordered_set<string> us = {};

    int dfs(string s, int index) {
        if (s.size() <= index) {
            return 1;
        }else if (index == s.size()-1) {
            if (us.count(s.substr(index))) {
                return 1;
            }
            return 0;
        }
        int cur = 0;
        string t0 = string({s[index]});
        if (us.count(t0)) {
            cur += dfs(s, index + 1);
        }
        
        string t1 = s.substr(index, 2);
        if (us.count(t1)) {
            cur += dfs(s, index + 2);
        }
        return cur;
    }
    
    int numDecodings(string s) {
        for (int num = 1 ; num < 27; num += 1) {
            us.insert(to_string(num));
        }
        vector<int> dp = vector(s.size(), 0);
        if (not us.count(string({s[0]}))) {
            return 0;
        }
        dp[0] = 1;

        for (int index = 1; index < s.size() ; index += 1) {
            bool flag = false;
            string t0 = string({s[index]});
            if (us.count(t0)) {
                flag = true;
                dp[index] += dp[index - 1];
            }
            
            string t2 = s.substr(index - 1, 2);
            if (us.count(t2)) {
                flag = true;
                dp[index] = dp[index] + (index >= 2 ? dp[index - 2] : 1);
            }
            if (not flag) {
                return 0;
            }
        }
        return dp.back();
    }
    int numDecodings2(string s) {
    if (s.empty() || s[0] == '0') return 0;

    int prev2 = 1; // dp[i-2]
    int prev1 = 1; // dp[i-1]

    for (int i = 1; i < s.size(); i++) {
        int cur = 0;

        // 한 자리
        if (s[i] != '0') {
            cur += prev1;
        }

        // 두 자리
        if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            cur += prev2;
        }

        if (cur == 0) return 0;

        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
};

int main() {
    auto p = Solution().numDecodings("11001");
    cout << p << endl;
}