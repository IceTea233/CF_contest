#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890LL
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {
        LLI n,k;
        scanf("%lld %lld", &n, &k);

        LLI b = k * (k+1) / 2;
        LLI x = ULTRA * ULTRA;
        for( i=0; i<=17; i++) {
            for( j=0; j<=k; j++) {
                LLI c = i*9;
                if( ( n - b + c * j ) % (k+1) == 0 ) {
                    printf(">>> ( %d, %d)\n", i, j);
                    LLI tmp = ( n - b + c * j ) / (k+1);
                    int cnt1 = max( tmp % 10 + k - 9, 0LL);
                    int cnt2 = 0;
                    LLI num = tmp;
                    if( cnt1) {
                        cnt2 = 1;
                        num /= 10;
                        while( num % 10 == 9) {
                            cnt2++;
                            num /= 10;
                        }
                    }
                    if( cnt1 == j && cnt2 == i) {
                        de(1) printf(" i = %d, j = %d\n", i, j);
                        LLI nx = 0;
                        x = min( x, tmp);
                    }
                }
            }
        }
        printf("%lld\n", x);
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
