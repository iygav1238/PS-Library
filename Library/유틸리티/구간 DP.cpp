#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 1; i<=n; i++) {
        for (int l = 0; l+i-1 < n; l++) {
            int r = l+i-1;
            // dp[l][r] = ...
        }
    }
    cout << dp[0][n-1] << endl;   
    return 0;
}