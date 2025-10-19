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

bool customSort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second > b.second;  // decreasing order of second
    return a.first < b.first;        // increasing order of first
}

int main(){
    ll n;cin>>n;
    vector<pair<ll,ll>>v,v1; map<pair<ll,ll>,ll>mp; vector<ll>ans;
    for(ll i=1;i<=n;i++){
        ll l,r;cin>>l>>r;
        v.pb({l,r}); v1.pb({l,r});
        mp[{l,r}]=i;
    }
    
    //sort vector of pair by inc value of l and if l is same then sort by r in dec order 
    sort(v.begin(), v.end(), customSort);

    ll ps[n],ind=-1,ind2,val; ps[n-1]=v[n-1].ss;
    //suffix minimum, uss index se aage wale mein jo minm h vo store hoga ps mein
    for(ll i=n-2;i>=0;i--){
        ps[i]=min(v[i+1].ss,ps[i+1]);
    }

    //check ki uss index se aage uuske r se koi choti ya equal value hai (aage vale r mein se),hai toh thik hai otherwise not possible(-1,-1)
    for(ll i=0;i<n-1;i++){
        if(ps[i]<=v[i].ss){
            val=ps[i];ind=i;break;
        }
    }

    if(ind==-1){cout<<-1<<" "<<-1<<endl;}
    else{
        for(ll i=ind+1;i<n;i++){
            if(v[i].ss==val){ind2=i;break;}
        }
        ll i1=mp[v[ind]],i2=mp[v[ind2]];

        if(i1==i2){//same hai dono segment 
            ll l1=v1[i1-1].ff,r1=v1[i1-1].ss;
            for(ll i=0;i<n;i++){
               if(v1[i].ff==l1 && v1[i].ss==r1){ans.pb(i+1);}
            }
            cout<<ans[0]<<" "<<ans[1];
        }
        else{cout<<i2<<" "<<i1<<endl;}
    }
}

/*

Let's sort segments firstly by their left border in increasing order and in case of equal by their right border in decreasing order. 
If there is any valid pair then the inner segment will always go after the outer one.
Now you can go from left to right, keep the maximum right border of processed segments and compare it to the current segment.

*/
