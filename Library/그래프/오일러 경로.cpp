#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<set<int>> graph;
vector<int> order;
void dfs(int u) {
    while (!graph[u].empty()) {
        int v = *graph[u].begin();
        graph[v].erase(u);
        graph[u].erase(v);
        dfs(v);
    }
    order.push_back(u);
}

int32_t main() {
    int n; cin >> n;
    graph.clear(); order.clear();
    map<int, int> p, v;
    map<pair<int, int>, int> idx;
    vector<pair<int, int>> a;
    for (int i = 1; i<=n; i++) {
        int vol, pit; cin >> vol >> pit;
        idx[{vol, pit}] = i;
        if (p.count(pit) == 0) {
            p[pit] = graph.size();
            graph.push_back(set<int>());
            a.push_back({0, pit});
        }
        if (v.count(vol) == 0) {
            v[vol] = graph.size();
            graph.push_back(set<int>());
            a.push_back({vol, 0});
        }
        graph[v[vol]].insert(p[pit]);
        graph[p[pit]].insert(v[vol]);
    }

    int root = 0, cnt = 0;
    for (int i = 0; i<graph.size(); i++) {
        if (graph[i].size() & 1) {
            cnt++;
            root = i;
        }
    }

    dfs(root);
    if (order.size() != n+1 || cnt > 2) {
        cout << "NO" << endl;
        return;
    }

    vector<int> out;
    for (int i = 0; i<n; i++) {
        auto p1 = a[order[i]];
        auto p2 = a[order[i+1]];
        out.push_back(idx[{p1.first+p2.first, p1.second+p2.second}]);
        if (out[i] == 0) {
            out.clear();
            break;
        }
    }

    if (out.empty()) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i<n; i++) cout << out[i] << " \n"[i==n-1];
    }
    return 0;
}