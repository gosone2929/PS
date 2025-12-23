#include <iostream>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bool visited[grid.size()][grid[0].size()];

        for (int row = 0; row < grid.size(); row += 1) {
            for (int col = 0; col < grid[0].size(); col += 1) {
                visited[row][col] = false;
            }
        }
        int answer = 0;
        for (int row = 0; row < grid.size(); row += 1) {
            for (int col = 0; col < grid[0].size(); col += 1) {
                if (visited[row][col] || grid[row][col] == '0') {
                    continue;
                }
                answer += 1;
                visited[row][col] = true;
                deque<pair<int, int>> d = {{row, col}};
                while (not d.empty()) {
                    auto [row, col] = d.front();
                    d.pop_front();

                    for (auto [rw, cw] : dirs) {
                        int nextRow = rw + row;
                        int nextCol = cw + col;
                        if (
                            0 <= nextRow and nextRow < grid.size() and
                            0 <= nextCol and nextCol < grid[0].size() and
                            grid[nextRow][nextCol] == '1' and
                            not visited[nextRow][nextCol]
                            ) {
                            visited[nextRow][nextCol] = true;
                            d.push_back({nextRow, nextCol});
                            }
                    }
                }
            }
        }
        return answer;
    }
};