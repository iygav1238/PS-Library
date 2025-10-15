#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
 
const int MOD = 998244353;
const int INF = 1000000000000000002LL;
 
const int MAXN = 2e5+1;
int fact[MAXN], inv[MAXN];
 
int modpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
 
void init() {
    fact[0] = 1;
    for (int i = 1; i<MAXN; i++) fact[i] = fact[i-1]*i%MOD;
    inv[MAXN - 1] = modpow(fact[MAXN-1], MOD - 2);
    for (int i = MAXN - 1; i>0; i--) inv[i-1] = inv[i]*i%MOD;
}
 
int nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int32_t main() {
    init();
    int n, k; cin >> n >> k;
    cout << nCk(n, k) << endl;
    return 0;
}