#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> board = {};
    unordered_map<int, int> visited = {};
    bool flag = false;
    void dfs(int index){
        // 도달 가능?
        if (index >= board.size() - 1) {
            // if (index == board.size() - 1) {
                
            // }
            flag = true;
            return;
        }
        // 조기 종료
        if (flag or visited.count(index)) {
            return;
        }
        visited[index] = 1;

        int curVal = board[index];
        for (int nextIndex = curVal; nextIndex > 0; nextIndex -= 1) {
            dfs(index + nextIndex);
            if (flag) {
                return;
            }
        }
        return;
    }
    bool canJump(vector<int>& nums) {
        int goal = 0;
        for (int i = 0; i <= nums.size() - 2; i += 1) {
            goal = max(goal, nums[i] + i);
        }
        return goal >= nums.size() - 1? true : false;
    }
    bool canJump2(vector<int>& nums) {
        board = nums;
        dfs(0);
        return flag;
    }
};

int main() {
    vector<int> x = {2,3,1,1,4};
    vector<int> x2 = {1,2};
    cout << Solution().canJump(x2) << endl;
}