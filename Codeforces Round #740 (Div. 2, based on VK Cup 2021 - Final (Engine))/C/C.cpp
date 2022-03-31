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

vector<int> monster[maxn] = {};
int gate[maxn] = {};
vector<pii> order;

bool chk(int x) {
    for (auto &it : order) {
        if (x < it.F)
            return false;
        x += monster[it.S].size();
    }
    return true;
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
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int k;
            scanf("%lld", &k);
            monster[i].clear();
            for (int j=1; j<=k; j++) {
                int a;
                scanf("%lld", &a);
                monster[i].PB(a);
            }
        }

        for (int i=1; i<=n; i++) {
            gate[i] = 0;
            for (int j=0; j<monster[i].size(); j++) {
                // printf("cmp(%lld, %lld - %lld + 1)\n", gate[i], monster[i][j], j);
                gate[i] = max(gate[i], monster[i][j] - j + 1);
            }
        }

        // printf(">>> ");
        // for (int i=1; i<=n; i++)
        //     printf("%lld ", gate[i]);
        // printf("\n");
        order.clear();
        for (int i=1; i<=n; i++) {
            order.PB({gate[i], i});
        }
        sort(all(order));

        int ans = bs(1, 1000000001);
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
