#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define heap priority_queue

const int INF = 1000000000000000002LL;

vector<vector<pii>> graph;

bool bellmanFord(int start) {
    int n = graph.size();
    vector<int> dist(n, INF), from(n, -1);
    dist[start] = 0;

    for (int iter = 0; iter < n; ++iter) {
        bool updated = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    from[v] = u;
                    updated = true;
                    if (iter == n - 1) {
                        // 음수 사이클 탐지
                        cout << "Negative cycle detected!" << endl;
                        return false;
                    }
                }
            }
        }
        if (!updated) break;
    }
    return true;
}

vector<int> findPath(const vector<int> &from, int start, int end) {
    vector<int> path;
    for (int cur = end; cur != -1; cur = from[cur]) {
        path.push_back(cur);
        if (cur == start) break;
    }
    reverse(path.begin(), path.end());
    if (path[0] != start) return {}; // 경로가 없는 경우
    return path;
}
