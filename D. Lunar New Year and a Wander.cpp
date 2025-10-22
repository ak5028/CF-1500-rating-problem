//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll setbits(ll n){ return __builtin_popcountll(n); }
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set st;

vector<int>adj[100001];
vector<bool>visited(100001);

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    //Perform BFS with a min-heap from 1, always expanding the smallest frontier node; mark visited upon push.
    priority_queue<int,vector<int>,greater<int>>q;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int s=q.top(); q.pop();
        cout<<s<<" ";
        for(auto u:adj[s]){
            if(!visited[u]){q.push(u); visited[u]=true;}
        }
    }
}
