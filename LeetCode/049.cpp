#include <iostream>

using namespace std;

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        unordered_map<string, vector<string>> stringAndMetrics;
        for (auto targetString: strs) {    
            vector<int> current(26, 0);
            for (char curChar: targetString) {
                current[curChar - 'a'] += 1;
            }
            // generateKey
            string currentKey = "";
            for (auto value: current) {
                currentKey += to_string(value) + ":";
            }
            stringAndMetrics[currentKey].push_back(targetString);
        }

        for (auto [p, strings] : stringAndMetrics) {
            answer.push_back(strings);
        }
        return answer;
    }
};