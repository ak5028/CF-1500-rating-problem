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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n+1],j=0; map<int,int>mp1,mp2; vector<int>v(n+1,-1);
        for(int i=1;i<=n;i++){cin>>a[i]; mp1[a[i]]=0; mp2[a[i]]=INT_MIN;}

        //Let's fix some arbitrary number x and calculate the minimum value of k
        //such that x occurs in all segments of length k. Let p1<p2<⋯<pm be the indices of entries of x in the array.
        //Then, for each 1≤i<m it is clear that k should be at least the value of pi+1−pi
        //Also, k≥p1 and k≥n−pm+1. It is enough to just take the maximum of those values. Let's call this derived value of k as f(x)
        //Now, we can just go in increasing order of x from 1 to n and try update the suffix [f(x),n]  with x
        //This can be done straightforwardly, just iterating over the range [f(x),n]. If we arrive at a cell for which the value of x
        //is already calculated, we immediately terminate our loop and continue our algorithm from x+1
            
        for(int i=1;i<=n;i++){
            int diff=i-mp1[a[i]];
            mp2[a[i]]=max(mp2[a[i]],diff);
            mp1[a[i]]=i;
        }
        for(auto val:mp1){
            int i=val.ss;
            int b=val.ff;
            int diff=n+1-i;
            mp2[b]=max(mp2[b],diff);
        }

        for(auto val:mp2){
            int a=val.ff;
            int b=val.ss;
            if(v[b]==-1){v[b]=a;}
        }


        int x=0,minm=INT_MAX;
        for(int i=1;i<=n;i++){
            if(x==0 && v[i]==-1){cout<<-1<<" ";}
            else{
                x=1;
                if(v[i]!=-1){minm=min(minm,v[i]);}
                cout<<minm<<" ";
            }
        }cout<<endl;
    }
}
