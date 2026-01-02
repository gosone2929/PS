#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> A;

int main() {
    cin >> N;
    cin >> K;
    A.resize(N);

    for (auto &a : A) {
        cin >> a;
    }
    unordered_map<int, int> hash;
    for (auto cur: A) {
        hash[cur % K] += 1;
    }

    int answer = 0;
    for (auto cur: A) {
        int targetVal = cur % K ;

        int tv = hash[targetVal];
        if (cur == targetVal) {
            tv -= 1;
        }
        answer += tv;
    }

    cout << answer / 2 << endl;
    return 0;
}
