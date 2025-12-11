#include <iostream>

using namespace std;

class Solution {
public:
    int dfv = INT_MAX / 2;
    int coinChange(vector<int>& coins, int amount) {

        vector<int> bags = vector(amount + 1, dfv);
        bags[0] = 0;
        auto sc = vector(coins);
        sort(sc.begin(), sc.end());

        for (auto c: sc) {
            for (int i = 0; i < amount + 1; i += 1) {
                if (i < c) {
                    continue;
                }
                if (bags[i - c] == dfv) {
                    continue;
                }
                bags[i] = min(bags[i], bags[i - c] + 1);
            }
        }
        return bags[amount] == dfv ? -1 : bags[amount];
    }
};

int main() {
    vector<int> t = vector({52,480,116,409,170,240,496});
    auto x = Solution().coinChange(t, 11);
    cout << x << endl;
}