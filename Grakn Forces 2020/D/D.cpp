#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e3 + 7;

int a[maxn] = {}, b[maxn] = {};
int c[maxn] = {}, d[maxn] = {};

struct event{
  int type;
  int x;
  int y;

  bool operator<(event b) {
    if (x == b.x)
      return type < b.type;
    return x > b.x;
  }
};

bool cmp(pii a, pii b) {
  return a.S < b.S;
}

main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
      scanf("%lld %lld", &a[i], &b[i]);
    }

    for (int i=1; i<=m; i++) {
      scanf("%lld %lld", &c[i], &d[i]);
    }

    vector<pii> keep;
    vector<event> keep2;
    vector<pii> R;
    vector<pii> S;

    for (int i=1; i<=m; i++) {
      keep.PB({c[i], d[i]});
    }
    keep.PB({-1, INF});
    sort(all(keep));
    for (int i=m; i>=0; i--) {
      if (i == m || keep[i].S > S.back().S) {
        S.PB(keep[i]);
      }
    }
    for (auto it: S) {
      printf("( %lld, %lld) ", it.F, it.S);
    }
    printf("\n");

    a[n+1] = INF-1;
    b[n+1] = INF-1;
    for (int i=1; i<=n; i++) {
      keep2.PB({1 ,a[i], b[i]});
    }
    keep2.PB({1, INF, INF});

    for (auto it: S) {
      keep2.PB({2, it.F, it.S});
    }
    sort(begin(keep2), end(keep2));



    int top = -INF;
    int ans = INF;
    for (auto it:keep2) {
      printf("now (%lld) (%lld, %lld)\n", it.type, it.x, it.y);
      if (it.type == 1) {
        int up = max( 0LL, top - it.y + 1);
        printf("try up = %lld\n", up);
        int maxi = 0;
        for (int i=1; i<=n+1; i++) {
          int r = (upper_bound(begin(S), end(S), (pii){a[i], b[i] + up}, cmp) )->F;
          printf("finding (%lld, %lld)\n", a[i], b[i] + up);
          printf("r = %lld\n", r);
          maxi = max( maxi, r - a[i] + 1);
        }
        ans = min(ans, up+maxi);
      } else if (it.type == 2) {
        top = it.y;
      }
    }

    printf("%lld\n", ans);

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
