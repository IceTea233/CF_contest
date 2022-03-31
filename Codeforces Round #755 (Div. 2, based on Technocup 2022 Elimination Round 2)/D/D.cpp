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

int query(int l, int r) {
    printf("? %lld %lld\n", l, r);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

bool find(int l, int r, int x) {
    if (l == r)
        return l == x;
    int m = (l + r) / 2;
    if (l * (l + 1) / 2 >= x)
        return find(l, m, x);
    else
        return find(m+1, r, x);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        int a = n - 2;
        int b = n - 1;
        int c = n;
        int tt = query(1, n);

        int l = 1;
        int r = a;
        while (l < r) {
            printf("bs(%lld, %lld)\n", l, r);
            int m = (l + r + 1) / 2;
            int q = query(1, m);

            if (!find(1, b, q))
                b = m;
            if (q == tt)
                c = m;

            if (q == 0)
                //bs(m, r)
                l = m;
            else
                r = m - 1;
        }
        a = r;

        l = a + 1;
        r = b;
        while (l < r) {
            printf("bs(%lld, %lld)\n", l, r);
            int m = (l + r + 1) / 2;
            int q = query(1, m);

            if (!find(1, b, q))
                b = m;
            if (q == tt)
                c = m;

            if (q == 0)
                //bs(m, r)
                l = m;
            else
                r = m - 1;
        }

        printf("! %lld %lld %lld\n", a, b, c);
        fflush(stdout);
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
