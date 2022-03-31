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
const int maxn = 1e3 + 7;

int a[maxn];

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int zero = 0;
        int one = 0;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                zero++;
            else
                one++;
        }
        if (one % 2 == 1) {
            one--;
        }
        if (zero < one) {
            printf("%lld\n", one);
            for (int i=1; i<=one; i++) {
                printf("1 ");
            }
            printf("\n");
        } else {
            printf("%lld\n", zero);
            for (int i=1; i<=zero; i++) {
                printf("0 ");
            }
            printf("\n");
        }
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
