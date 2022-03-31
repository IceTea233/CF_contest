#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[100007] = {};

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {
        int n, k, z;
        scanf("%d %d %d", &n, &k, &z);

        for( i=1; i<=n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        for( i=0; i<=z; i++) {
            int tt = 0;
            for( j=1; j <= k-i*2+1; j++) {
                tt += a[j];
            }
            int maxi = 0;
            for( j=1; j <= k-i*2+1; j++) {
                maxi = max( maxi, a[j] + a[j+1]);
            }
            ans = max( ans, tt + maxi*i);
        }
        printf("%d\n", ans);
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
