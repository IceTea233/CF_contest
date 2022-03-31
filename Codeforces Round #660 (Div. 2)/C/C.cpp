#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

vector<int> adj[100007];

int p[100007] = {};
int h[100007] = {};
LLI tt[100007] = {};
LLI cnt[100007][2] = {};

bool ans = 1;
void dfs( int x, int pa) {
    bool leaf = 1;

    LLI good = 0;
    LLI bad = 0;
    tt[x] = p[x];
    for( auto y:adj[x]) {
        if( y == pa)
            continue;
        leaf = 0;
        dfs( y, x);

        good += cnt[y][1];
        bad += cnt[y][0];
        tt[x] += tt[y];
    }

    if( leaf) {
        if( (p[x]+h[x]) % 2)
            ans = 0;
        cnt[x][1] = ( p[x] + h[x] ) / 2;
        cnt[x][0] = p[x] - cnt[x][1];
    }
    else {
        if( (tt[x] + h[x]) % 2 )
            ans = 0;
        cnt[x][1] = ( tt[x] + h[x] ) / 2;
        cnt[x][0] = tt[x] - cnt[x][1];
        if( cnt[x][0]-p[x] > bad || cnt[x][1] < good)
            ans = 0;
    }

    if( cnt[x][0] < 0 || cnt[x][1] < 0)
        ans = 0;
}

int main() {

    int i,j;
    int t;

    cin >> t;
    while(t--) {

        int n,m;
        cin >> n >> m;
        for( i=1; i<=n; i++) {
            adj[i].clear();
            tt[i] = 0;
            cnt[i][0] = 0;
            cnt[i][1] = 0;
        }

        for( i=1; i<=n; i++)
            cin >> p[i];
        for( i=1; i<=n; i++)
            cin >> h[i];
        for( i=1; i<=n-1; i++) {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs( 1, 1);
        de(1) {
            for( i=1; i<=n; i++)
                printf("( %d, %d) ", cnt[i][1], cnt[i][0]);
            printf("\n");
            for( i=1; i<=n; i++)
                printf("%d ", tt[i]);
            printf("\n");
        }


        if( ans)
            cout << "YES\n";
        else
            cout << "NO\n";
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
