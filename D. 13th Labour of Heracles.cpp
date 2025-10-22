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
vector<ll>adj[100001];
int main(){
    ll t;cin>>t;
    while(t--){
    ll n;cin>>n;
    ll a[n+1],tot=0;
    for(int i=1;i<=n;i++){adj[i].clear();}
    vector<pair<ll,ll>>v;
    vector<ll>ans;
    for(ll i=1;i<=n;i++){cin>>a[i]; v.pb({a[i],i});}
    for(ll i=0;i<n-1;i++){
        ll x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i=1;i<=n;i++){
        tot+=a[i]*(adj[i].size());
    }
    sort(all(v));
    ans.pb(tot);
    for(auto val:v){
        ll b=val.ff,i=val.ss;
        ll sz=adj[i].size();
        for(ll i=0;i<sz-1;i++){
            tot-=b;ans.pb(tot);
        }
    }
    reverse(all(ans));
    for(auto val:ans){cout<<val<<" ";}cout<<endl;
    }
}
