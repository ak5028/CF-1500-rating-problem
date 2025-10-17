//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set st;

vector<int>adj[100001];
int main(){
    int n;cin>>n; int node=-1,k=0,j=3,x=0; 
    vector<pair<int,int>>v;
    int ans[n-1];
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        v.pb({x,y});
    }

    //jo bhi node ke neigbours >2 honge hmm uske negihbor k edges pr 0,1,2 daal denge basizaaly diff branches pr.
    //usse ye hoga ki hmm jo bhi path lenge usmein koi na koi inn tino (0,1,2)mein se missing hoga aur whi mex hoga.
    //isliye ismein o maximum mex hoga wo 2 hoga if there is a node which have >2 degree otherwise n-1 hoga bcz wo tree abb straight hoga toh uss mein 0 to n-2 tk saari aa jayegi if we chosse ending nodes.

    for(int i=1;i<=n;i++){
        if(adj[i].size()>2){node=i;break;}
    }if(node==-1){j=0;}
    for(int i=0;i<n-1;i++){
        if((v[i].ff==node || v[i].ss==node) && x==0){ans[i]=k;k++; if(k==3){x=1;}}
        else{ans[i]=j;j++;}
    }
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<endl;
    }
}

//ENGLISH
    //Notice that there will be a path that passes through the edge labeled 0 and the edge labeled 1
    //no matter how you label the edges, so there's always a path with MEX 2
    //or more. If any node has degree 3 or more, you can distribute the labels 0, 1, and 2
    //to edges incident to this node and distribute the rest of the labels arbitrarily. 
    //Otherwise, the tree is a bamboo, and it doesn't actually matter how you label the edges, since there will be a path with MEX n−1 anyway.
