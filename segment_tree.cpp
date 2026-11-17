#include <bits/stdc++.h>
#define int long long
#define f(i,x) for(int i=0;i<(x);i++)
#define print_container(arr) for(auto const temp: arr){ cout << temp << " ";  }cout << endl;
#define all(x) (x).begin(), (x).end()
using namespace std;
 
struct segmentTree{
    int n2 = 1, ln2 = 0;
    vector<vector<int>> arr2;
 
    // change
    const int neutral = 0;
    int combine(int a, int b){
        return a + b;
    }
 
    void fill(int depth = 0, int i = 0){
        if (depth == ln2){
            return;
        }
        if (arr2[depth].empty()){
            arr2[depth].resize(1 << depth);
        }
        fill(depth + 1,2 * i);
        fill(depth + 1,2 * i + 1);
        arr2[depth][i] = combine(arr2[depth + 1][2 * i] , arr2[depth + 1][2 * i + 1]); //combine
    }
 
    segmentTree(vector<int>& arr){
        int n = arr.size();
        while (n2 < n){
            n2 *= 2;
            ln2++;
        }
        arr2.resize(ln2 + 1);
        arr2[ln2] = arr;
        arr2[ln2].resize(n2, neutral);
        fill();
    }
 
    void update(int i, int x){
        arr2[ln2][i] = x;
        int depth = ln2 - 1;
        i = i / 2;
        while (depth >= 0){
            arr2[depth][i] = combine(arr2[depth + 1][i * 2], arr2[depth + 1][i * 2 + 1]);
            depth--;
            i /= 2;
        }
    }
    
    int query(int l, int r, int depth = 0, int i = 0){
        int res = neutral;
        int size_chunk = (1 << (ln2 - depth));
        int li = i * size_chunk, ri = (i + 1) * size_chunk - 1;
        if (li >= l && ri <= r){
            res = combine(res, arr2[depth][i]);
        }
        else if (ri < l || li > r){
            // do nothing
        }
        else{
            res = combine(res, query(l, r, depth + 1, i * 2));
            res = combine(res, query(l, r, depth + 1, i * 2 + 1));
        }
        return res;
    }
 
};
 
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    segmentTree st(arr);
    f (i, q){
        int type; cin >> type;
        if (type == 1){
            int i, x; cin >> i >> x; i--;
            st.update(i, x);
        }
        else{
            int l, r; cin >> l >> r; l--; r--;
            cout << st.query(l, r) << "\n";
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

// https://cses.fi/problemset/task/1648