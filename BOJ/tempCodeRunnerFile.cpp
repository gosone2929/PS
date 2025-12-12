ector<int> v = {};
    // for(auto val: arr) {
    //     if (v.empty() or v.back() < val) {
    //         v.push_back(val);
    //         continue;
    //     }
    //     int lo = -1;
    //     int hi = arr.size();

    //     while (lo + 1 < hi) {
    //         int mid = (lo + hi) / 2;
            
    //         if (v[mid] < val) {
    //             lo = mid;
    //         }else {
    //             hi = mid;
    //         }
    //     }
    //     v[hi] = val;
        
    //     for (auto t: v) cout << t << " "; cout << endl;
    // }