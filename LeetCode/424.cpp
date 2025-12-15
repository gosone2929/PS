#include <iostream>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int answer = 0;
        int curMax = 0;
        unordered_map <char, int> hash = {};

        for (int right = 0; right < s.size(); right += 1) {
            // expand right
            hash[s[right]] += 1;
            curMax = max(curMax, hash[s[right]]);

            // expand widnow
            // while (not condition) { ... }
            int length = right - left;
            if (not (length - curMax < k)) {
                hash[s[left]] -= 1;
                left += 1;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

int main() {
    auto x = Solution().characterReplacement("baaa", 0);
    cout << x << endl;
}