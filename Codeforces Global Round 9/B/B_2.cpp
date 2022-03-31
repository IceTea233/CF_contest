#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[307][307] = {};
int b[307][307] = {};
int n,m;
int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        bool ans = 1;
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                if( ( i == 1 || i == n) && ( j == 1|| j == m) ) {
                    if( a[i][j] > 2)
                        ans = 0;
                    else
                        a[i][j] = 2;
                }
                else if( ( i == 1 || i == n ) && ( 2 <= j && j <= m-1) ||
                         ( j == 1 || j == m ) && ( 2 <= i && i <= n-1) ) {

                    if( a[i][j] > 3)
                        ans = 0;
                    else
                        a[i][j] = 3;
                }
                else {
                    if( a[i][j] > 4)
                        ans = 0;
                    else
                        a[i][j] = 4;
                }
            }
        }

        if( ans) {
            printf("YES\n");
            for( i=1; i<=n; i++) {
                for( j=1; j<=m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("NO\n");
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
