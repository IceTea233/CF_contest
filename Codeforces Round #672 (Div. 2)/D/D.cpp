#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 3e5 + 7;
const int MOD = 998244353;

vector<pii> keep;

struct event {
    int type;
    int idx;

    bool operator<(event b) {
        if (idx == b.idx)
            return type < b.type;
        return idx < b.idx;
    }
};

int pwr(int x, int k) {
    int ret = 1;
    while(k) {
        if (k&1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int fac[maxn] = {};
void prepare(int n) {
    fac[0] = 1;
    for (int i=1; i<=n; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
}

int C(int a, int b) {
    return fac[a] * pwr( fac[b], MOD-2) % MOD * pwr( fac[a-b], MOD-2) % MOD;
}

main() {
    int i,j;
    int n,k;

    cin >> n >> k;
    prepare(n);

    vector<event> keep;
    for (int i=1; i<=n; i++) {
        int l,r;
        cin >> l >> r;
        keep.PB({1, l});
        keep.PB({2, r});
    }
    sort(all(keep));
    int ans = 0;
    int cnt = 0;
    for (auto it:keep) {
        de(1) printf("event : (%lld, %lld)\n", it.type, it.idx);
        if (it.type == 1) {
            if (cnt >= k-1) {
                ans += C(cnt, k-1);
                ans %= MOD;
            }
            cnt++;
        } else {
            cnt--;
        }
    }

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
