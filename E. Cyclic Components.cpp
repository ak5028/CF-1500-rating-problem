//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;

vector<int>adj[200001];
vector<int>visited(200001);
bool check;
void dfs(int s){
    if(adj[s].size()!=2){check=false;}
    if(visited[s]){return;}
    visited[s]=true;
    for(auto u:adj[s]){
        dfs(u);
    }
}

int main(){
    int n,m,cnt=0;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            check=true;
            dfs(i);
            if(check){cnt++;}
        }
    }
    cout<<cnt;
}
