#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    typedef unsigned long long ll;
    int k;
    int n;
    vector<ll> board;
    cin >> k; cin >> n;
    for(int i = 0; i < k; i += 1){
        ll p;
        cin >> p;
        board.push_back(p);
    }
    
    ll left = 0;
    ll right = 1ll << 32;
    
    auto c = [&](ll mid) {
        ll answer = 0;
        for (auto cur : board) {
            answer += cur / mid;
        }
        return answer;
    };

    while (left + 1 < right) {
        ll mid = (right + left) / 2;
        auto midVal = c(mid);
        if (n <= midVal) {
            left = mid;
        }else {
            right = mid;
        }
    }
    cout << left << endl;
}