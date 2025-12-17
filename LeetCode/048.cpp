#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, int depth) {

    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1; 
        for (int row = 0; row <= n / 2 ; row += 1) {
            for (int col = row; col <= n - row - 1; col += 1) {
                deque<pair<int, int>> target;
                int tempRow = row, tempCol = col;
                for (int i = 0; i < 4; i += 1) {
                    int nextRow = tempCol, nextCol = n - tempRow;
                    target.push_back({tempRow, tempCol});
                    tempRow = nextRow;
                    tempCol = nextCol;
                }
                pair<int,int> swapTarget = target.front();
                target.pop_front();
                while (not target.empty()) {
                    pair<int,int> nextSwapTarget = target.back();
                    target.pop_back();
                    swap(matrix[swapTarget.first][swapTarget.second], matrix[nextSwapTarget.first][nextSwapTarget.second]);
                    swapTarget = nextSwapTarget;
                }
            }
        }
    }
};

vector<vector<int>> make(int n) {
    vector<vector<int>> answer(n, vector(n, 0));
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            answer[i][j] = i * n + j + 1;
        }
    }
    return answer;
}
int main() {
    auto ex1 = make(3);

    for(auto t: ex1){
        for (auto p: t) {
            cout << p << " ";
        }
        cout << endl;
    }
    Solution().rotate(ex1);
    for(auto t: ex1){
        for (auto p: t) {
            cout << p << " ";
        }
        cout << endl;
    }

}