//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
ll n,k;
bool good(ll x){
        ll s1=0,r=1;
        while(true){
        s1+=(x/r);
        if(x/r ==0){break;}
        r*=k;
        }
        if(s1>=n){return true;}
        return false;
}
int main(){
    cin>>n>>k;
    ll s=1,e=1e9,ans;
    while(s<=e){
        ll mid=e+(s-e)/2;
        if(good(mid)){
                ans=mid;
                e=mid-1;
        }
        else{s=mid+1;}
    }
    cout<<ans;
}
