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
const int maxn = 2e5 + 7;

int a[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        bool ans = true;
        if (x > n / 2) {
            int l = n - x + 1;
            int r = x;

            for (int i = l; i <= r; i++) {
                if (i > l && a[i] < a[i-1]) {
                    ans = false;
                }
            }

            for (int i=1; i < l; i++) {
                if (a[l] < a[i] && a[i] < a[r])
                    ans = false;
            }
            for (int i=r+1; i <= n; i++) {
                if (a[l] < a[i] && a[i] < a[r])
                    ans = false;
            }

            int lcnt = 0;
            int rcnt = 0;
            for (int i=1; i < l; i++) {
                if (a[i] < a[r])
                    lcnt++;
                else if (a[i] > a[l])
                    rcnt++;
            }
            for (int i=r+1; i <= n; i++) {
                if (a[i] < a[r])
                    lcnt++;
                else if (a[i] > a[l])
                    rcnt++;
            }
            if (lcnt > n - x || rcnt > n - x)
                ans = false;
        }

        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
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
