#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> hash = {};
        int left = 0;

        for (char curChar: t) {
            hash[curChar] += 1;
        }
        int ansLeft = 0, ansRight = s.size() - 1;
        int flagCount = hash.size();

        for (int right = 0; right < s.size(); right += 1) {
            // cout  << left << ", " << right << endl;
            // for( auto [key, value]: hash) {
            //     cout << key << ":" << value << ", ";
            // }
            // cout << endl;
            char rightChar = s[right];
            if (not hash.count(rightChar)) {
                continue;
            }

            hash[rightChar] -= 1;
            if (hash[rightChar] == 0) {
                flagCount -= 1;
            }
            // 기준 충족 X
            if (flagCount != 0) {
                continue;
            }
            
            // move left
            while (not hash.count(s[left]) or hash[s[left]] < 0) {
                if (hash.count(s[left])) {
                    hash[s[left]] += 1;
                }
                left += 1;
            }
            // cout << "컨디션 충족" << left << ", " << right << endl;
            if ((ansRight - ansLeft) > (right - left)) {
                ansRight = right;
                ansLeft = left;
            }
        }

        return flagCount != 0 ? "" : s.substr(ansLeft, ansRight - ansLeft + 1);
    }
};

int main() {
    cout << Solution().minWindow("aba", "ab") << endl;
}