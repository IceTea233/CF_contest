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

int cnt[maxn] = {};
int add[maxn] = {};
int last[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n, m;

    cin >> n >> m;
    vector<vector<int>> c(n + 1);
    for (int i=1; i<=n; i++) {
        c[i].resize(m + 1);
        for (int j=1; j<=m; j++) {
            cin >> c[i][j];
        }
    }

    int ans = 0;


    for (int i=1; i<=n; i++) {
        map<int,int> cnt2;
        for (int j=1; j<=m; j++) {
            int cur = c[i][j];
            cnt2[cur] ++;
            ans += add[cur] + (i - last[cur]) * cnt[cur];
        }
        for (auto it : cnt2) {
            add[it.F] += (i - last[it.F]) * cnt[it.F];
            cnt[it.F] += it.S;
            last[it.F] = i;
        }
    }

    // printf("ans = %lld\n", ans);

    memset(cnt, 0, sizeof(cnt));
    memset(add, 0, sizeof(add));

    for (int i=1; i<=m; i++) {
        map<int,int> cnt2;
        for (int j=1; j<=n; j++) {
            int cur = c[j][i];
            cnt2[cur] ++;
            ans += add[cur] + (i - last[cur]) * cnt[cur];
        }
        for (auto it : cnt2) {
            add[it.F] += (i - last[it.F]) * cnt[it.F];
            cnt[it.F] += it.S;
            last[it.F] = i;
        }
    }

    printf("%lld\n", ans);

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
