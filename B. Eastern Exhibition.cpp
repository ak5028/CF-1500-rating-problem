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

//At first let's see that the problem is not two dimensional. If we change the x coordinate the sum of distances by y
//is not changed at all. So we just need to calculate the number of good points on a line with points having coordinates x and then y and multiply the answers.
//Now to calculate the answer on a line we could use a known fact: point with the smallest summary distance is between left and right median. So now we only need to sort the array and find the elements on positions ⌊n+12⌋
//and ⌊n+22⌋ and return their difference plus one.

long long solve(vector<int> x) {
    sort(x.begin(), x.end());
    return x[x.size() / 2] - x[(x.size() - 1) / 2] + 1;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    cout << solve(x) * solve(y) << '\n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
