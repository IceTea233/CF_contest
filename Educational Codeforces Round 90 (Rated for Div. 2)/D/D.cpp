#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

LLI a[200007] = {};
LLI cht1[200007] = {};
LLI cht2[200007] = {};

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        LLI sum = 0;
        for( i=0; i<n; i++) {
            scanf("%lld", &a[i]);
            if( i % 2 == 0)
                sum += a[i];
        }
        for( i=0; i*2+1 < n; i++) {
            cht1[i] = a[ i*2 + 1 ] - a[i*2];
        }
        for( i=0; i*2+2 < n; i++) {
            cht2[i] = a[ i*2 + 1 ] - a[ i*2 + 2 ];
        }

        LLI maxi = 0;
        LLI cnt = 0;
        for( i=0; i*2+1 < n; i++) {
            cnt = max( cnt + cht1[i], 0LL);
            maxi = max( maxi, cnt);
        }
        cnt = 0;
        for( i=0; i*2+2 < n; i++) {
            cnt = max( cnt + cht2[i], 0LL);
            maxi = max( maxi, cnt);
        }
        printf("%lld\n", sum + maxi);
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
