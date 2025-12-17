#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        
        // start(i)
        // 1) end_(i) , start_(i+1) 존재
        // - if
        // 2) start_(i), end(i)에 존재
        
        // end(i)
        // 1) end_(i) , start_(i+1) 존재
        // 2) start_(i), end(i)에 존재
        vector<vector<int>> answer = {};
        if (intervals.empty()) {
            answer.push_back(newInterval);
            return answer;
        }
        int index = 0;
        
        bool flag = false;
        while (index < intervals.size()) {
            auto cur = intervals[index];
            int curStart = cur[0], curEnd = cur[1];
            index += 1;

            if (curEnd < newInterval[0] or flag) {
                answer.push_back(cur);
                continue;
            }
            if (newInterval[1] < curStart) {
                answer.push_back(newInterval);
                answer.push_back({curStart, curEnd});
            }
            else if (curStart <= newInterval[0]) {
                answer.push_back({curStart, max(newInterval[1], curEnd)});
            }
            else if (newInterval[0] < curStart) {
                answer.push_back({newInterval[0], max(newInterval[1], curEnd)});
            }
            flag = true;

            
            while (index < intervals.size()) {
                int curBackValue = answer.back()[1];
                if (intervals[index][0] <= curBackValue) {
                    vector<int> curValue = answer.back();
                    answer.pop_back();
                    answer.push_back({curValue[0], max(curBackValue, intervals[index][1])});
                }else {
                    break;
                }
                index += 1;
            }
        }
        if(flag == false) {
            answer.push_back(newInterval);
        }
        return answer;
    }
    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> board;
        for (auto p: intervals){
            board.push_back(p[0]);
            board.push_back(p[1]);
        }
        auto lb = lower_bound(board.begin(), board.end(), newInterval[0]);
        int lbIndex = distance(board.begin(), lb);
        auto ub = lower_bound(board.begin(), board.end(), newInterval[1]);
        int ubIndex = distance(board.begin(), ub);
        
    }

};

int main() {
    vector<vector<int>> x = {{1,5}};
    vector<int> t = {0, 0};
    auto p = Solution().insert(x, t);
    for(auto t: p) cout << "{"<< t[0] << "," << t[1] << "} "<< endl;
}