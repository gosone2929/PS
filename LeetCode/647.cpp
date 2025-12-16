#include <iostream>

using namespace std;

class Solution {
private:
    int getCountOfPalindromicStringFromCeter(int left, int right, string s) {
        int current = 0;
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            left -= 1;
            right += 1;
            current += 1;
        }
        return current;
    }
public:
    int countSubstrings(string s) {
        int answer = 0;
        for (int index = 0; index < s.size(); index += 1) {
            answer += getCountOfPalindromicStringFromCeter(index, index, s);
            answer += getCountOfPalindromicStringFromCeter(index, index + 1, s);
        }
        return answer;
    }
};