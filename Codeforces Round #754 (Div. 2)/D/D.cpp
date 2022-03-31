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

vector<int> G[maxn] = {};
int tag[maxn] = {};
set<int> clan;
vector<int> cand[maxn];
int ans[maxn] = {};

void dfs(int x, int p=0) {
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
    }

    for (auto it = clan.end(); it != clan.begin(); it--) {
        int c = *prev(it);
        // printf("c = %lld\n", c);
        bool flag = true;
        for (auto y : G[x]) {
            if (y == p)
                continue;
            if (tag[y] == c) {
                flag = false;
                break;
            }
        }

        if (flag) {
            tag[x] = c;
            // printf("x = %lld\n", cand[c].back());
            ans[x] = cand[c].back();
            cand[c].pop_back();
            if (cand[c].empty())
                clan.erase(c);
            break;
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
        }
        clan.clear();

        for (int i=1; i<=n-1; i++) {
            int u, v;
            scanf("%lld %lld", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }

        for (int i=0; (1<<i) <= n; i++) {
            clan.insert(i);
            cand[i].clear();
            for (int j = (1<<i); j < min( (1LL<<(i+1)), n+1); j++) {
                cand[i].PB(j);
            }
        }
        // for (auto it : clan) {
        //     printf("clan %lld: ", it);
        //     for (auto it2 : cand[it])
        //         printf("%lld ", it2);
        //     printf("\n");
        // }
        dfs(1);

        de(1) printf(">>> ");
        for (int i = 1; i <= n; i++)
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
