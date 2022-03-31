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
const int maxn = 5e5 + 7;
const int MOD = 1e9 + 7;

int x[maxn] = {};
int cnt[64] = {};
int mul[64] = {};

void prepare() {
    mul[0] = 1;
    for (int i=1; i<64; i++)
        mul[i] = mul[i-1] * 2 % MOD;
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    prepare();
    while(t--) {
        int n;
        cin >> n;
        memset(cnt, 0 , sizeof(cnt));
        for (int i=1; i<=n; i++)
            scanf("%lld", &x[i]);
        for (int i=1; i<=n; i++) {
            for (int j=0; j<64; j++) {
                if ((x[i]>>j)&1)
                    cnt[j]++;
            }
        }

        int ans = 0;
        for (int i=1; i<=n; i++) {
            int a = 0;

            for (int j=0; j<64; j++) {
                if ((x[i]>>j)&1) {
                    a += mul[j] * cnt[j] % MOD;
                    a %= MOD;
                }
            }
            int b = 0;
            for (int j=0; j<64; j++) {
                if ((x[i]>>j)&1) {
                    b += mul[j] * n % MOD;
                    b %= MOD;
                } else {
                    b += mul[j] * cnt[j] % MOD;
                    b %= MOD;
                }
            }
            ans += a * b % MOD;
            ans %= MOD;
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
