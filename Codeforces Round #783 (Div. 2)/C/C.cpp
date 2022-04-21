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
const int maxn = 5e3 + 7;

int a[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int ans = INF;
    for (int i=1; i<=n; i++) {
        int tt = 0;
        int cur = 0;
        for (int j=i+1; j<=n; j++) {
            int add = (cur) / a[j] + 1;
            tt += add;
            cur = a[j] * add;

            de(1) printf("cur = %lld\n", cur);
        }

        de(1) printf("--- \n");
        cur = 0;
        for (int j=i-1; j>=1; j--) {
            int add = (cur) / a[j] + 1;
            tt += add;
            cur = a[j] * add;

            de(1) printf("cur = %lld\n", cur);
        }

        ans = min(ans, tt);
    }

    printf("%lld\n", ans);

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
