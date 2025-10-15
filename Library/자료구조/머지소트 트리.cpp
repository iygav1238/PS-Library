#include <bits/stdc++.h>
using namespace std;

struct MergeSortTree {
    int size, LOG; vector<vector<int>> tree;
    MergeSortTree(int n) : LOG((int)ceil(log2(n))), size(1 << LOG), tree(2 * size) {}
    
    vector<int> merge(const vector<int> &a, const vector<int> &b) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        while (i < a.size()) res.push_back(a[i++]);
        while (j < b.size()) res.push_back(b[j++]);
        return res;
    }
    
    void init(const vector<int> &a) {
        for (int i = 0; i<a.size(); i++) tree[size+i].push_back(a[i]);
        for (int i = size-1; i>=1; i--) {
            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }

    // queryUP: [l, r] 구간에서 k보다 큰 수의 개수
    int queryUP(int l, int r, int k) {
        l += size;
        r += size;
        int res = 0;
        while (l <= r) {
            if (l & 1) {
                res += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
                l++;
            }
            if (!(r & 1)) {
                res += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    // queryDown: [l, r] 구간에서 k보다 작은 수의 개수
    int queryDown(int l, int r, int k) {
        l += size;
        r += size;
        int res = 0;
        while (l <= r) {
            if (l & 1) {
                res += lower_bound(tree[l].begin(), tree[l].end(), k) - tree[l].begin();
                l++;
            }
            if (!(r & 1)) {
                res += lower_bound(tree[r].begin(), tree[r].end(), k) - tree[r].begin();
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};