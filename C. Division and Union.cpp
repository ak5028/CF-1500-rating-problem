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

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<pair<int,int>,int>>v;
        vector<int>mark(n,-1);
        for(int i=0;i<n;i++){
            int l,r;cin>>l>>r;
            v.pb({{l,r},i});
        }
        sort(all(v)); int mx=v[0].ff.ss,x=0; 
        for(int i=1;i<n;i++){
            if(v[i].ff.ff<=mx && x==0){
                mark[v[i].ss]=1;
                mx=max(mx,v[i].ff.ss);
            }
            else{
                mark[v[i].ss]=2; x=1;;
            }
        }mark[v[0].ss]=1;
        if(x==0){cout<<-1<<endl;}
        else{
            for(auto val:mark){
                cout<<val<<" ";
            }cout<<endl;
        }
    }
}
/*

Think of intervals as forming a chain by overlapping. The moment one interval starts after all previous ones end, the chain breaks, that’s the split point. 
Sort intervals by left endpoint. Sweep left →→ right, maintain mx=max(right). 
All intervals with l≤mx belong to group 1. 
The first interval with l>mx starts group 2.

*/
