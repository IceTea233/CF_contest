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
const int maxn = 1e2 + 7;

int n, k;
int a[maxn] = {};
int d[maxn] = {};

void prepare() {
    d[0] = 1;
    for (int i=1; i<=18; i++)
        d[i] = d[i-1] * 10;
}

bool chk(int x) {
    int cnt = 0;
    for (int i=n; i>=1; i--) {
        cnt += x / d[a[i]];
        x /= d[a[i]];
    }
    return cnt > k;
}

int bs(int l, int r) {
    printf("(%lld, %lld)\n", l, r);
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (chk(m))
        return bs(l, m);
    else
        return bs(m+1, r);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    prepare();
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i=1; i<=n; i++)
            cin >> a[i];
        a[n+1] = 18;
        int ans = 0;
        k++;
        for (int i=1; i<=n; i++) {
            int num = min(k, d[a[i+1] - a[i]] - 1);
            // printf("num = %lld\n", num);
            k -= num;
            ans += d[a[i]] * num;
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
