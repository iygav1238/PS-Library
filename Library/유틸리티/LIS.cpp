#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(const vector<int>& A) {
    int N = A.size();
    vector<int> DP;
    vector<pair<int, int>> RESULT(N);
    
    DP.push_back(A[0]);
    RESULT[0] = {A[0], 1};

    for (int i = 1; i < N; ++i) {
        int x = A[i];
        auto it = lower_bound(DP.begin(), DP.end(), x);
        int idx = it - DP.begin();
        if (it == DP.end()) DP.push_back(x);
        else *it = x;
        RESULT[i] = {x, idx + 1};
    }

    int current = DP.size();
    vector<int> res;
    for (int i = N - 1; i >= 0; --i) {
        if (RESULT[i].second == current) {
            res.push_back(RESULT[i].first);
            --current;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
