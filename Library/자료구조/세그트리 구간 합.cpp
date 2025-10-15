#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Segtree{
    int LOG, SIZE, N;
    vector<int> tree;
    Segtree(int n) {
        N = n;
        LOG = (int)ceil(log2(n+1));
        SIZE = 1 << LOG;
        tree.assign(2*SIZE, 0);
    }

    void update(int i, int x) {
        i += SIZE;
        tree[i] += x;
        while (i > 1) {
            i /= 2;
            tree[i] += x;
        }
    }

    int query(int l, int r) {
        l += SIZE; r += SIZE;
        int res = 0;
        while (l <= r) {
            if (l & 1) res += tree[l];
            if (~r & 1) res += tree[r];
            l = (l+1)/2;
            r = (r-1)/2;
        }
        return res;
    }
};