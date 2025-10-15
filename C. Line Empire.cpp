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
    ll t;cin>>t;
    while(t--){
        ll n,a,b;cin>>n>>a>>b;
        ll arr[n+1],cost=0,s=0;arr[0]=0;
        for(ll i=1;i<=n;i++){cin>>arr[i];}

        //if a>=b then we conquer and move that means total n conquers and n-1 moves.
        //if a<b then for every move we check ki ye move krne pr jo cost hai cost1=(a[i]-a[i-1])*a ye uss cost se bdi hai ya choti.
        //vo cost jo agr hmm move nhi krte toh utni times vo diff agge valo maininclude with multiply by b. cost2=(a[i]-a[i-1])*(n-i)*b
        //if cost2>=cost1 then move krne se hmara fayda hai mtlb cost reduce hga and 
        //if cost2<cost1 mtlb move krne ki cost agr jyada hai toh move nhi krege then hmara pointr vhi pr rhega and abb vhi se sbka diff nikalenge and multiply by b krenge.

        if(a<=b){
            for(ll i=1;i<=n;i++){
                s+=arr[i]-arr[i-1];
            }
            cost+=(b*s);
            cost+=(a*s);
            cost-=(a*(arr[n]-arr[n-1]));
        }
        
        else{
            for(ll i=1;i<=n;i++){
                ll d=arr[i]-arr[i-1];
                cost+=(b*d);
                if(((n-i)*d)*b >= d*a){cost+=d*a;}
                else{
                    ll z=arr[i-1];
                    for(ll j=i+1;j<=n;j++){
                        cost+=(arr[j]-z)*b;
                    }
                    break;
                }
            }
        }
        cout<<cost<<endl;
    }
}
