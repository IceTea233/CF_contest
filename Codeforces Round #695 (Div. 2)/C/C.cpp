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
const int maxn = 3e5 + 7;

int a[4][maxn] = {};

int32_t main() {
    int i,j;
    int n1, n2, n3;

    cin >> n1 >> n2 >> n3;
    int ntt = n1 + n2 + n3;

    int tt = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    for (int i=1; i<=n1; i++) {
        scanf("%lld", &a[1][i]);
        tt += a[1][i];
        s1 += a[1][i];
    }
    for (int i=1; i<=n2; i++) {
        scanf("%lld", &a[2][i]);
        tt += a[2][i];
        s2 += a[2][i];
    }
    for (int i=1; i<=n3; i++) {
        scanf("%lld", &a[3][i]);
        tt += a[3][i];
        s3 += a[3][i];
    }
    sort(a[1]+1, a[1]+n1+1);
    sort(a[2]+1, a[2]+n2+1);
    sort(a[3]+1, a[3]+n3+1);

    int cut = min({s1, s2, s3});

    cut = min({cut, a[1][1] + a[2][1], a[1][1] + a[3][1], a[2][1] + a[3][1]});

    int ans = tt - cut * 2;
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
