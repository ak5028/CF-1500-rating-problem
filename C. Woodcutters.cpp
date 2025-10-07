//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
        ll n;cin>>n; ll x[n],h[n],cnt=0,z;
        for(ll i=0;i<n;i++){cin>>x[i]>>h[i];}ll y=x[0];

        //iteratively check for each tree that it can be fell or not 
        //and for each tree there is two posn right or left (we start from left)
        //first and last tree always fell in left and right.
        //for others agr vo left mein gir rha hai tohagle vale pr koi impact nhi pdhega uske pass dono posn hogi right and left
        //but agr right mein girta hai toh vo tree kuch portion occupy kr lega so vo portion minus krke bcha hua 
        //vo bcha hua agle vale k liye available hoga and right vala toh hoga hi obviously.
        
        for(ll i=1;i<n-1;i++){
                if(x[i]-y>h[i]){cnt++;y=x[i];}
                else if(x[i+1]-x[i]>h[i]){cnt++;y=x[i]+h[i];}
                else{y=x[i];}
        }
        if(n<2){z=1;}else{z=2;}
        cout<<cnt+z<<endl;
}
