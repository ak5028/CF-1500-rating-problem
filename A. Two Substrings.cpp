//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 

int main(){
        string s;cin>>s;
        int x=0,y=0,cnt=0,z=0,r=0,n=s.size();
        for(int i=0;i<s.size()-1;i++){
                if(i+2<n && s[i]=='A' && s[i+1]=='B' && s[i+2]=='A' ){i+=2;z++;}
                else if(i+2<n && s[i]=='B' && s[i+1]=='A' && s[i+2]=='B' ){i+=2;r++;}
                else if(s[i]=='A' && s[i+1]=='B' && x==0){i++;cnt++;x++;}
                else if(s[i]=='B' && s[i+1]=='A' && y==0){i++;cnt++;y++;}
                if(cnt==2){break;}
        }
        if(cnt==2){cout<<"YES"<<endl;}
        else if(z>0 && r>0){cout<<"YES"<<endl;}
        else if(z>0 && (x>0 || y>0)){cout<<"YES"<<endl;}
        else if(r>0 && (x>0 || y>0)){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
}
