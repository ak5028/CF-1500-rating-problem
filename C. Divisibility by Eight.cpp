//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 

int main(){
        
        //if last 3-digit is divisible by 8 then whole no.is divisible by 8
        //so naively make all 1,2,3 combinations of characters and check it is divisible by 8 or not
        string s;cin>>s;int z=0,n=s.size();
        for(int i=0;i<n;i++){
                if(s[i]=='0'){cout<<"YES"<<endl<<0;z++;break;}
                if(s[i]=='8'){cout<<"YES"<<endl<<8;z++;break;}
        }
        if(z==0){
        for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                        string t; t.append(1,s[i]);t.append(1,s[j]);
                        int x=stoi(t);
                        if(x%8==0){cout<<"YES"<<endl<<t;z++;break;}
                }
                if(z>0){break;}
        }}
        if(z==0){
        for(int i=0;i<n-2;i++){
                for(int j=i+1;j<n-1;j++){
                        for(int k=j+1;k<n;k++){
                                string t; t.append(1,s[i]);t.append(1,s[j]);t.append(1,s[k]);
                                int x=stoi(t);
                                if(x%8==0){cout<<"YES"<<endl<<t;z++;break;}
                        }
                        if(z>0){break;}
                }
                if(z>0){break;}
        }}
        if(z==0){cout<<"NO"<<endl;}
}
