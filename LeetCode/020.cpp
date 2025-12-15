#include <iostream>
using namespace std;

class Solution {
public:
    // bracketChar, (space, weight)
    unordered_map<char, tuple<int, int, char>>  bracketAndSpaceWeight = {
        {'{', {0, 1, '}'}}, {'}', {0, -1, '{'}},
        {'(', {1, 1, ')'}}, {')', {1, -1, '('}},
        {'[', {2, 1, ']'}}, {']', {2, -1, '['}},
    };
    unordered_map<char, int> left = {
        {'{', 1},
        {'(', 1},
        {'[', 1}
    };
    bool isValid(string s) {
        vector<int> b(3, 0);
        vector<char> prev;
        for (int index = 0; index < s.size() ; index += 1) {
            auto c = s[index];
            auto [spaceIndex, w, pair] = bracketAndSpaceWeight[c];

            b[spaceIndex] += w;
            if (b[spaceIndex] < 0 ) {
                return false;
            }

            if (left.count(c)) {
                prev.push_back(c);
                continue;
            }

            if (pair != prev.back()) {
                return false;
            }
            prev.pop_back();
        }
        
        for (auto t: b) {
            if (t != 0) {
                return false;
            }
        }
        return true;
    }
};