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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a; // Base case: if b is 0, a is the GCD
    }
    return gcd(b, a % b); // Recursive call using remainder
}

int main(){
    ll n;cin>>n;
    ll a[n],cnt=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){cnt++;}
    }
    
    //Consider cnt1 as number of 1s in the a. If 0<cnt1 then the answer is n-cnt1.
    //otherwise We should find a segment with its gcd equal to 1 and minimum length.
    //brute force:check for all subaarays or segments which from gcd 1 then store minm length wala subaaray kyki ismein minm op lgege.
    //answer is op+n-1.

    if(cnt>0){cout<<n-cnt;}
    else{
        ll minm=INT_MAX,t=0;
        for(ll i=1;i<n;i++){
            ll x=0,g=a[i-1],y=0;
            for(ll j=i;j<n;j++){
                g=gcd(a[j],g);
                x++;
                if(g==1){y=1;t=1;break;}
            }
            if(y==1){
            minm=min(minm,x);}
        }
        if(t==0){cout<<-1;}
        else{cout<<minm+n-1;}
    }
}
