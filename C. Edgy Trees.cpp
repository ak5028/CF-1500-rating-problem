//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set st;

vector<pair<ll,ll>>adj[100001];
vector<ll>visited(100001);
ll cnt,mod=1e9+7,k,n;

void dfs(ll s){
    if(visited[s]){return;}
    visited[s]=true;
    for(auto u:adj[s]){
        if(u.ss==1 || visited[u.ff]){continue;}
        cnt++; dfs(u.ff);
    }
}

ll power(ll a){
    ll x=1;
    for(int i=1;i<=k;i++){
        x*=a;
        x%=mod;
    }
    return x;
}

int main(){
    cin>>n>>k; vector<ll>v;
    for(ll i=0;i<n;i++){
        ll x,y,w;cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }

    //hmm total main se jo possible nhi hai vo minus krke apna nswer nikalenge
    //vo nikalne k liye n^k mein se jitne 0 lgatar hai(red edges)jb tk 1 na mile toh wo count^k minus krdenge aise hmm saare nikal lenge.
    //also minus that vertices which has only 1(means black edge)
    
    //Let's find the number of bad sequences — Sequences of length k
    //that do not pass through any black edges. Then answer is all possible sequences minus the number of bad sequences.
    //Thus, we can remove black edges from the tree.Now the tree would be split into connected components.
    //For every connected component, if we start with A1 being a node from this component, then we cannot step outside this component, since doing so would mean that we visit a black edge. 
    //But we can visit all the nodes in the current connected component in any order. So if the size of the current component is p
    //, then we have pk bad sequences corresponding to this connected component. Thus, the overall answer is nk−∑pk
    //where p is the size of different connected components, considering only red edges.


    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cnt=1;
            dfs(i);
            v.pb(cnt);
        }
    }

    ll ans=power(n);
    for(auto val:v){
        ll y=power(val);
        ans=((ans % mod) - (y % mod) + mod) % mod;
    }
    cout<<ans;
}
