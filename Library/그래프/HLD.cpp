#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define endl "\n"

struct SegTree {
    vector<int> tree, lazy;
    int size;

    SegTree(int n, const vector<int> &a) {
        int LOG = (int)ceil(log2(n));
        size = 1 << LOG;
        tree.assign(2 * size, INF);
        lazy.assign(2 * size, 0);
        init(a, 1, 1, size);
    }

    void init(const vector<int> &a, int node = 1, int nl = 1, int nr = -1) {
        if (nr == -1) nr = size;
        if (nl == nr) {
            if (nl <= (int)a.size()) tree[node] = a[nl - 1];
            return;
        }
        int mid = (nl + nr) >> 1;
        init(a, node << 1, nl, mid);
        init(a, node << 1 | 1, mid + 1, nr);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int l, int r, int v, int node = 1, int nl = 1, int nr = -1) {
        if (nr == -1) nr = size;
        push(node, nl, nr);
        if (r < nl || nr < l) return;
        if (l <= nl && nr <= r) {
            lazy[node] += v;
            push(node, nl, nr);
            return;
        }
        int mid = (nl + nr) >> 1;
        update(l, r, v, node << 1, nl, mid);
        update(l, r, v, node << 1 | 1, mid + 1, nr);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    int query(int l, int r, int node = 1, int nl = 1, int nr = -1) {
        if (nr == -1) nr = size;
        push(node, nl, nr);
        if (r < nl || nr < l) return INF;
        if (l <= nl && nr <= r) return tree[node];
        int mid = (nl + nr) >> 1;
        return query(l, r, node << 1, nl, mid) + query(l, r, node << 1 | 1, mid + 1, nr);
    }
} tree;

#define MAXV (int)1e5+1
int pv = 0;
int sub[MAXV], dep[MAXV], parent[MAXV], top[MAXV], in[MAXV];
vector<int> graph[MAXV], child[MAXV];

void dfs(int u = 1){
    for (auto v : graph[u]){
        if (v == parent[u]) continue;
        parent[v] = u;
        child[u].push_back(v);
        dfs(v);
    }
}

void dfs1(int u = 1){
    sub[u] = 1;
    for (auto &v : child[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);
        sub[u] += sub[v];
        if (sub[v] > sub[child[u][0]]) swap(v, child[u][0]);
    }
}

void dfs2(int u = 1){
    in[u] = ++pv;
    for (auto v : child[u]){
        top[v] = (v == child[u][0]) ? top[u] : v;
        dfs2(v);
    }
}

void update(int a, int b, int v = 1) {
    while (top[a] != top[b]){
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        tree.update(in[st], in[a], v);
        a = parent[st];
    }
    if (dep[a] > dep[b]) swap(a, b);
    tree.update(in[a] + 1, in[b], v);
}

int query(int a, int b){
    int ret = 0;
    while (top[a] != top[b]){
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += tree.query(in[top[a]], in[a]);
        a = parent[top[a]];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret += tree.query(in[a] + 1, in[b]);
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(); dfs1(); dfs2();
    while (q--){
        char what; cin >> what;
        int u, v; cin >> u >> v;
        if (what == 'P') update(u, v);
        else cout << query(u, v) << endl;
    }
    return 0;
}
