#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int N) {
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j<=N; j+=i) is_prime[j] = false;
        }
    }
    return is_prime;
}