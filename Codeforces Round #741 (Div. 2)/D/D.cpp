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
const int maxn = 3e5 + 7;

int n,q;
int bit[maxn] = {};
char s[maxn] = {};

void add(int x, int d) {
    while (x <= n) {
        bit[x] += d;
        x += (x & -x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= (x & -x);
    }
    return ret;
}

int sum(int l, int r) {
    return query(r) - query(l-1);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        cin >> n >> q;
        scanf("%s", s+1);
        memset(bit, 0, sizeof(int) * (n+1));
        for (int i=1; i<=n; i++) {
            if (i % 2 == 1 && s[i] == '+' || i % 2 == 0 && s[i] == '-')
                add(i, 1);
            else
                add(i, -1);
        }

        while (q--) {
            int a, b;
            scanf("%lld %lld", &a, &b);
            int k = sum(a, b);
            if (k == 0) {
                printf("0\n");
            } else if ((b - a + 1) % 2 == 1) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }
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
