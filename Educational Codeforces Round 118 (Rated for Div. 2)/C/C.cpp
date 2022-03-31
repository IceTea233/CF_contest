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

int n, h;
int a[maxn] = {};

bool chk(int x) {
    int sum = 0;
    int cur = 0;
    for (int i=1; i<=n; i++) {
        int add = min(x, a[i] + x - cur);
        sum += add;
        // printf("add= %lld\n", add);
        cur = a[i] + x;
    }
    return sum >= h;
}

int bs(int l, int r) {
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

    cin >> t;
    while (t--) {
        cin >> n >> h;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }
        int ans = bs(1, 1e18 + 1);
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
