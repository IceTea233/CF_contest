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
const int maxn = 5e2 + 7;
const int MOD = 998244353;

int frac[maxn] = {};

void prepare() {
    frac[0] = 1;
    for (int i=1; i<maxn; i++)
        frac[i] = frac[i-1] * i % MOD;
}

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, MOD - 2);
}

int C(int a, int b) {
    return frac[a] * inv(frac[b]) % MOD * inv(frac[a - b]) % MOD;
}

int solve(int n, int x) {
    int cal = 0;
    for (int i=x; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            int add = C(n, j) * pwr(i - 1, n - j);
        }
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,x;

    prepare();
    cin >> n >> x;
    int cal1 = pwr(x-1, n);
    int cal2 = solve(n, x);

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
