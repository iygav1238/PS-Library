#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define heap priority_queue

const int INF = 1000000000000000002LL;

vector<vector<pii>> graph;

vector<int> dijkstra(int start) {
    int n = graph.size();
    vector<int> dist(n, INF), from(n, -1);
    heap<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top(); pq.pop();

        if (cur_dist > dist[u]) continue;

        for (auto [v, weight] : graph[u]) {
            int new_dist = cur_dist + weight;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                from[v] = u;
                pq.push({new_dist, v});
            }
        }
    }
    return dist;
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
