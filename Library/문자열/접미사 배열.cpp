#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(const string& s) {
    int n = s.size();
    vector<int> sa(n), rank(n), temp(n);

    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(sa.begin(), sa.end(), cmp);

        temp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rank = temp;
    }

    return sa;
}

vector<int> lcp_array(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n);

    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h])
                h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}