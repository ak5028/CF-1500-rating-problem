//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}

    // we skip all zeroes and after ending of zero sequence ,friend not start with sequence of 1 as it is more costier.
        
    int ans=0;
    bool turn =true;
    for(int i=0;i<n;i++){
        if(a[i]==0){turn=false; continue;}
        if(turn){
            turn=false;
            ans++;
        }
        else{
            turn=true;
            if(i+1<n && a[i+1]==1){i++; continue;}
        }
    }
    cout<<ans<<endl;
}
}
