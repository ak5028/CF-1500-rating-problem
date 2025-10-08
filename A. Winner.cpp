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
        map<string,ll>mp; vector<pair<string,ll>>v;v.pb({"z",-1});

        for(ll i=1;i<=n;i++){
                string s;cin>>s; ll x;cin>>x;
                v.pb({s,x}); mp[s]=0;
        }

        //At the first pass calculate the sum of points for each player at game end. 
        //Let M be the maximum of these sums. At the second pass check every round. 
        //If current player X has not less than M points and his final score is equal to M then he is the winner.
        //The following test illustrates that player could receive more than M points, then lose some and, finally, win.
        //Input:
        //Masha 12
        //Masha -5
        //Sasha 10
        //Masha 3
        //Output:
        //Masha

        string name;ll maxm=INT_MIN,cnt=0;
        for(ll i=1;i<=n;i++){ mp[v[i].ff]+=v[i].ss; }
        for(auto val:mp){ if(val.ss>maxm){name=val.ff; maxm=val.ss;} }
        for(auto val:mp){if(val.ss==maxm){cnt++;}}

        if(cnt==1){cout<<name;}
        else{
                ll i=1,m=mp.size(); vector<vector<ll>>a(m+1,vector<ll>(n+1,0));
                map<string,ll>mp2; ll r,x=0;
                for(auto val:mp){
                        mp2[val.ff]=i; i++;
                }
                for(ll i=1;i<=n;i++){
                        ll x=mp2[v[i].ff];
                        ll y=v[i].ss;
                        for(ll j=1;j<=m;j++){
                                if(j==x){a[j][i]=a[j][i-1]+y;}
                                else{a[j][i]=a[j][i-1];}
                        }
                }
                for(ll i=1;i<=n;i++){
                        for(ll j=1;j<=m;j++){
                                if(a[j][i]>=maxm && a[j][n]==maxm){r=j;x++;break;}
                        }
                        if(x>0){break;}
                }
                for(auto val:mp2){
                        if(val.ss==r){name=val.ff;break;}
                }
                cout<<name;
        }
}
