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
const int maxk = 3e5 + 7;

int x[maxn] = {};
int y[maxn] = {};

bool cmp2(pii a, pii b) {
    if (a.S == b.S)
        return a.F < b.F;
    return a.S < b.S;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &x[i]);
        }
        for (int i=1; i<=m; i++) {
            scanf("%lld", &y[i]);
        }
        vector<pii> p;
        for (int i=1; i<=k; i++) {
            int a, b;
            scanf("%lld %lld", &a, &b);
            p.PB({a, b});
        }

        map<int,int> mp;
        int ans = 0;
        sort(all(p));
        for (int i=1, j=0; i<=n-1; i++) {
            int cnt = 0;
            mp.clear();
            while(j < k && p[j].F <= x[i])
                j++;
            while(j < k && p[j].F < x[i+1]) {
                mp[p[j].S] ++;
                j++;
                cnt++;
            }
            de(1) printf("cnt = %lld\n", cnt);
            ans += cnt * (cnt - 1) / 2;
            for (auto &it : mp) {
                de(1) printf("same = (%lld, %lld)\n", it.F, it.S);
                ans -= it.S * (it.S - 1) / 2;;
            }
        }

        de(1) printf("\n");

        sort(all(p), cmp2);
        for (int i=1, j=0; i<=m-1; i++) {
            int cnt = 0;
            mp.clear();
            while(j < k && p[j].S <= y[i])
                j++;
            while(j < k && p[j].S < y[i+1]) {
                mp[p[j].F] ++;
                j++;
                cnt++;
            }
            de(1) printf("cnt = %lld\n", cnt);
            ans += cnt * (cnt - 1) / 2;
            for (auto &it : mp) {
                de(1) printf("same = (%lld, %lld)\n", it.F, it.S);
                ans -= it.S * (it.S - 1) / 2;;
            }
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
