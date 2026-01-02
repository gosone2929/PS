#include <iostream>

using namespace std;


class Solution {
public:

    string nsquareSolution(string s) {
        if (s.empty()) {
            return "";
        }
        auto expandFromCenter = [](string s, int left, int right) {
            while (left >= 0 and right < s.size() and s[left] == s[right]) {
                left -= 1;
                right += 1;
            }

            return right - left - 1;
        };
        
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i += 1) {
            int odd = expandFromCenter(s, i, i);
            int even = expandFromCenter(s, i, i + 1);

            int curMax = max(odd, even);
            if ((right - left) < curMax) {
                left = i - (curMax - 1) / 2;
                right = i + (curMax + 1) / 2;
            }
        }
        return s.substr(left, right - left);
    }
    string longestPalindrome(string s) {
        return nsquareSolution(s);
    }
};

int main() {
    cout << Solution().longestPalindrome("abac");
}

//  cbabad
// dababc