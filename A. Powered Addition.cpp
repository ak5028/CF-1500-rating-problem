//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
       ll t;cin>>t;
       while(t--){
        ll n;cin>>n;
        ll a[n];ll maxm=0,cnt=0;
        for(ll i=0;i<n;i++){cin>>a[i];}

        //take the diffenece of adjacent element and store in d,
        //then find the left most set bit of d and store maximum that is the answer.

        for(ll i=1;i<n;i++){
                if(a[i]>=a[i-1]){continue;}
                ll d=a[i-1]-a[i],m;
                for(int i=0;i<64;i++){
                        if(d>>i ==0){m=i;break;}
                }
                maxm=max(maxm,m);
                a[i]=a[i-1];
        }
        
        cout<<maxm<<endl;
       }
}
