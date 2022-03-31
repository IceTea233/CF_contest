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

struct edge {
    int des;
    int id;
};

vector<edge> G[maxn];
int ans[maxn] = {};

void dfs(int x, int p = -1, int pre = 3) {
    // printf("dfs(%lld, %lld, %lld)\n", x, p, pre);
    for (auto nxt : G[x]) {
        if (nxt.des == p)
            continue;

        // printf("nxt id = %lld\n", nxt.id);
        if (pre == 3) {
            ans[nxt.id] = 2;
            dfs(nxt.des, x, 2);
        } else {
            ans[nxt.id] = 3;
            dfs(nxt.des, x, 3);
        }
    }
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
            G[i].clear();
            ans[i] = -1;
        }
        for (int i=1; i<=n-1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].PB({v, i});
            G[v].PB({u, i});
        }

        bool flag = false;
        for (int i=1; i<=n; i++) {
            if (G[i].size() >= 3) {
                flag = true;
                break;
            }
        }

        if (flag) {
            printf("-1\n");
            continue;
        }

        for (int i=1; i <= n; i++) {
            if (G[i].size() == 1) {
                dfs(i);
                break;
            }
        }
        for (int i=1; i<=n-1; i++)
            printf("%lld ", ans[i]);
        printf("\n");
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
