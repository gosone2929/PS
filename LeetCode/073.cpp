#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> zr(matrix.size(), 0);
        vector<int> zc(matrix[0].size(), 0);
        for (int row = 0; row < matrix.size(); row += 1) {
            for (int col = 0; col < matrix[0].size(); col += 1) {
                if (matrix[row][col] == 0) {
                    zr[row] = 1;
                    zc[col] = 1;
                }
                
            }
        }

        for (int row = 0; row < matrix.size(); row += 1) {
            if (zr[row] == 1) {
                for (int col = 0; col < matrix[0].size(); col += 1) {
                    matrix[row][col] = 0;
                }
                continue;
            }

            for (int col = 0; col < matrix[0].size(); col += 1) {
                if (zc[col] == 1) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};