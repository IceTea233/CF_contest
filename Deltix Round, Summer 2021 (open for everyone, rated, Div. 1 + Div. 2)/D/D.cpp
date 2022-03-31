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

int OR(int i, int j) {
    int ret = 0;
    printf("or %lld %lld\n", i, j);
    fflush(stdin);
    scanf("%lld", &ret);
    return ret;
}

int AND(int i, int j) {
    int ret = 0;
    printf("and %lld %lld\n", i, j);
    fflush(stdin);
    scanf("%lld", &ret);
    return ret;
}

void FINISH(int res) {
    printf("finish %lld\n", res);
    fflush(stdin);
}

int a[maxn] = {};
int cht_AND[maxn] = {};
int cht_OR[maxn] = {};

bool cmp(int a, int b) {
    if (cht_OR[a] == cht_OR[b])
        return cht_AND[a] < cht_AND[b];
    return cht_OR[a] < cht_OR[b];
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,k;

    scanf("%lld %lld", &n, &k);
    for (int i=1; i<=n-1; i++) {
        cht_AND[i] = AND(i, n);
        cht_OR[i] = OR(i, n);
    }

    vector<int> keep;
    for (int i=1; i<=n-1; i++) {
        keep.PB(i);
    }
    sort(all(keep), cmp);
    for (auto it : keep)
        printf("%lld ", it);
    printf("\n");
    int id1 = keep[k-1];
    int id2 = id1 % (n-1) + 1;
    int id3 = n;

    cht_AND[id3] = AND(id1, id2);
    cht_OR[id3] = OR(id1, id2);
    int num1 = (cht_AND[id1] | cht_AND[id3] | (cht_OR[id1] & cht_OR[id3] & ~cht_OR[id2]));
    int num2 = (cht_AND[id2] | cht_AND[id3] | (cht_OR[id2] & cht_OR[id3] & ~cht_OR[id1]));
    int num3 = (cht_AND[id1] | cht_AND[id2] | (cht_OR[id1] & cht_OR[id2] & ~cht_OR[id3]));

    printf("%lld %lld %lld\n", num1, num2, num3);

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
