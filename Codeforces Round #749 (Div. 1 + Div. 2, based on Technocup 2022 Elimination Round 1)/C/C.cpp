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
const int maxn = 1e6 + 7;

int n, m;
string g[maxn];
vector<bool> good[maxn];
bool ans[maxn] = {};

void upd(int col) {
    for (int i=1; i<=n; i++) {
        good[i][col] = true;
    }
}

bool chk(int col) {
    for (int i=1; i<=n; i++) {
        if (!good[i][col])
            return false;
    }
    return true;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> g[i];
        g[i] = '.' + g[i];
        good[i].resize(m+1);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i > 1 && j > 1 && g[i][j-1] == 'X' && g[i-1][j] == 'X')
                good[i][j] = false;
            else
                good[i][j] = true;
        }
    }
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=m; j++) {
    //         cout << good[i][j];
    //     }
    //     printf("\n");
    // }
    int r = 1;
    while (r < m && chk(r+1)) {
        r++;
    }

    int q;
    cin >> q;
    vector<array<int,3>> keep;
    for (int i=1; i<=q; i++) {
        int x1, x2;
        scanf("%lld %lld", &x1, &x2);
        keep.PB({x1, x2, i});
    }
    sort(all(keep));
    int l = 1;
    for (auto it : keep) {
        // printf("(%lld, %lld) %lld\n", it[0], it[1], it[2]);
        while (l < it[0]) {
            upd(++l);
        }
        while (r < m && chk(r+1)) {
            r++;
        }
        // printf("[%lld, %lld]\n", l, r);

        if (it[1] <= r)
            ans[it[2]] = true;
        else
            ans[it[2]] = false;
    }

    for (int i=1; i<=q; i++) {
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
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
