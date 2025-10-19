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

int main(){
    ll n,k1,k2;cin>>n>>k1>>k2;
    ll a[n],b[n],res=0,op=k1+k2;
    priority_queue<ll>pq;

    for(ll i=0;i<n;i++){cin>>a[i];}
    for(ll i=0;i<n;i++){cin>>b[i];}
    for(ll i=0;i<n;i++){pq.push(abs(a[i]-b[i]));}
    
    //we store diff of a and b and decrese maximum of these diff by one then op=k1+k2 will be dec by 1.
    //we can do this efficently by using priority queue.
        
    while(!pq.empty()){
        if(op==0 || pq.top()==0){break;}
        ll m=pq.top();
        m-=1;
        pq.pop();
        pq.push(m);
        op-=1;
    }

    while(!pq.empty()){
        ll val=pq.top();
        pq.pop();
        res+=val*val;
    }
    if(op%2!=0){res+=1;}
    cout<<res;
}
