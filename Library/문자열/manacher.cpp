#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<vector<int>, int> manacher(const string& input) {
    string s = "#";
    for (char c : input) {
        s += c;
        s += "#";
    }

    int n = s.size();
    vector<int> ret(n); // ret[i]는 s[i]를 중심으로 한 최장 팰린드롬 반지름
    int center = -1, right = -1;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (i <= right) {
            int j = 2 * center - i;
            ret[i] = min(ret[j], right - i);
        }

        while (i - ret[i] - 1 >= 0 && i + ret[i] + 1 < n && s[i - ret[i] - 1] == s[i + ret[i] + 1]) {
            ++ret[i];
        }

        if (i + ret[i] > right) {
            center = i;
            right = i + ret[i];
        }

        cnt += (ret[i] + 1) / 2; // 실제 팰린드롬 개수 카운트
    }
    return {ret, cnt};
}
