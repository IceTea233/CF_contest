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
const int maxn = 2e5 + 7;

int p[maxn] = {};
int a[maxn] = {};
int rem[maxn] = {};
vector<int> G[maxn];

bool flag = 1;
void dfs(int x, int m) {
    for (auto y : G[x]) {
        dfs(y, m);
        rem[x] += rem[y];
    }

    if (G[x].empty())
        rem[x] += m;

    rem[x] -= a[x];
    if (rem[x] < 0)
        flag = 0;
}

bool check(int m) {
    flag = 1;
    memset(rem, 0, sizeof(rem));
    dfs(1, m);
    return flag;
}

int bs(int l, int r) {
    de(1) printf("(%lld, %lld)\n", l, r);
    if (l == r)
        return l;
    int m = ( l + r ) / 2;
    if (check(m))
        return bs(l, m);
    else
        return bs(m+1, r);
}

main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=2; i<=n; i++) {
        scanf("%lld", &p[i]);
        G[ p[i] ].PB(i);
    }
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }

    int ans = bs(0, 1e15);
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
