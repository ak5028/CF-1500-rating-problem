//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
    ll k;cin>>k; string s="codeforces"; int a,b;
    if(k==1){cout<<s<<endl;}
    else{
    ll x=1; vector<int>v(10,1);

    //we will make like c..co..od..de..ef..fo..or..rc..ce..es..s and we equally inc the character until x>=k
    
    while(x<k){
       for(int i=0;i<10;i++){
           x/=v[i];
           v[i]++;
           x*=v[i];
           if(x>=k){break;}
       }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<v[i];j++){
                cout<<s[i];
        }
    }
}
}
