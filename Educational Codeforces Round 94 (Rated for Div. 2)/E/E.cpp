#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int n;
int a[5007] = {};

int solve(int l, int r, int x) {
    if (l == r)
        return ( x != a[l] );

    int mini = l;
    for (int i=l; i<=r; i++) {
        if (a[i] < a[mini]) {
            mini = i;
        }
    }
    int cal = 0;
    if (mini > l)
        cal += solve(l, mini-1, a[mini]);
    if (mini < r)
        cal += solve(mini+1, r, a[mini]);
    
    return min(cal + (a[mini] - x), r-l+1);
}

main() {
    int i,j;

    cin >> n;
    for (i=1; i<=n; i++) {
        cin >> a[i];
    }

    int ans = solve( 1, n, 0);
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
