#include <bits/stdc++.h>
using namespace std;
#define int long long

struct MaxTree {
    vector<int> tree;
    int size;
    MaxTree(int n) {
        int LOG = (int)ceil(log2(n));
        size = 1 << LOG;
        tree.assign(2*size, 0);
    }

    void init(const vector<int> &a) {
        for (int i = 0; i<a.size(); i++) tree[size+i] = a[i];
        for (int i = size-1; i>=1; i--) tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    void update(int i, int x) {
        i += size;
        tree[i] = x;
        while (i > 1) {
            i /= 2;
            tree[i] = max(tree[2*i], tree[2*i+1]);
        }
    }

    int query(int l, int r) {
        l += size;
        r += size;
        int res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, tree[l++]);
            if (~r & 1) res = max(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};