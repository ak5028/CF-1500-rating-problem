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
ll M=1e9+7;
int main(){
        string s;cin >> s; 
        ll cnt=0,p = 1; 
        for (ll i = 0;i<s.size();i++) {
                if(s[i] == 'a')
                        cnt++; 
                else if(s[i] == 'b'){
                        // A 'b' closes the current 'a' block: for this block, we may pick any one 'a' or none => (cnt + 1) choices
                        p = p * (cnt + 1) % M;
                        cnt = 0; // reset for the next block of 'a'
                }
        }
        // Account for the trailing 'a' block (if the string ends with 'a')
        p = p * (cnt + 1) % M;

        // Subtract 1 to exclude the empty selection (no 'a' chosen anywhere)
        ll ans = (p - 1 + M) % M;
        cout << ans << '\n';
}
