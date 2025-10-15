#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5+1;

int n;
vector<int> sub(MAXN, 0), res(MAXN, 0), dp(MAXN, 0);
vector<pair<int, int>> graph[MAXN];
void dfs(int u, int p) {
    sub[u] = 1;
    for (auto [v, w] : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
        dp[u] += dp[v] + w*sub[v];
    }
}

void reroot(int u, int p) {
    for (auto [v, w] : graph[u]) {
        if (v == p) continue;
        res[v] = res[u] + (n-2*sub[v])*w;
        reroot(v, u);
    }
}

int32_t main() {
    cin >> n;
    for (int i = 0; i<n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 1);
    res[1] = dp[1];
    reroot(1, 1);
    for (int i = 1; i<=n; i++) cout << res[i] << endl;
    return 0;
}