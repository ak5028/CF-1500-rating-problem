//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    map<char,ll>mp; ll j=0,maxm=INT_MIN;

    //This problem can be solved with help of two pointers. 
    //Let the first pointer is l and the second pointer is r. 
    //Then for every position l we will move right end r until on the substring s[l]s[l+1]... s[r] it is possible to make no more than k swaps to make this substring beautiful.
    // Then we need to update the answer with length of this substring and move l to the right.


    for(ll i=0;i<n;i++){
        mp[s[i]]++;
        if(min(mp['a'],mp['b'])>k){
                mp[s[j]]--;
                j++;
        }
        else{
                maxm=max(maxm,i-j+1);
        }
    }
    cout<<maxm;
}
