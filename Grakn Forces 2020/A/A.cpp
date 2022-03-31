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
const int maxn = 1e2 + 7;

int a[maxn] = {};
int b[maxn] = {};
int c[maxn] = {};
int ans[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      for (int i=1; i<=n; i++) {
        cin >> a[i];
      }
      for (int i=1; i<=n; i++) {
        cin >> b[i];
      }
      for (int i=1; i<=n; i++) {
        cin >> c[i];
      }
      for (int i=1; i<=n-1; i++) {
        if (a[i] != ans[i-1])
          ans[i] = a[i];
        else if (b[i] != ans[i-1])
          ans[i] = b[i];
        else
          ans[i] = c[i];
      }

      if (a[n] != ans[n-1] && a[n] != ans[1])
        ans[n] = a[n];
      else if (b[n] != ans[n-1] && b[n] != ans[1])
        ans[n] = b[n];
      else if (c[n] != ans[n-1] && c[n] != ans[1])
        ans[n] = c[n];

      for (int i=1; i<=n; i++)
        printf("%lld ", ans[i]);
      printf("\n");
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
