#include <bits/stdc++.h>
using namespace std;

#define heap priority_queue
#define pii pair<int, int>

//1. 첫번째가 큰 수가 먼저, 같을 경우 두번째가 큰 수가 먼저
struct cmp1 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};
// 2. 첫번째가 큰 수가 먼저, 같을 경우 두번째가 작은 수가 먼저
struct cmp2 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};
// 3. 첫번째가 작은 수가 먼저, 같을 경우 두번째가 큰 수가 먼저
struct cmp3 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

int main() {
    vector<pii> v;
    sort(v.begin(), v.end(), cmp1());
    priority_queue<pii, vector<pii>, cmp1> pq;
    return 0;
}