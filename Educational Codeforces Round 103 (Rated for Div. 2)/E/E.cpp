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
const int maxn = 1e5 + 7;

vector<int> G[maxn];
string pat[maxn];
string str[maxn];
int mt[maxn];

bool ans = 1;
bool v[maxn] = {};
int indeg[maxn] = {};

int32_t main() {
    int i,j;
    int n,m,k;

    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >> pat[i];
    for (int i=1; i<=m; i++)
        cin >> str[i] >> mt[i];

    map<string, int> mp;
    for (int i=1; i<=n; i++) {
        mp[pat[i]] = i;
    }

    for (int i=1; i<=m; i++) {
        bool flag = 0;
        for (int j=0; j<(1<<k); j++) {
            string x = str[i];
            for (int h=0; h<k; h++) {
                if ((j>>h)&1)
                    x[h] = '_';
            }
            de(1) cout << "x = " << x << "\n";
            if (mp.find(x) != mp.end()) {
                de(1) printf("find!\n");
                if (mt[i] == mp[x])
                    flag = 1;
                else {
                    G[mt[i]].PB(mp[x]);
                    indeg[mp[x]]++;
                }
            }
        }
        if (!flag) {
            printf("NO\n");
            return 0;
        }
    }

    de(1) {
        for (int i=1; i<=n; i++) {
            printf("%lld >>> ", i);
            for (auto it : G[i]) {
                printf("%lld ", it);
            }
            printf("\n");
        }
    }

    queue<int> que;
    vector<int> keep;
    for (int i=1; i<=n; i++) {
        if (!indeg[i])
            que.push(i);
    }

    while (!que.empty()) {
        int goal = que.size();
        while (goal--) {
            int x = que.front();
            de(1) printf("now = %lld\n", x);
            keep.PB(x);
            que.pop();
            for (auto y : G[x]) {
                if (--indeg[y] == 0)
                    que.push(y);
            }
        }
    }

    if (keep.size() != n)
        ans = 0;

    if (ans) {
        printf("YES\n");
        for (auto it : keep)
            printf("%lld ", it);
        printf("\n");
    } else {
        printf("NO\n");
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
