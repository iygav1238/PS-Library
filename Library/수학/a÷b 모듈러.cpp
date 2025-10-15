#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// a^b % mod 계산
int fpow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

// a / b % MOD 계산
int mod_div(int a, int b) {
    return 1LL * a * fpow(b, MOD - 2) % MOD;
}
