#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> graph[n+1], IN(n+1), OUT(n+1);
    for (int i = 2; i<=n; i++) {
        int parent; cin >> parent;
        graph[parent].push_back(i);
    }

    int dep = 0;
    function<void(int, int)> Tourist = [&](int u, int p) {
        IN[u] = ++dep;
        for (int v : graph[u]) {
            if (v == p) continue;
            Tourist(v, u);
        }
        OUT[u] = dep;
    };
    Tourist(1, 0);

    return 0;
}
