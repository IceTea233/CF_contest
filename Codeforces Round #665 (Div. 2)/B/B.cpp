#include<bits/stdc++.h>
#define int long long
#define d lld
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int x1, y1, z1;
        scanf("%lld %lld %lld", &x1, &y1, &z1);
        int x2, y2, z2;
        scanf("%lld %lld %lld", &x2, &y2, &z2);
        int ans = 0;
        int p1 = 0;
        if( z1 >= y2) {
            p1 = y2;
            z1 -= p1;
        }
        else {
            p1 = z1;
            y2 -= p1;
        }
        int p2 = min( max( 0LL, y1-x2), max( 0LL, z2-x1));
        ans = p1*2 - p2*2;
        de(1) {
            printf("p1 = %lld, p2 = %lld\n", p1, p2);
            printf(">>> ");
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
