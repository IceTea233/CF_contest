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

int n, k;
int a[maxn] = {};
int val[maxn] = {};
vector<int> G[maxn];

int cnt;
void dfs(int x, int p) {
    val[x] = a[x];
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x);

        if (val[y] != k)
            val[x] ^= val[y];
    }

    if (val[x] == k) {
        cnt ++;
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {

        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            G[i].clear();
        }

        for (int i=1; i<=n-1; i++) {
            int u, v;
            cin >> u >> v;
        }

        cnt = 0;
        dfs(1, 0);
        printf("%lld, %lld\n", val[1], cnt);
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
