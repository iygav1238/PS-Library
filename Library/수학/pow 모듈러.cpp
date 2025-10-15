#include <bits/stdc++.h>
using namespace std;

// a^b % mod 계산
int fpow(int a, int b, int mod) {
    int res = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}