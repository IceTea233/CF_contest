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

int n, m;
int a[maxn] = {};
int bit[maxn] = {};

void add(int x, int d) {
    while (x <= n*m) {
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
    return ret;
}

int sum(int l, int r) {
    return query(r) - query(l-1);
}

bool cmp(int a, int b) {
    int r1 = (a - 1) / m + 1;
    int c1 = (a - 1) % m + 1;
    int r2 = (b - 1) / m + 1;
    int c2 = (b - 1) % m + 1;

    if (r1 == r2)
        return c1 < c2;
    else
        return r1 > r2;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {

        cin >> n >> m;

        memset(bit, 0, sizeof(int) * (n*m+1));
        for (int i=1; i<=n*m; i++) {
            scanf("%lld", &a[i]);
        }

        vector<int> keep;
        for (int i=1; i<=n*m; i++)
            keep.PB({a[i]});
        sort(all(keep));

        map<int, vector<int>> pos;
        for (int i=1; i<=n*m; i++)
            pos[keep[i-1]].PB(i);

        for (auto &it : pos) {
            sort(all(it.S), cmp);
        }

        int ans = 0;
        for (int i=1; i<=n*m; i++) {
            int k = pos[a[i]].back();
            pos[a[i]].PP();
            int r = (k - 1) / m + 1;
            int c = (k - 1) % m + 1;
            // printf("[%lld, %lld]\n", m * (r - 1) + 1, m * (r - 1) + c);
            ans += sum(m * (r - 1) + 1, m * (r - 1) + c);
            add(m * (r - 1) + c, 1);
        }

        printf("%lld\n", ans);
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
