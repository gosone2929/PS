
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<vector<int>> answer;

        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int index = 0; index < intervals.size(); index += 1) {
            vector<int>& current = intervals[index];
            if (current[0] <= second) {
                second = max(current[1], second);
            }else {
                answer.push_back({first, second});
                first = current[0];
                second = current[1];
            }
        }
        answer.push_back({first, second});
        return answer;
    }
};