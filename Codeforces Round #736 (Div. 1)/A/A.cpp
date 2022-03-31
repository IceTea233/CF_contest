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

int n, m;
multiset<int> st[maxn];

bool ismax(int x) {
    return st[x].empty() || *prev(st[x].end()) < x;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        scanf("%lld %lld", &u, &v);
        st[u].insert(v);
        st[v].insert(u);
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (ismax(i))
            ans++;
    }
    int q;
    cin >> q;
    while (q--) {
        int cmd;
        scanf("%lld", &cmd);
        if (cmd == 1) {
            int u, v;
            scanf("%lld %lld", &u, &v);

            bool premax_u = ismax(u);
            bool premax_v = ismax(v);
            st[u].insert(v);
            st[v].insert(u);

            ans += ismax(u) - premax_u;
            ans += ismax(v) - premax_v;
        } else if (cmd == 2) {
            int u, v;
            scanf("%lld %lld", &u, &v);

            bool premax_u = ismax(u);
            bool premax_v = ismax(v);
            st[u].erase(st[u].find(v));
            st[v].erase(st[v].find(u));

            ans += ismax(u) - premax_u;
            ans += ismax(v) - premax_v;
        } else if (cmd == 3) {
            printf("%lld\n", ans);
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
