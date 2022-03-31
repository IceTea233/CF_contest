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
int b[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }

        int add1 = INF;
        int add2 = INF;
        for (int i=1; i<=n; i++) {
            add1 = min(add1, abs(a[n] - b[i]));
            add2 = min(add2, abs(b[n] - a[i]));
        }
        int ans1 = abs(a[1] - b[1]) + min(add1 + add2, abs(a[n] - b[n]));

        add1 = INF;
        add2 = INF;
        for (int i=1; i<=n; i++) {
            add1 = min(add1, abs(a[n] - b[i]));
            add2 = min(add2, abs(b[1] - a[i]));
        }
        int ans2 = abs(a[1] - b[n]) + min(add1 + add2, abs(a[n] - b[1]));

        add1 = INF;
        add2 = INF;
        for (int i=1; i<=n; i++) {
            add1 = min(add1, abs(a[1] - b[i]));
            add2 = min(add2, abs(b[1] - a[i]));
        }
        int ans3 = abs(a[n] - b[n]) + min(add1 + add2, abs(a[1] - b[1]));

        add1 = INF;
        add2 = INF;
        for (int i=1; i<=n; i++) {
            add1 = min(add1, abs(a[1] - b[i]));
            add2 = min(add2, abs(b[n] - a[i]));
        }
        int ans4 = abs(a[n] - b[1]) + min(add1 + add2, abs(a[1] - b[n]));

        add1 = INF;
        add2 = INF;
        int add3 = INF;
        int add4 = INF;
        for (int i=1; i<=n; i++) {
            add1 = min(add1, abs(a[1] - b[i]));
            add2 = min(add2, abs(a[n] - b[i]));
            add3 = min(add3, abs(b[1] - a[i]));
            add4 = min(add4, abs(b[n] - a[i]));
        }
        int ans5 = add1 + add2 + add3 + add4;
        // printf(">>> %lld, %lld, %lld\n", ans1, ans2, ans3);
        int ans = min({ans1, ans2, ans3, ans4, ans5});
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
