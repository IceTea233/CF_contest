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

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> b1;
    vector<int> b2;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (b1.empty() || a[i] != b1.back()) {
            if (!b1.empty() && !b2.empty() && a[i+1] == a[i] && b2.back() == a[i]) {
                b2.PB(b1.back());
                b1.PP();
            }
            if (b1.empty() || a[i] != b1.back())
                ans++;
            b1.PB(a[i]);
        } else {
            if (b2.empty() || a[i] != b2.back()) {
                ans++;
            }
            b2.PB(a[i]);
        }
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
