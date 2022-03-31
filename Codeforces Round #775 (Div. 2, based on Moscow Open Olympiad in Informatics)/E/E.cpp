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
const int MOD = 998244353;

int n, m;
int s[maxn] = {};
int t[maxn] = {};

int frac[maxn] = {};
int fracInv[maxn] = {};

int pwr(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        k >>= 1;
    }
    return ret;
}

void prepare() {
    frac[0] = 1;
    fracInv[0] = 1;
    for (int i=1; i < maxn; i++) {
        frac[i] = frac[i-1] * i % MOD;
        fracInv[i] = pwr(frac[i], MOD - 2);
    }
}

int cnt[maxn] = {};
int bit[maxn] = {};
void add(int x, int d) {
    while (x < maxn) {
        bit[x] += d;
        x += x & (-x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= x & (-x);
    }
    // printf("ret = %lld\n", ret);
    return ret;
}

int Lamda = 1;
int cal(int cur) {
    int cntAll = query(maxn - 1);
    int cntPart = query(cur - 1);
    de(1) printf("cur = %lld, count = %lld / %lld, Lamda = %lld\n", cur, cntPart, cntAll, Lamda);

    int ret = Lamda * cntPart % MOD * pwr(cntAll, MOD - 2) % MOD;
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> m;
    prepare();
    // printf("%lld\n", 3 * frac[2] * fracInv[3] % MOD);
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }

    // calculate count of alpha in s.
    for (int i=1; i<=n; i++) {
        cnt[s[i]] ++;
        add(s[i], 1);
    }

    // calculate initial Lamda.
    Lamda = frac[query(maxn-1)];
    for (int i=1; i<maxn; i++) {
        Lamda = Lamda * fracInv[cnt[i]] % MOD;
    }
    de(1) printf("Lamda = %lld\n", Lamda);

    int ans = 0;
    for (i=1; i<=min(m, n); i++) {
        int cur = t[i];
        // calculate if this position is put an alpha < t[i] using Lamda.
        int inc = cal(cur);
        de(1) printf("add = %lld\n", inc);
        ans = (ans + inc) % MOD;

        // put an alpha from s that equal to t[i], if cannot, then terminate.
        if (cnt[cur] > 0) {
            // update Lamda.
            de(1) printf("cnt[cur] = %lld, all = %lld\n", cnt[cur], query(maxn - 1));
            Lamda = Lamda * cnt[cur] % MOD * pwr(query(maxn - 1), MOD - 2) % MOD;
            de(1) printf("updated Lamda = %lld\n", Lamda);
            cnt[cur] --;
            add(cur, -1);
        }  else {
            break;
        }
    }

    if (query(maxn - 1) == 0 && n != m) {
        ans = (ans + 1) % MOD;
    }

    de(1) printf("ans = ");
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
