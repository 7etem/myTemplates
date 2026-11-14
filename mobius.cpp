#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;

const int  limit = 1e6 + 5;
vector<int> mobius(limit);

void fill_mobius(){
    mobius[1] = -1;
    for (int i = 1; i < limit; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < limit; j += i) { mobius[j] += mobius[i]; }
        }
    }
}
struct SPF {
    int MAXN;
    vector<int> spf;

    SPF(int n) : MAXN(n), spf(n + 1) {
        build();
    }

    void build() {
        for (int i = 0; i <= MAXN; i++)
            spf[i] = i;

        spf[0] = 0;
        spf[1] = 1;

        for (int i = 2; 1LL * i * i <= MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXN; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> divisors(int x) {
        vector<pair<int,int>> pf;

        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            pf.push_back({p, cnt});
        }

        vector<int> res;

        function<void(int,int)> dfs = [&](int idx, int cur) {
            if (idx == (int)pf.size()) {
                res.push_back(cur);
                return;
            }

            auto [p, e] = pf[idx];
            int val = 1;

            for (int i = 0; i <= e; i++) {
                dfs(idx + 1, cur * val);
                val *= p;
            }
        };

        dfs(0, 1);
        sort(res.begin(), res.end());

        return res;
    }
};

SPF spf(limit);

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> divisors(limit);
    f (i, n){
        vector<int> divs = spf.divisors(arr[i]);
        for (int div: divs){
            divisors[div]++;
        }
    }
    int res = 0;
    for (int i = 1; i < limit; i++){
        res += mobius[i] * (divisors[i]) * (divisors[i] - 1) / 2;
    }
    cout << res << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    fill_mobius();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
// https://cses.fi/problemset/task/2417/