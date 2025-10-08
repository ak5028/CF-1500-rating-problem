//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    ll n;cin>>n;
    ll a[n];
    vector<ll>v,ans;
    vector<pair<ll,ll>>v1;
    ll st=0,cnt=1;
    for(ll i=0;i<n;i++){cin>>a[i];}
    for(ll i=1;i<n;i++){
        if(a[i]>a[i-1]){cnt++;}
        else{
            v.pb(cnt);
            cnt=1;
            v1.pb({st,i-1});
            st=i;
        }
    }
    v.pb(cnt);
    v1.pb({st,n-1});
    //for(auto val:v){cout<<val;}cout<<endl;
    //for(auto val:v1){cout<<val.ff<<val.ss<<endl;}
    if(v.size()>1){
    for(ll i=0;i<v.size()-1;i++){
        ll e1=v1[i].ss;
        ll s1=v1[i].ff;
        ll s2=v1[i+1].ff;
        ll e2=v1[i+1].ss;
        if(s2-e1-1==0){
            if(e2-s2-1>=0 && a[s2+1]>a[e1]){ans.pb(v[i]+v[i+1]-1);}
            else if(e1-s1-1>=0 && a[s2]>a[e1-1]){ans.pb(v[i]+v[i+1]-1);}
        }
        else if(i+2<n && v1[i+2].ff-e1-1==1){
            if(a[e1]<a[v1[i+2].ff]){ans.pb(v[i]+v[i+2]);}
        }
    }}
    ans.pb(v[v.size()-1]);
    sort(all(ans));
    reverse(all(ans));
    sort(all(v));
    reverse(all(v));
    cout<<max(ans[0],v[0]);
}
