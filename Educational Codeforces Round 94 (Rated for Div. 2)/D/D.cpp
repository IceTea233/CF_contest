#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[3007] = {};
int cnt[3007][3007] = {};
int pre[3007][3007] = {};

int sum(int x, int l, int r) {
    return pre[x][r] - pre[x][l-1];
}

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++) {
                pre[i][j] = pre[i][j-1];
                if (a[j] == i)
                    pre[i][j]++;
            }
        }

        int ans = 0;
        for (i=2; i<=n-2; i++) {
            for (j=i+1; j<=n-1; j++) {
                ans += sum(a[i], j+1, n) * sum(a[j], 1, i-1);
            }
        }
        de(0) printf(">>>");
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
