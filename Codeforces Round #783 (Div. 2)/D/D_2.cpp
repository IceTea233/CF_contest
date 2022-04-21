#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e5 + 7;

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1, 0);
        vector<int> dp(n + 1, 0);
        vector<int> pre(n + 1, 0);

        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i];
        }

        map<int, int, greater<int>> st1; // (pre, val)
        map<int, int, less<int>> st2;

        st1[0] = 0;
        st2[0] = 0;
        for (int i=1; i<=n; i++) {
            auto it = st1.upper_bound(pre[i]);
            int val1 = (it == st1.end() ? -INF : it->S + i);
            int val2 = 0;
            if (a[i] > 0)
                val2 = 1;
            else if (a[i] < 0)
                val2 = -1;
            dp[i] = max(val1, dp[i-1] + val2);

            it = st1.lower_bound(pre[i]);
            if (it == end(st1) || it->S < dp[i] - i) {
                st1[pre[i]] = dp[i] - i;
                it = st1.lower_bound(pre[i]);
                while (it != begin(st1) && prev(it)->S <= it->S) {
                    st1.erase(prev(it));
                }
            }
        }

        int ans = dp[n];
        printf("%lld\n", ans);
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
