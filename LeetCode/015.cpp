#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        unordered_map<int, int> ts = {};
        
        sort(nums.begin(), nums.end());
        unordered_set<string> acs = {};
        
        for (int index = 0; index < nums.size(); index += 1) {
            auto num = nums[index];
            ts[num] += 1;
        }

        for (int i = 0; i < nums.size() - 1 ; i += 1) {
            if (i + 2 < nums.size() - 1 and nums[i + 2] == nums[i]) {
                continue;
            }
            for (int j = i + 1 ; j < nums.size() - 1; j += 1) {
                if (j + 1 < nums.size() - 1 and nums[j + 1] == nums[j]) {
                    continue;
                }
                auto curTarget = -(nums[i] + nums[j]);
                if (ts.count(curTarget) and nums[j] <= curTarget) {
                    auto currentAnswer = vector({nums[i], nums[j], curTarget});


                    if (nums[j] == curTarget) {
                        if (nums[i] == curTarget and ts[curTarget] < 3) {
                            continue;
                        }else if(ts[curTarget] < 2) {
                            continue;
                        }
                    }

                    string currentAnswerString = "";
                    for (int t: currentAnswer) {
                        currentAnswerString += to_string(t);
                        currentAnswerString += " ";
                    }
                    cout << currentAnswerString << endl;
                    if (not acs.count(currentAnswerString)) {
                        answer.push_back(currentAnswer);
                        acs.insert(currentAnswerString);
                    }
                    
                }
            }
        }
        
        return answer;
    }
};

int main() {
    vector<int> xVector({-2, 1, 1});
    auto answer = Solution().threeSum(xVector);

    for (auto t: answer) {
        for (auto p: t) cout << p << " ";
        cout << endl;
    }
    return 3;
}

