//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll setbits(ll n){ return __builtin_popcountll(n); }
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set st;

vector<int>adj[100001];
vector<int>node(100001);
void dfs(int s,int e){
    node[s]=1;
    for(auto u:adj[s]){
        if(u==e){continue;}
        dfs(u,s);
        node[s]+=node[u];
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    //if n is odd then not poosible to divide into two even so -1
    //if n is even then two case odd+odd=even and even+even=even.
    //count hrr ek node se uske subtree ka size including that node if size is even  iska mtlb uss node k upar wala bhi even size ka hi hai then cnt inc.

    if(n%2!=0){cout<<-1;}
    else{
        int cnt=0,x=0;
        dfs(1,-1);
        int ans = 0;
        for (int i = 2; i <= n; ++i) {  // exclude the root (no parent edge above it)
                if (node[i] % 2 == 0) ++ans;  // cut edge (i, parent) if subtree size is even
        }
        cout << ans << '\n';
    }
}
