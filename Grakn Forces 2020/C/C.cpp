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
const int maxn = 1e5 + 7;

int a[maxn] = {};
double time1[maxn] = {};
double time2[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
      int n,l;
      cin >> n >> l;
      for (int i=1; i<=n; i++) {
        cin >> a[i];
      }
      a[n+1] = l;
      time1[0] = 0;
      for (int i=1; i<=n+1; i++) {
        time1[i] = time1[i-1] + (double)(a[i] - a[i-1]) / i;
      }
      // for (int i=0; i<=n+1; i++) {
      //   printf("%.2f ", time1[i]);
      // }
      // printf("\n");
      time2[n+1] = 0;
      for (int i=n; i>=0; i--) {
        time2[i] = time2[i+1] + (double)(a[i+1] - a[i]) / (n-i+1);
      }
      // for (int i=0; i<=n+1; i++) {
      //   printf("%.2f ", time2[i]);
      // }
      // printf("\n");
      for (i=0; i<=n+1; i++) {
        if (time1[i] >= time2[i])
          break;
      }
      double dis = a[i] - ( a[i-1] + i * (time2[i] - time1[i-1]) );
      // printf("dis = %.2f\n", dis);
      double v = i + (n-i+2);
      // printf("v = %.2f\n", v);
      double add = dis / v;
      double ans = time2[i] + add;
      printf("%.9f\n", ans);
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
