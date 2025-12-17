#include <iostream>
using namespace std;


class Solution {
public:
    vector<pair<int ,int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        function<bool(int, int, int)> dd = [&](int row, int col, int depth){
            if (
                not(0 <= row and row < n) or 
                not (0 <= col and col < m) or
                board[row][col] != word[depth]
            ) {
                return false;
            }
            
            if (word.size() - 1 == depth) {
                return true;
            }
            char temp = board[row][col];
            board[row][col] = NULL;

            for (auto [nrw, ncw]: dirs) {
                if (dd(nrw, ncw, depth + 1)) {
                    return true;
                }
            }
            board[row][col] = temp;
            return false;
        };
        for (int row = 0; row < n; row += 1) {
            for (int col = 0; col < m; col += 1) {
                if (dd(row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};