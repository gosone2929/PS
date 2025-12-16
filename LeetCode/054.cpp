#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        deque<pair<int, int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        vector<vector<bool>> visited = vector(matrix.size(), vector(matrix[0].size(), false));

        int row = 0;
        int col = -1;

        auto [nextRowW, nextColW] = dirs.front();
        dirs.pop_front();
        int visitedCount = 0;
        while (visitedCount < matrix.size() * matrix[0].size()){
            int nextRow = row + nextRowW, nextCol = col + nextColW;
            if (
                0 <= nextRow and nextRow < matrix.size() and
                0 <= nextCol and nextCol < matrix[0].size() and
                visited[row + nextRowW][col + nextColW] == false
            ) {
                answer.push_back(matrix[nextRow][nextCol]);
                visited[nextRow][nextCol] = true;
                visitedCount += 1;
                row = nextRow;
                col = nextCol;
            }else {
                dirs.push_back({nextRowW, nextColW});
                auto popElement = dirs.front();
                nextRowW = popElement.first;
                nextColW = popElement.second;
                dirs.pop_front();
            }
        }

        return answer;
    }
};