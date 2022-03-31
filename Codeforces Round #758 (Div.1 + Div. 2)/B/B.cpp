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

int arr[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n - 2 < a + b || abs(a - b) > 1) {
            printf("-1\n");
            continue;
        }

        vector<int> ans;
        if (a == b) {
            ans.PB(1);
            for (i=1; i<=a; i++) {
                ans.PB(2 * i + 1);
                ans.PB(2 * i);
            }
            for (i=2*i; i<=n; i++) {
                ans.PB(i);
            }
        } else if (a == b + 1) {
            for (i=1; i<=a; i++) {
                ans.PB(i);
                ans.PB(n - i + 1);
            }
            for (i = ans.back() - 1; ans.size() < n; i--) {
                ans.PB(i);
            }
        } else if (a == b - 1) {
            for (i=1; i<=b; i++) {
                ans.PB(n - i + 1);
                ans.PB(i);
            }
            for (i = ans.back() + 1; ans.size() < n; i++) {
                ans.PB(i);
            }
        }

        for (auto it : ans)
            printf("%lld ", it);
        printf("\n");
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
