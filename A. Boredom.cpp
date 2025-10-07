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
        ll a[n];map<ll,ll>mp;ll maxi=INT_MIN;
        for(ll i=0;i<n;i++){cin>>a[i];mp[a[i]]++;maxi=max(maxi,a[i]);}
        //n=mp.size();//cout<<n;
        vector<ll>cnt(maxi+1);//cout<<1;
        for(auto val:mp){
                //b[i]=val.first;
                cnt[val.first]=val.second;
                //i++;
        }//cout<<1;
        vector<ll>dp(maxi+1);
        dp[0]=0;
        dp[1]=1*cnt[1];
        for(ll i=2;i<=maxi;i++){
                dp[i]=max(dp[i-1],dp[i-2]+i*cnt[i]);
        }
        cout<<dp[maxi];
}
