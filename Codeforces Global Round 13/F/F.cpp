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

int n;

int query(vector<int> &a, vector<int> &b) {
    printf("? %d %d\n", a.size(), b.size());
    for (auto it : a)
        printf("%lld ", it);
    printf("\n");
    for (auto it : b)
        printf("%lld ", it);
    printf("\n");
    fflush(stdout);

    int f;
    scanf("%lld", &f);

    return f;
}

int32_t main() {
    int i,j;
    int t;

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        vector<int> ans;
        for (int i=1; i<=n; i++) {
            vector<int> a;
            vector<int> b;
            a.PB(i);
            for (int j=1; j<=n; j++) {
                if (j == i)
                    continue;
                b.PB(j);
            }
            int q = query(a, b);
            if (q == 0)
                ans.PB(i);
        }
        printf("! %d", ans.size());
        for (auto it : ans)
            printf(" %lld", it);
        printf("\n");
        fflush(stdout);
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
