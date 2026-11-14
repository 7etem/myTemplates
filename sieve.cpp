#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;

const int limit = 1e6 + 5000;
vector <int> primes;
array<bool, limit> is_composite;

void sieve () {
	fill (all(is_composite), false);
	for (int i = 2; i < limit; ++i) {
		if (!is_composite[i]) primes.push_back (i);
		for (int j = 0; j < primes.size () && i * primes[j] < limit; j++) {
			is_composite[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

void solve(){
    int x; cin >> x;
    int res = 1;
    int y = x;
    for (int prime: primes){
        if (prime * prime > x) break;
        int k = 0;
        while (y % prime == 0){
            y /= prime;
            k++;
        }
        res *= (k + 1);
    }
    if (y > 1) res *= 2;
    cout << res << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    sieve();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// https://cses.fi/problemset/task/1713/