#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> arr;
    int N;
    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    vector<int> v = {};
    for(auto val: arr) {
        if (v.empty() or v.back() < val) {
            v.push_back(val);
            continue;
        }
        int lo = -1;
        int hi = v.size();

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            
            if (v[mid] < val) {
                lo = mid;
            }else {
                hi = mid;
            }
        }
        v[hi] = val;
    }
    // vector<int> v2 = {};
    // for(auto val: arr) {
    //     if (v2.empty() or v2.back() < val) {
    //         v2.push_back(val);
    //         continue;
    //     }
    //     auto t = lower_bound(v2.begin(), v2.end(), val);
    //     int index = distance(v2.begin(), t);
    //     cout << index;
    //     *t = val;
    //     // for(auto t:v2) cout << t << " "; cout << endl;
    // }
    
    cout << v.size() << endl;
}