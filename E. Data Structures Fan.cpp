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
        ll n;cin>>n;
        ll a[n+1],o=0,z=0;
        for(ll i=1;i<=n;i++){cin>>a[i];}
        string s;cin>>s;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){z^=a[i+1];}
            else{o^=a[i+1];}
        }

        //in z we store all zero xor and in o all one xor.
        //so for 2nd op we only output o or z if x=1 or 0 in O(1)
        //then for 1st op we make prefix xor p.so with land r we can find uss range k no.s ka xor.
        //by making (1,r)^(1,l-1) , (l,l-1) range comes twice so xor of this range becomes zero in (1,r) so we get xor from (l,r).
        //2nd op mei kya krna hai hme,agr x=0,jitne bhi zero wale elemnt hai unka xor krna hai and whi answer hai.
        //to hmne phle se z mein zero wale elemnt store krva rkhe toh after evry 1st op we have to modify o & z.
        //jaise l se r mein 0 hai toh usko 1 mein convert krna hai toh uss 0 ka elemnt pehle z mein xor tha but abb hmme usse o mein xor krna hai and z mein se htana hai toh ,
        //finally hmm dono o&z k saath hi xor kr rha hai.
        //same for 1 wala element usko 0 mein convert krna h toh pehle wo o mein incude tha usse htana hoga by making xor with o and include in z by making xor with z.toh dono k saath hi xor kiya hai.
        //toh basically hmme hr 1st op k baad o & z mein change hoga and wo change bss uss rnage k elemnt ka xor with o & z both and changes done .
        
        ll p[n+1];
        p[0]=0;
        for(ll i=1;i<=n;i++){
            p[i]=p[i-1]^a[i];
        }
        ll q;cin>>q;
        for(ll i=0;i<q;i++){
            ll op;cin>>op;
            if(op==1){
                ll l,r;cin>>l>>r;
                ll x=p[r]^p[l-1];
                z^=x;o^=x;
            }
            if(op==2){
                ll x;cin>>x;
                if(x==0){cout<<z<<" ";}
                else{cout<<o<<" ";}
            }
        }
        cout<<endl;
    }
}
    
