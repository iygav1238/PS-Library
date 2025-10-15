#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> get_divisors(int N) {
    vector<vector<int>> divisors(N+1);
    for (int i = 1; i<=N; i++) {
        for (int j = i; j <= N; j+=i) {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}