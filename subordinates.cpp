#include<bits/stdc++.h>
#define ll long long
using namespace std;

//dp(N, x, leading_zeros, tight)
vector<int> tree[200001];
void solve(int src, int parent, vector<int>& subs){
    int subordinates = 0;
    for(auto child: tree[src]){
        if(child == parent)
            continue;
        solve(child, src, subs);
        subordinates += (1 + subs[child]);
    }
    subs[src] = subordinates;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    // cin >> t;
    t = 1;
    while(t--){
        cin >> n;
        vector<int> ans(n+1);
        for(int i=2; i<=n; i++){
            int x;
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        solve(1, 0, ans);
        for(int i=1;i<=n;i++)
            cout << ans[i] << " ";
    }
    return 0;
}
