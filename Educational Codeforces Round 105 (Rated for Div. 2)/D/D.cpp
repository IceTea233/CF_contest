#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e3 + 7;

struct info {
    int u;
    int v;
    int val;
};
bool operator<(info a, info b) {
    return a.val > b.val;
}

int p[maxn];
int a[maxn][maxn] = {};
int c[maxn] = {};
int lead[maxn] = {};
int v[maxn][maxn] = {};

int32_t main() {
    int i,j;
    int n;

    cin >> n;

    int mini = INF;
    int now = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if (i == j) {
                v[i][j] = 1;
                lead[i] = i;
                c[i] = a[i][j];
                mini = min(mini, a[i][j]);
            }
        }
    }
    now = mini;

    int k = n;
    for (int i=1; i<=n; i++) {
        mini = INF;
        for (int j=1; j<=n; j++) {
            for (int h=j+1; h<=n; h++) {
                if (a[j][h] > now)
                    mini = min(mini, a[j][h]);
            }
        }

        if (mini == INF)
            break;
        k++;
        for (int j=1; j<=n; j++) {
            for (int h=j+1; h<=n; h++) {
                if (a[j][h] == mini) {
                    p[lead[j]] = k;
                    p[lead[h]] = k;
                    lead[j] = k;
                    lead[h] = k;
                    c[k] = mini;
                }
            }
        }
        now = mini;
    }

    printf("%lld\n", k);
    for (i=1; i<=k; i++)
        printf("%lld ", c[i]);
    printf("\n");
    int r = 0;
    for (int i=1; i<=k; i++) {
        if (i == p[i])
            r = i;
    }
    printf("%lld\n", r);
    for (int i=1; i<=k; i++) {
        if (i != p[i])
            printf("%lld %lld\n", i, p[i]);
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
