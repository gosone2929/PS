
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 1);
    int temp = 1;
    for (int i = 0; i < nums.size(); i += 1) {
        answer[i] *= temp;
        temp *= nums[i];
    }
    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i -= 1) {
        answer[i] *= temp;
        temp *= nums[i];
    }
    return answer;
}

int main() {
    auto x = vector<int>({1,2,3,4});
    auto answer = productExceptSelf(x);

    for(auto x: answer) {
        cout << x << " ";
    }
}