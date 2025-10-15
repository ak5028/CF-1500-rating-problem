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
        int a[n],x=0,y=0,cnt=0;
        for(int i=0;i<n;i++){cin>>a[i];x^=a[i];}

        //if same element count is even then xor will be 0 and if count is odd then xor will be same no.
        //so for even we directly check xor of all elemnent will bw zero 
        //and for odd we check that x will ocuur odd times after taking xor of elemant.
                
        if(x==0){cout<<"YES"<<endl;}
        else{
                for(int i=0;i<n;i++){
                        y^=a[i];
                        if(y==x){cnt++;y=0;}
                }
                if(cnt%2!=0 && y==0 && cnt>1){cout<<"YES"<<endl;}
                else{cout<<"NO"<<endl;}
        }

    }
}
