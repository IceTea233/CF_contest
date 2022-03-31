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

int pre[maxn] = {};
int suf[maxn] = {};

int32_t main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    for (int i=0, j=0; i<m; i++, j++) {
        while (s[j] != t[i]) {
            j++;
        }
        pre[i] = j;
    }
    for (int i=m-1, j=n-1; i>=0; i--, j--) {
        while (s[j] != t[i]) {
            j--;
        }
        suf[i] = j;
    }

    // for (int i=0; i<m; i++) {
    //     printf("%lld ", pre[i]);
    // }
    // printf("\n");
    // for (int i=0; i<m; i++) {
    //     printf("%lld ", suf[i]);
    // }
    // printf("\n");
    int ans = 0;
    for (int i=1; i<m; i++) {
        ans = max(ans, suf[i] - pre[i-1]);
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
