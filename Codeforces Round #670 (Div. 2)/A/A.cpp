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
const int maxn = 1e2 + 7;

int a[maxn] = {};
int cnt[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (i=1; i<=n; i++) {
            cin >> a[i];
            cnt[ a[i] ] ++;
        }

        int a = 0;
        for (int i=0; i<=maxn+1; i++) {
            if (cnt[i]) {
                cnt[i]--;
            } else {
                a = i;
                break;
            }
        }
        int b = 0;
        for (int i=0; i<=maxn+1; i++) {
            if (cnt[i]) {
                cnt[i]--;
            } else {
                b = i;
                break;
            }
        }

        printf("%lld\n", a+b);
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
