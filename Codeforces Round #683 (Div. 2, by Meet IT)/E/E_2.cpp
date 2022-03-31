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
const int maxn = 2e5 + 7;

int a[maxn] = {};
int cnt[40] = {};

main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++) {
        for (j=0; (1<<j) <= a[i]; j++);
        cnt[j]++;
    }

    if (cnt[0]) {
        for (int i=1; i<=32; i++) {
            if (cnt[i] == 1) {
                cnt[0]++;
                cnt[i]--;
            }
        }
    }

    int maxi = 0;
    int ans = 0;
    for (int i=0; i<=33; i++) {
        if (cnt[i]) {
            ans += cnt[i] - 1;
            maxi = max(cnt[i] - 1, maxi);
        }
        printf("%lld ", cnt[i]);
    }
    ans -= maxi;
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
