//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
        ll n,d;cin>>n>>d;
        ll ps[n+1],ind[n+1],maxm=INT_MIN,x,y; ps[0]=0;
        vector<pair<ll,ll>>v; v.pb({-1,-1});
        for(ll i=1;i<=n;i++){cin>>x>>y; v.pb({x,y});}
        sort(all(v));
        
        //first we have to find for each amount the amount for which condn(diff<d) satisfies.
        //so we use binary srch for finding the index at which condn satisfies.
        //so that for all 1 to ind-1 condn not satisfy and for all from ind+1 to i condn satifies.
        //then by making prefix sum array with the use of friendship factor.
        //then for each index i we can esaily find the maxm total factor.
        // so i use binary srch and prefix sum array concept for solving this problem.

        //BINARY SEARCH (for each index i)
        for(ll i=n;i>=1;i--){
                ll s=1,e=i,val=v[i].ff;
                while(s<=e){
                       ll mid=e+(s-e)/2;
                       if(val-v[mid].ff <d){ ind[i]=mid; e=mid-1;}    
                       else{s=mid+1;}                    
                }
        }
        //PREFIX SUM 
        for(ll i=1;i<=n;i++){
                ps[i]=ps[i-1]+v[i].ss;
        }
        //CALCULATE MAXIMUM FACTOR
        for(ll i=1;i<=n;i++){
                maxm=max(maxm,ps[i]-ps[ind[i]-1]);
        }
        cout<<maxm<<endl;
}
