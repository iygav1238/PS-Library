#include <bits/stdc++.h>
using namespace std;

int getParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = getParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}