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
const int MOD = 998244353;

int a[maxn] = {};

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
        sort(a+1, a+n+1);
        // for (int i=1; i<=n; i++)
        //     printf("%lld ", a[i]);
        // printf("\n");
        int ans = 0;
        if (a[n] == a[n-1]) {
            ans = 1;
            for (int i=1; i<=n; i++) {
                ans = ans * i % MOD;
            }
        } else if (a[n] == a[n-1] + 1) {
            int cnt1 = 1;
            int cnt2 = 0;
            int cnt3 = 0;
            for (int i=1; i<=n-1; i++) {
                if (a[i] == a[n-1])
                    cnt2 ++;
                else
                    cnt3 ++;
            }
            // printf(">>> %lld %lld %lld\n", cnt1, cnt2, cnt3);

            ans = 1;
            for (int i=1; i<=n; i++) {
                ans = ans * i % MOD;
            }

            int cut = 1;
            for (int i = 1; i <= cnt2; i++) {
                cut = cut * i % MOD;
            }
            for (int i = 1; i <= cnt3; i++) {
                cut = cut * (cnt1 + cnt2 + i) % MOD;
            }
            // printf("cut = %lld\n", cut);
            ans = ((ans - cut) % MOD + MOD) % MOD;
        }

        printf("%lld\n", ans);
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
