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

int A[maxn] = {};
int B[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int a,b,k;
        cin >> a >> b >> k;
        map< pair<int,int>, int> mp;
        vector<int> cnt_a(a+1, 0);
        vector<int> cnt_b(b+1, 0);
        for (int i=1; i<=k; i++)
            scanf("%lld", &A[i]);
        for (int i=1; i<=k; i++)
            scanf("%lld", &B[i]);

        for (int i=1; i<=k; i++) {
            cnt_a[A[i]]++;
            cnt_b[B[i]]++;
            mp[{A[i], B[i]}]++;
        }

        int ans = 0;
        for (int i=1; i<=k; i++) {
            int add = k - cnt_a[A[i]] - cnt_b[B[i]] + mp[{A[i], B[i]}];
            ans += add;
        }
        printf("%lld\n", ans/2);
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
