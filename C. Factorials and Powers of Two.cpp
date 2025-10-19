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
ll setbits(ll n){ return __builtin_popcountll(n); }

int main(){
    ll t;cin>>t;
    while(t--){
        ll n,m=1;cin>>n; vector<ll>v;

        for(ll i=1;i<=20;i++){
            m*=i;
            if(m>n){m=m/i;break;}
            v.pb(m);
        }

        ll n1=v.size(),minm=INT_MAX;

        for(ll b=0;b<(1<<n1);b++){
            ll s=0,cnt=0;
            for(ll i=0;i<n1;i++){
                if(b&(1<<i)){
                   s+=v[i];cnt++;
                }  
            }
            if(s<=n){
                ll rem=n-s;
                cnt+=setbits(rem);
                minm=min(minm,cnt);
            }
        }

        cout<<minm<<endl;
    }
}

/*

If the problem asked to represent n as a sum of distinct powers of two only (without the factorials), then there is a unique way to do it, using the binary representation of n
and the number of terms will be the number of digits equal to 1 in this binary representation. Let's denote this number by ones(n).

If we fix the factorials we are going to use in the sum, then the rest of the terms are uniquely determined because of the observation above. Note that 1
and 2 will not be considered as factorials in order to avoid repeating terms.

So, to solve the problem it is enough to iterate through all possibilities of including or not including each factorial (up to 14!
) and for each of them calculate the number of terms used in the sum. If we used f factorials and their sum is s
, then the number of terms can be calculated as f+ones(n−s). The minimum of all these numbers will be the answer.

*/
