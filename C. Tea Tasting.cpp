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
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n+1],b[n+1];
        for(ll i=1;i<=n;i++){cin>>a[i];}
        for(ll i=1;i<=n;i++){cin>>b[i];}

        // we use difference array (times) for record no .of times that no.will be add.
        // and val array for storing bchi hui value. bss simple!!!!

        ll ps[n+1];ps[0]=0;
        vector<ll>times(n+2),val(n+1);
        for(ll i=1;i<=n;i++){
            ps[i]=ps[i-1]+b[i];
        }
        for(ll i=1;i<=n;i++){
            ll s=i,e=n,x=ps[i-1],ind=n;
            while(s<=e){
                ll mid=(s+e)/2;
                if(ps[mid]-x>=a[i]){
                    ind=mid;e=mid-1;
                }
                else{s=mid+1;}
            }
            times[i]+=1;
            if(ps[ind]-x==a[i]){
                times[ind+1]-=1;
            }
            else if(ps[ind]-x>a[i]){
                times[ind]-=1;
                val[ind]+=(a[i]-(ps[ind-1]-x));
            }
        }
        ll time=0;
        for(ll i=1;i<=n;i++){
            time+=times[i];
            ll s=(time*b[i])+val[i];
            cout<<s<<" ";
        }
        cout<<endl;
    }
}
    
