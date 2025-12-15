#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1 = {1, 2, 3};
        vector<int> v2 = {1, 2, 3};
        for (auto t: s) v1[t] += 1;
        for (auto t: t) v2[t] += 1;
        return v1 == v2;
    }
};