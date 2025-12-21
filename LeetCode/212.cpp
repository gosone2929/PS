#include <iostream>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char, unordered_set<pair<int, int>>> d;
        
        for (int row = 0; row <= board.size(); row += 1) {
            for (int col = 0; col <= board[0].size(); col += 1) {
                char curChar = board[row][col];
                d[curChar].insert({row, col});
            }
        }

        vector<string> answer;
        unordered_set<pair<int, int>> visited;
        pair<int,int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        function<bool(string, int)> dfs = [&](string word, int depth) {
            if (word.size() == depth) {
                return true;
            }

            char curChar = word[depth];
            if (not d.count(curChar)) {
                return false;
            }

            for (auto [tr, tc]: d[curChar]) {
                visited.insert({tr, tc});
                for (auto [rw, cw]: dirs) {
                    int nextRow = tr + rw;
                    int nextCol = tc + cw;
                    if (0 <= nextRow && nextRow < board.size() && 0 <= nextCol && nextCol < board[0].size()) {
                        char nextChar = board[nextRow][nextCol];
                        if (d[nextChar].count({nextRow, nextCol}) and not visited.count({nextRow, nextCol}) and dfs(word, depth + 1)) {
                            return true;
                        }
                    }
                }
                visited.erase({tr, tc});
            }
            
            
            return false;
        };

        for (auto cur: words) {
            if (dfs(cur, 0)) {
                answer.push_back(cur);
            }
        }
        return answer;
    }
};