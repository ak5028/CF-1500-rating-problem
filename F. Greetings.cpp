//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
ordered_set st;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<pair<ll,ll>>v; 
        for(ll i=0;i<n;i++){
            ll a,b;cin>>a>>b;
            v.pb({b,a});
        }st.clear();
        sort(all(v)); ll ans=0;
        for(ll i=0;i<n;i++){
            ans+=st.size()-st.order_of_key(v[i].ss);
            st.insert(v[i].ss);
        }
        cout<<ans<<endl;
    }
}
   
