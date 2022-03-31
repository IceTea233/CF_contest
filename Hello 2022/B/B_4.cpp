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
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int l[maxn], r[maxn], c[maxn];

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i <= n; i++) {
            cin >> l[i] >> r[i] >> c[i];
        }

        int mini_idx = 0;
        int maxi_idx = 0;
        int all_idx = 0;
        for (int i=1; i<=n; i++) {
            if (!mini_idx || l[i] < l[mini_idx] || l[i] == l[mini_idx] && c[i] < c[mini_idx])
                mini_idx = i;
            if (!maxi_idx || r[i] > r[maxi_idx] || r[i] == r[maxi_idx] && c[i] < c[maxi_idx])
                maxi_idx = i;
            if (!all_idx || l[i] < l[all_idx] || l[i] == l[all_idx] && r[i] > r[all_idx] ||
                l[i] == l[all_idx] && r[i] == r[all_idx] && c[i] < c[all_idx])
                all_idx = i;

            int ans = 0;
            if (l[all_idx] <= l[mini_idx] && r[all_idx] >= r[maxi_idx]) {
                if (l[all_idx] == l[mini_idx] && r[all_idx] == r[maxi_idx]) {
                    ans = min(c[all_idx], c[mini_idx] + c[maxi_idx]);
                } else {
                    ans = c[all_idx];
                }
            } else {
                ans = c[mini_idx] + c[maxi_idx];
            }

            // cerr << ">>> " << mini_idx << ", " << maxi_idx << ", " << all_idx << "\n";
            // cerr << "ans = ";
            printf("%lld\n", ans);
        }
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
