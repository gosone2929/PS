#include <iostream>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> um = {};
    for (auto x: nums) {
        if (um.count(x)) {
            return true;
        }
        um[x] = true;
    }
    return false;
}