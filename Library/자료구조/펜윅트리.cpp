#include <bits/stdc++.h>
using namespace std;
#define int long long

// 1 base, update 시 1번 인덱스부터
struct BIT {
    int n; vector<int> t;
    BIT(int n): n(n), t(n+1,0) {}
    void add(int i,int v){ for(; i<=n; i+=i&-i) t[i]+=v; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
};

int32_t main() {
    
    int n; cin >> n;
    vector<int> a(n), b;
    for (auto &x : a) cin >> x;
    
    b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(int &x : a) x = lower_bound(b.begin(), b.end(), x) - b.begin()+1;

    BIT bit(b.size());
    int res = 0;
    for(int x : a){
        res += (bit.sum(b.size()) - bit.sum(x));
        bit.add(x,1);
    }
    cout << res << endl;

    return 0;
}