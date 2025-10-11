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

ll calc(ll a,ll sum){
    ll s=1,e=a; ll ans=0;
    while(s<=e){
        ll mid=(s+e)>>1;
        if(mid+sum >= a-mid){
            ans=mid+1; e=mid-1;
        }
        else{s=mid+1;}
    }
    return ans;
}

int main(){
    ll t;cin>>t;
    while(t--){
    ll n; cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    ll i=0,j=n-1; ll sum=0,ans=0;
    while(i<=j){
        if(i==j && a[i]!=0){
            if(sum==0){
                if(a[i]%2==0){ans+=(a[i]/2)+1;}
                else if(a[i]==1){ans++;}
                else{ans+=(a[i]/2)+1+1;}
                break;
            }
            else{
                if(a[i]==1 || sum>=a[i]){ans++; break;}
                ans+=calc(a[i],sum);
                break;
            }
        }
        sum +=a[i]; ans+=a[i];
        if(sum<a[j]){
             i++; continue;
        }
        else if(sum==a[j]){
            ans+=1; j--; i++; sum=0;
        }
        else if(sum>a[j]){
            ans-=(sum-a[j]); ans++; sum-=a[j]; a[i]=sum; sum=0; j--;
        }
    }
    cout<<ans<<endl;
}
}
