//AKJ
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll setbits(ll n){ return __builtin_popcountll(n); }
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
//ordered_set st;
bool check(int n) {
        // Check if integer n is a palindrome by comparing the string with its reverse
        string s = to_string(n);
        string str = s;
        reverse(s.begin(), s.end());
        return (s == str);
}

const int M = 1e9 + 7;
const int N = 4e4 + 5;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        // Generate all palindromic numbers up to N - 1 (these are the "coins")
        vector<int> a;
        for (int i = 1; i < N; i++) {
                if (check(i))
                        a.push_back(i);
        }
        int sz = a.size();

        // dp[x] stores number of ways to form sum x using palindromic numbers (order doesn't matter)
        vector<int> dp(N, 0);
        dp[0] = 1; // One way to make sum 0: choose nothing

        // Unbounded knapsack (coin change - combinations): iterate over coins first
        for (int i = 0; i < sz; i++) {
                for (int x = 1; x < N; x++) {
                        if (x - a[i] >= 0)
                                dp[x] = (dp[x] + dp[x - a[i]]) % M; // Use unlimited copies of a[i]
                }
        }

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                cout << dp[n] << '\n'; // Answer each query in O(1) from precomputed dp
        }

        return 0;
}
