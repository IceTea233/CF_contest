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
const int maxn = 1e5 + 7;

int a[maxn] = {};
int cht_AND[4][4] = {};
int cht_OR[4][4] = {};
int judge[maxn] = {0, 1, 6, 4, 2, 3, 5, 4};

int OR(int i, int j) {
    int ret = 0;
    printf("or %lld %lld\n", i, j);
    fflush(stdout);
    scanf("%lld", &ret);
    // ret = judge[i] | judge[j];
    return ret;
}

int AND(int i, int j) {
    int ret = 0;
    printf("and %lld %lld\n", i, j);
    fflush(stdout);
    scanf("%lld", &ret);
    // ret = judge[i] & judge[j];
    return ret;
}

void FINISH(int res) {
    printf("finish %lld\n", res);
    fflush(stdout);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,k;

    scanf("%lld %lld", &n, &k);
    cht_AND[1][2] = cht_AND[2][1] = AND(1, 2);
    cht_OR[1][2] = cht_OR[2][1] = OR(1, 2);
    cht_AND[1][3] = cht_AND[3][1] = AND(1, 3);
    cht_OR[1][3] = cht_OR[3][1] = OR(1, 3);
    cht_AND[2][3] = cht_AND[3][2] = AND(2, 3);
    cht_OR[2][3] = cht_OR[3][2] = OR(2, 3);

    a[1] = (cht_AND[1][2] | cht_AND[1][3] | (cht_OR[1][2] & cht_OR[1][3] & ~cht_OR[2][3]));
    a[2] = (cht_AND[2][1] | cht_AND[2][3] | (cht_OR[2][1] & cht_OR[2][3] & ~cht_OR[1][3]));
    a[3] = (cht_AND[3][1] | cht_AND[3][2] | (cht_OR[3][1] & cht_OR[3][2] & ~cht_OR[1][2]));

    for (int i=4; i<=n; i++) {
        a[i] = AND(1, i) | (OR(1, i) & ~a[1]);
    }

    sort(a+1, a+n+1);
    FINISH(a[k]);

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
