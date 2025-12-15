#include <iostream>

using namespace std;


class Solution {
public:
    unordered_map<char, char> targetLower;
    void makeMap() {
        string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lower = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < upper.size(); i += 1) {
            targetLower[upper[i]]  = lower[i];
            targetLower[lower[i]] = lower[i];
        }
        for (int i = 0; i < 10; i += 1) {
            char val = to_string(i)[0];
            targetLower[val] = val;
        }
    }
    string makeTargetLower(string s) {
        string answer = "";
        for (auto t: s) {
            if (targetLower.count(t)) {
                answer += targetLower[t];
            }
        }
        return answer;
    }
    bool isPalindrome(string s) {
        makeMap();
        string targetString = makeTargetLower(s);

        string reversetargetString = targetString;
        reverse(reversetargetString.begin(), reversetargetString.end());
        return targetString == reversetargetString;
    }
};