#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;

struct fenwick{
    int n;
    vector<int> arr, fen_prefix;

    fenwick(int x){
        n = x;
        arr.assign(n, 0);
        fen_prefix.assign(n + 1, 0);
    }

    void set(int i, int x){
        int y = x - arr[i];
        add(i, y);
    }

    void add(int i, int x){
        arr[i] += x;
        i++;
        for (; i <= n; i += (i & -i)){
            fen_prefix[i] += x;
        }
    }

    int get_prefix(int i){ //get(0) = arr[0], get(-1) = 0
        i++;
        int res = 0;
        for (; i > 0; i -= (i & -i)){
            res += fen_prefix[i];
        }
        return res;
    }

    int query(int l, int r){
        return get_prefix(r) - get_prefix(l);
    }
};


void solve(){
    int n, q;
    cin >> n >> q;
    fenwick ft(n);
    for(int i = 0; i < n; i++){
        int inp; cin >> inp;
        ft.set(i, inp);
    }
    f (i, q){
        int type; cin >> type;
        if (type == 1){
            int i, x; cin >> i >> x; i--;
            ft.set(i, x);
        }
        else{
            int l, r; cin >> l >> r; l--; r--;
            cout << ft.query(l - 1, r) << "\n";
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// https://cses.fi/problemset/task/1648/
