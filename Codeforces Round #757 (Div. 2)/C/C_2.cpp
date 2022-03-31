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
const int maxn = 2e5 + 7;
const int MOD = 1000000007;

int arr[maxn] = {};
int l[maxn] = {};
int r[maxn] = {};
int x[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;

        vector<array<int,3>> keep;
        int maxi = 0;
        for (int i=1; i<=m; i++) {
            scanf("%lld %lld %lld", &l[i], &r[i], &x[i]);
            keep.PB({l[i], r[i], x[i]});
            maxi = max(maxi, x[i]);
        }
        sort(all(keep));

        int ans = 0;
        for (int b=0; (1LL<<b) <= maxi; b++) {
            for (i=0, j=1; i<m; i++) {
                int li = keep[i][0];
                int ri = keep[i][1];
                int xi = keep[i][2];
                if ((xi>>b)&1) {
                    continue;
                }
                while (j < li) {
                    arr[j++] = 1;
                }
                for (j = li; j<=ri; j++) {
                    arr[j] = 0;
                }
            }

            while (j <= n)
                arr[j++] = 1;

            de(1) {
                for (int i=1; i<=n; i++)
                    printf("%lld ", arr[i]);
                printf("\n");
            }

            int odd = 0;
            int even = 1;
            for (int i=1; i <= n; i++) {
                int last_odd = odd;
                int last_even = even;
                if (arr[i] == 0) {
                    odd = last_odd * 2 % MOD;
                    even = last_even * 2 % MOD;
                } else {
                    odd = (last_even + last_odd) % MOD;
                    even = (last_even + last_odd) % MOD;
                }
            }

            // printf("cnt = %lld\n", cnt);
            ans = (ans + odd * (1LL<<b) % MOD) % MOD;
            // printf("asn += %lld\n", cnt * (1LL<<b));
        }

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
