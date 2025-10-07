//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
vector<int>adj[100001];
vector<int>curr(100001),maxi(100001,INT_MIN);
map<int,int>mp;
void dfs(int s,int e){
        for(auto u:adj[s]){
                if(u==e){continue;}
                if(mp[u]==1){curr[u]=curr[s]+1; maxi[u]=maxi[s];}
                if(mp[u]==0){curr[u]=0; maxi[u]=max(curr[s],maxi[s]);}
                dfs(u,s);
        }
}

int main(){
        int n,m;cin>>n>>m;
        int x,ans=0;
        for(int i=1;i<=n;i++){cin>>x;mp[i]=x;}
        for(int i=0;i<n-1;i++){
                int u,v;cin>>u>>v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        curr[1]=mp[1];
        dfs(1,0);
        for(int i=2;i<=n;i++){
                if(adj[i].size()==1){
                        int x=max(curr[i],maxi[i]);
                        if(x<=m){ans++;}
                }
        }
        cout<<ans<<endl;
}
