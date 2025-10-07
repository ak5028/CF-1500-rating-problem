//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
        ll n,q;cin>>n>>q;
        ll a[n+1];vector<ll>v(n+2);a[0]=INT_MIN;
        for(ll i=1;i<=n;i++){cin>>a[i];}

        //jis index ka occurence jyada hai in queries uss index pr hm maxm value rkhenge
        //so for finding occurence of index we add 1 at L and -1 at R+1.
        //-1 indicates ki iske baad ek query khatam hoti hai.
        //we add +1 at all indexes between L & R.
        //then sort freq of occurence and values and add accordingly.
                
        for(ll i=0;i<q;i++){
                ll l,r;cin>>l>>r;
                v[l]+=1;v[r+1]+=-1;
        }
        ll b[n+1];ll val=0;b[0]=INT_MIN;
        for(ll i=1;i<=n;i++){
                val+=v[i];
                b[i]=val;
        }
        
        sort(b,b+n+1);
        sort(a,a+n+1);
        ll ans=0;
        for(ll i=1;i<=n;i++){
                ans+=b[i]*a[i];
        }
        cout<<ans;

}
