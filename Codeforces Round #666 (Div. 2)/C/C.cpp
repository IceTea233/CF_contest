#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int a[maxn];

main() {
    int i,j;
    int n;

    cin >> n;
    for (i=1; i<=n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        printf("1 1\n");
        printf("%lld\n", -a[1]);
        printf("1 1\n");
        printf("%lld\n", 0LL);
        printf("1 1\n");
        printf("%lld\n", 0LL);
        return 0;
    }

    vector< pair<pii, vector<int> > > ans;
    int maxi = *max_element(a+1, a+n+1);

    vector<int> keep;
    for (i=1; i<=n; i++) {
        keep.push_back( n * a[i] * (-1) );
    }
    ans.push_back({ {1, n}, keep});
    a[n] -= n * a[n];

    keep.clear();
    for (i=1; i<=n-1; i++) {
        keep.push_back( (n-1) * a[i] );
    }
    ans.push_back({ {1, n-1}, keep});

    ans.push_back({ {n, n}, {-a[n]} });

    for (auto it: ans) {
        printf("%lld %lld\n", it.F.F, it.F.S);
        for (auto it2: it.S) {
            printf("%lld ", it2);
        }
        printf("\n");
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
