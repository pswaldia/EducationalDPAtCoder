#include<bits/stdc++.h>
using namespace std;

#include<algorithm>
#define str(a) to_string(a)
#define int long long
#define pb push_back
#define mp make_pair
#define SORT(c) sort(c.begin(),c.end())
#define max_heap priority_queue<int>
#define min_heap priority_queue< int,vector<int>, greater<int> >
#define mod 1000000007
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define inf LLONG_MAX
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define N 1000001

// top down + memoisation......
int MinimizingCoinsI(vector<int>&nums, int amount, vector<int>&dp) {
    if (amount == 0)
        return 1;
    if (dp[amount] != -1)
        return dp[amount];
    int count = 0;
    for (int coin : nums) {
        if (coin <= amount)
            count = (count % mod + (MinimizingCoinsI(nums, amount - coin, dp)) % mod) % mod;
    }
    return dp[amount] = count;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(m + 1, -1);
    int ans = MinimizingCoinsI(a, m, dp);
    cout << ans << endl;

}