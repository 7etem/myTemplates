#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;

const int mod = 1e9 + 7;
const int limit = 1e6 + 5;

array<int, limit> fact, inv_fact;

int mod_pow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1){
            res *= a; res %= mod;
        }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

void init_fact(){
    fact[0] = 1;
    for (int i = 1; i < limit; i++){
        fact[i] = fact[i - 1] * i; fact[i] %= mod;
    }
    inv_fact[limit - 1] = mod_pow(fact[limit - 1], mod - 2);
    for (int i = limit - 2; i >= 0; i--){
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

int comb(int n, int k){
    return (fact[n] * (inv_fact[k] * inv_fact[n - k] % mod) % mod);
}

void solve(){
    int a, b;
    cin >> a >> b;
    cout << comb(a, b) << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    init_fact();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// https://cses.fi/problemset/task/1079/