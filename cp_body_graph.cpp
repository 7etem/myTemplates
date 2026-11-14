#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

void solve(){
    cin >> n;
    adj.assign(n, {});
    visited.assign(n, false);
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}