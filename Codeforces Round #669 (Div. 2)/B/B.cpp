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

int a[maxn] = {};
bool v[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(v, 0, sizeof(v));
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        sort( a+1, a+n+1);
        vector<int> ans;
        ans.push_back(a[n]);
        v[n] = 1;

        int now = a[n];
        for (int i=1; i<=n-1; i++) {
            int maxi = 0;
            int idx = 0;
            for (int j=n; j>=1; j--) {
                if ( !v[j] && __gcd(now, a[j]) > maxi) {
                    maxi = __gcd(now, a[j]);
                    idx = j;
                }
            }
            now = __gcd(now, a[idx]);
            ans.push_back(a[idx]);
            v[idx] = 1;
        }
        for (auto it:ans) {
            printf("%lld ", it);
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
