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
int r[307][307] = {};
int n,m;
int mask[4][2] = {
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

bool OK( int r, int c) {
    if( 1 <= r && r <= n && 1 <= c && c <= m)
        return 1;
    else
        return 0;
}

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {


        scanf("%d %d", &n, &m);
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                scanf("%d", &a[i][j]);
                r[i][j] = a[i][j];
            }
        }

        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                if( r[i][j] > 0) {
                    for( int k=0; k<4; k++) {
                        int n_r = i + mask[k][0];
                        int n_c = j + mask[k][1];
                        if( !OK( n_r, n_c))
                            continue;
                        if( a[n_r][n_c] == 0) {
                            a[n_r][n_c] = 1;
                            r[n_r][n_c] = 1;
                        }
                    }
                }
            }
        }

        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                if( a[i][j] > 0) {
                    for( int k=0; k<4; k++) {
                        int n_r = i + mask[k][0];
                        int n_c = j + mask[k][1];
                        if( !OK( n_r, n_c))
                            continue;
                        r[n_r][n_c]--;
                    }
                }
            }
        }

        bool flag = 0;
        for( i=1; i<=n; i++) {
            for( j=1; j<=m; j++) {
                if( r[i][j] > 0)
                    flag = 1;
                else if( r[i][j] < 0) {
                    a[i][j] -= r[i][j];
                }
            }
        }

        if( flag)
            printf("NO\n");
        else {
            printf("YES\n");
            for( i=1; i<=n; i++) {
                for( j=1; j<=m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
        }

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
