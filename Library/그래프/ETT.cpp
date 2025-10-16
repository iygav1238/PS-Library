#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> graph[n+1], IN(n+1), OUT(n+1);
    for (int i = 2; i<=n; i++) {
        int parent; cin >> parent;
        graph[parent].push_back(i);
    }

    auto Tourist = [&](int node) {
        vector<pair<int, int>> st = {{node, 0}};
        int dep = 0;
        while (!st.empty()) {
            auto [u, stat] = st.back(); st.pop_back();
            if (stat == 1) {
                dep++;
                IN[u] = dep;
                st.push_back({u, 1});
                sort(graph[u].rbegin(), graph[u].rend());
                for (auto v : graph[u]) st.push_back({v, 0});
            } else OUT[u] = dep;
        }
    };
    Tourist(1);

    return 0;
}