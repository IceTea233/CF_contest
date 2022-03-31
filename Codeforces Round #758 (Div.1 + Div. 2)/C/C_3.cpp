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

int a[maxn] = {};
int b[maxn] = {};
int suf_max[maxn] = {};
int suf_min[maxn] = {};
int ans[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld", &b[i]);

        vector<array<int,3>> keep;

        for (int i=1; i<=n; i++) {
            keep.PB({a[i], b[i], i});
        }
        suf_min[n+1] = INF;
        suf_max[n+1] = 0;
        sort(all(keep));
        for (int i=n; i>=1; i--) {
            suf_max[i] = max(keep[i-1][1], suf_max[n+1]);
            suf_min[i] = min(keep[i-1][1], suf_min[n+1]);
        }
        // for (int i=1; i<=n; i++) {
        //     printf("%lld ", suf_max[i]);
        // }
        // printf("\n");
        // for (int i=1; i<=n; i++) {
        //     printf("%lld ", suf_min[i]);
        // }
        // printf("\n");
        int idx = 1;
        int maxi = 0;
        for (auto it : keep) {
            while(idx <= n && suf_min[idx] <= maxi) {
                maxi = max(maxi, keep[idx-1][1]);
                idx ++;
            }
            printf("maxi = %lld, idx = %lld\n", maxi, idx);
            if (maxi > suf_max[idx]) {
                ans[it[2]] = 1;
            } else {
                ans[it[2]] = 0;
            }
        }
        for (int i=1; i<=n; i++)
            printf("%lld", ans[i]);
        printf("\n");
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
