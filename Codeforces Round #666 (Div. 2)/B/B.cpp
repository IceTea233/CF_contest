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
    for (i=0; i<n; i++) {
        cin >> a[i];
    }
    sort( a, a+n);

    int ans = INF;
    if (n >= 60) {
        int cnt = 0;
        for (i=0; i<n; i++) {
            cnt += abs(a[i]-1);
        }
        ans = cnt;
    } else {
        for (i=1; pow(i, n) <= 1e15; i++) {
            int k = 1;
            int cnt = 0;
            for (j=0; j<n; j++, k*=i)
                cnt += abs(a[j] - k);

            ans = min(ans, cnt);
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
