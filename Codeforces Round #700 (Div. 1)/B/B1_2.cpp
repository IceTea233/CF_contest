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
    vector<int> b1 = {1, 0};
    vector<int> b2 = {1, 0};
    int ans = 0;
    int lock = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] != b1.back()) {
            lock = 0;
            b1.PB(a[i]);
            ans++;
        } else {
            if (a[i] != b2.back()) {
                b2.PB(a[i]);
                ans++;
            } else {
                if (!lock && b1.size() >=3 && *(b1.end()-3) != a[i]) {
                    b2.PB(*(b1.end()-3));
                    b2.PB(a[i]);
                    b1.erase((b1.end()-3));
                    ans++;
                }
            }
        }

        de(1) {
            printf("b1 = ");
            for (auto it : b1)
            printf("%lld ", it);
            printf("\n");

            printf("b2 = ");
            for (auto it : b2)
            printf("%lld ", it);
            printf("\n\n");
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
