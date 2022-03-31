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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e3 + 7;

int bl[maxn*2] = {};
int br[maxn*2] = {};
int tl[maxn*2] = {};
int tr[maxn*2] = {};
int d[maxn*2] = {};
int arr[maxn][maxn] = {};
int cover[maxn][maxn] = {};

int n,m,k;
int l[maxn] = {};
int r[maxn] = {};

int cal(int s, int id){
    int ll = max(l[id], s);
    int rr = min(r[id], s+k-1);
    return max( 0LL, rr - ll + 1);
}

int32_t main() {
    int i,j;

    cin >> n >> m >> k;

    for (int i=1; i<=m; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i=1; i<=m; i++) {
        bl[i] = l[i] - k;
        br[i] = r[i] + k;
        if (k < r[i] - l[i] + 1) {
            tl[i] = l[i];
            tr[i] = r[i] - k + 1;
        } else {
            tl[i] = r[i] - k + 1;
            tr[i] = l[i];
        }
    }
    de(1) {
        for (int i=1; i<=m; i++) {
            printf(">>> (%lld, %lld)\n", tl[i], tr[i]);
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        memset(d, 0, sizeof(d));
        for (int j=1; j<=m; j++) {
            int addl = max(i, bl[j]);
            int addr = max(i, tl[j]);
            int cutl = max(i, tr[j]);
            int cutr = max(i, tr[j] + (addr - addl));
            de(1) {
                printf("cp. (%lld, %lld, %lld, %lld)\n", addl, addr, cutl, cutr);
            }
            d[addl]++;
            d[addr]--;
            d[cutl]--;
            d[cutr]++;
        }

        int cnt = 0;
        for (int j=1; j<=m; j++) {
            cnt += cal(i, j);
        }
        int add = 0;
        // printf("%2lld >>> ", i);
        for (int j=1; j+k-1<=n; j++) {
            // printf("%2lld ", cnt);
            add += d[j];
            cnt += add;
            ans = max(cnt, ans);
        }
        // printf("\n");
    }

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
