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

int main(){
    ll n;cin>>n; ll x=0,a,b; vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){cin>>a>>b; v.pb({a,b});}
    sort(all(v)); ll l1=v[0].ff,r1=v[0].ss,l2=INT_MIN,r2=INT_MIN;

    //assign shows on two tvs so that all shows can run on two tvs no clash then yes otherwise no.

    for(ll i=1;i<n;i++){
        ll l=v[i].ff;
        ll r=v[i].ss;
        if(l<=r1){
            if(l<=r2){
                x++;break;
            }
            else{
                l2=l;r2=r;
            }
        }
        else{
            l1=l;r1=r;
        }
    }
    if(x>0){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
}
