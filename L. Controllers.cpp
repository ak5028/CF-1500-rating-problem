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
    ll n;cin>>n;
    string s;cin>>s; ll p=0,m=0;
    for(ll i=0;i<n;i++){if(s[i]=='+'){p++;} else{m++;}}
    ll q;cin>>q; 

    //this eqn is valid k1*a+(p-k1)*b-k2*a-(m-k2)*b=0
    //by solving this we get k=k1-k2=(m-p)*b/(a-b) 
    //k should be integer and in the range of [-m,p] then ans is yes else no.

    for(ll i=0;i<q;i++){
        ll a,b;cin>>a>>b; 
        if(p==m){cout<<"YES"<<endl;continue;}
        if(a==b){cout<<"NO"<<endl;continue;}
        ll x=((m-p)*b)/(a-b);
        if(((m-p)*b)%(a-b)==0 && x>=-m && x<=p){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
}
