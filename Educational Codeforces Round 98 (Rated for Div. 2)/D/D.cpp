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

int pwr(int x, int k) {
    int ret = 1;
    while(k) {
        if (k&1) {
            ret = ret * x % MOD;
        }

        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int fac[maxn] = {1};
void prepare(int n) {
    for (int i=1; i<=n; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
}

int C(int a, int b) {
    return fac[a] * pwr(fac[b], MOD-2) % MOD * pwr(fac[a-b], MOD-2) % MOD;
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    prepare(n);
    int down = pwr(2, n);
    int up = 0;
    for (int i=0; (n-1) - i*2 >= 0; i++) {
        // printf("C(%lld, %lld)>>> %lld\n", n-1-i, n-1-i*2,C(n-1-i, (n-1)-i*2));
        up += C(n-1-i, (n-1)-i*2);
        up %= MOD;
    }
    int ans = up * pwr(down, MOD-2) % MOD;
    printf("%lld\n", ans);

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
