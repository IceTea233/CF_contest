#include<bits/stdc++.h>
#define int long long
#define d lld
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define MOD 1000000007LL
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int n;

vector<int> adj[100007];
int sz[100007] = {};
int cal[100007] = {};
int p[100007] = {};

void dfs( int x, int p) {
    sz[x]++;

    for( auto y: adj[x]) {
        if( y == p)
            continue;
        dfs( y, x);
        sz[x] += sz[y];
        cal[y] = sz[y] * ( n - sz[y]);
    }
}

main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {

        cin >> n;
        memset( sz, 0, sizeof(int)*(n+1));
        memset( cal, 0, sizeof(int)*(n+1));
        for( i=1; i<=n; i++) {
            adj[i].clear();
        }
        for ( i=1; i<=n-1; i++) {
            int u,v;
            scanf("%lld %lld", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int m;
        cin >> m;
        for ( i=1; i<=m; i++) {
            scanf("%lld", &p[i]);
        }
        sort( p+1, p+m+1);
        if ( m > n-1) {
            for ( i=m; i>n-1; i--) {
                p[i-1] *= p[i];
                p[i-1] %= MOD;
            }
            reverse( p+1, p+n-1+1);
        } else {
            reverse( p+1, p+m+1);
            for ( i=n-1; i>m; i--) {
                p[i] = 1;
            }
        }

        de(1) {
            printf("p >> ");
            for( i=1; i<=n-1; i++) {
                printf("%lld ", p[i]);
            }
            printf("\n");
        }

        dfs( 1, 1);

        de(0) {
            printf("sz >> ");
            for( i=1; i<=n; i++) {
                printf("%lld ", sz[i]);
            }
            printf("\n");
        }

        sort( cal+1, cal+n+1, greater<int>() );

        de(1) {
            printf("cal >> ");
            for( i=1; i<=n; i++) {
                printf("%lld ", cal[i]);
            }
            printf("\n");
        }
        int ans = 0;
        for ( i=1; i<=n-1; i++) {
            ans += ( p[i] % MOD ) * ( cal[i] % MOD ) % MOD;
            ans %= MOD;
        }
        de(1) printf(">>> ");
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
