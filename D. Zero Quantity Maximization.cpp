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
ll M=1e9+7;
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main(){
    ll n;cin>>n;
    ll a[n],b[n]; map<pair<ll,ll>,ll>mp; ll cnt=0,zero=0,maxm=INT_MIN;
    for(ll i=0;i<n;i++){cin>>a[i];}
    for(ll i=0;i<n;i++){cin>>b[i];}

    //hmo ek hi d se maxm no. of zero chahiye.we make zero c=d*a+b ,lets say a=13,b=1 & a=39,b=13 require same d for making c=0. same for a=1,b=2 & a=2,b=4.
    //so hmm iske common factor ko divide kr denge dono se taaki hmme same a,b mil jaye taaki same d lge inko zero bnane mein.
    //We should normalize each fraction as follows: firstly, we reduce it by finding the greatest common divisor of x and y, and then dividing both numbers by this divisor.
    //a1>0,b1<0 & a2<0,b2>0 using same d if a1=a2,b1=b2.eg. a1=1,b1=-6 & a2=-1,b1=6 reuire same d for c=0 that is d=6.
    //a1>0,b1>0 & a2<0,b2<0 using same d if a1=a2,b1=b2.eg. a1=1,b1=6 & a2=-1,b1=-6 reuire same d for c=0 that is d=-6.
    //we count if a=0,b=0 case separately then add in final answer.(cnt)
    //if a=0,b!=0 then no d makes c=0.
    //if a!=0,b=0 then only d=0 makes c=0. so we count these cases separately.(zero)
    // and final answer will be max(maxm+cnt,zero+cnt).
        
    for(ll i=0;i<n;i++){
        ll c=gcd(a[i],b[i]);
        if(c==0){continue;}
        a[i]/=c; b[i]/=c;
    }
    for(ll i=0;i<n;i++){
        if((a[i]<0 && b[i]>0) || (a[i]>0 && b[i]<0)){
            if(mp.count({a[i],b[i]})==0 && mp.count({-a[i],-b[i]})==0){mp[{a[i],b[i]}]++;}
            else if(mp.count({a[i],b[i]})>0){mp[{a[i],b[i]}]++;}
            else if(mp.count({-a[i],-b[i]})>0){mp[{-a[i],-b[i]}]++;}
        }   
        if((a[i]>0 && b[i]>0) || (a[i]<0 && b[i]<0)){
            if(mp.count({a[i],b[i]})==0 && mp.count({-a[i],-b[i]})==0){mp[{a[i],b[i]}]++;}
            else if(mp.count({a[i],b[i]})>0){mp[{a[i],b[i]}]++;}
            else if(mp.count({-a[i],-b[i]})>0){mp[{-a[i],-b[i]}]++;}
        }    
        if(a[i]==0 && b[i]==0){cnt++;}
        if(a[i]!=0 && b[i]==0){zero++;}
    }

    for(auto val:mp){
        ll d=val.ss;
        maxm=max(maxm,d);
    }
    maxm+=cnt;
    cout<<max(maxm,zero+cnt);
}
