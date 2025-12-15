#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 1;
        int left = 0;
        int right = 0;
        if (s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> hash = {{s[left],  1}};
        while (right < s.size()) {
            // move right maximum;
            while (right + 1 < s.size() and hash[s[right + 1]] == 0) {
                right += 1;
                hash[s[right]] += 1;
            }
            answer = max(answer, right - left + 1);

            // move duplicated char;
            right += 1;
            hash[s[right]] += 1;

            // move left minimum;
            while (left <= right) {
                hash[s[left]] -= 1;
                left += 1;
                if (hash[s[left - 1]] == 1){
                    break;
                }
            }
            if (right < left) {
                right = left;
            }
        }
        return answer;
    }
};

int main() {
    string mys = "";
    cout << Solution().lengthOfLongestSubstring(mys) << endl;
}