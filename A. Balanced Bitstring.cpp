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
        ll n,k;cin>>n>>k;
        string s;cin>>s;ll p0=0,p1=0,o=0,z=0,q=0;
        for(ll i=0;i<k;i++){
            if(s[i]=='1'){o++;}
            if(s[i]=='0'){z++;}
            if(s[i]=='?'){q++;}
        }

        //we make sliding window of k size. last char mtlb jo chodd rhe hai and next element mtlb jo nya elemnt hmm sliding window mein include kr rhe hai.
        //if last char is 1 then there is 3 option in next char 0,1,? . if next is 1 then no harm kyki jo chodd rhe hai whi mil rha hai 
        //if next is 0 then print no answer bcz not balance of 0 and 1(count become diff),if next is ? then no harm bcz we set ? is 1 and count remains same.(same do when last element is 0.)
        //when last char is ? then 3 option in next char 1,0,?. in this we use ki uss k window mein kitne ? 1 k liye hai and kitne ? 0 k liye
        //if next is ? then no harm bcz (count remain same )ki wo ? kisi ka bhi ho 0 ya 1 ka toh hmm uss next wale ko mann lenge.
        //if next is 1 then dekho ki count of (? for 1) should be >0 so that ki hmm uss ? ki jgah 1 aa rha hai to koi problem nhi hogi.(hmm ? ko 1 mann lenge)
        //if next is 0 then dekho ki count of (? for 0) should be >0 so that ki hmm uss ? ki jgah 0 aa rha hai to koi problem nhi hogi.(hmm ? ko 0 mann lenge)

        if(q==0 && o!=z){cout<<"NO"<<endl;continue;}
        if(q!=0 && o==z){p0+=q/2;p1+=q/2;}
        if(q!=0 && o!=z){
            ll m1=min(o,z);
            ll m2=max(o,z);
            if(m1+q<m2){cout<<"NO"<<endl;continue;}
            if(o>z){
                p0=o-z;
                q-=p0;
                p1+=(q/2);p0+=(q/2);
            }
            else if(z>o){
                p1=z-o;
                q-=p1;
                p0+=(q/2);p1+=(q/2);
            }
        }
        ll x=0;
        for(ll i=k;i<n;i++){
            char c1=s[i-k];
            char c2=s[i];
            if(c1=='1'){
                if(c2=='1'){continue;}
                if(c2=='?'){s[i]='1';continue;}
                if(c2=='0'){x++;break;}
            }
            if(c1=='0'){
                if(c2=='0'){continue;}
                if(c2=='?'){s[i]='0';continue;}
                if(c2=='1'){x++;break;}
            }
            if(c1=='?'){
                if(c2=='?'){continue;}
                if(c2=='1'){
                    if(p1>0){
                        p1-=1;continue;
                    }
                    else{x++;break;}
                }
                if(c2=='0'){
                    if(p0>0){
                        p0-=1;continue;
                    }
                    else{x++;break;}
                }
            }
        }
        if(x>0){cout<<"NO"<<endl;}
        else{cout<<"YES"<<endl;}
    }
}
