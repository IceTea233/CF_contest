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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e4 + 7;

int a[maxn] = {};
bool taken[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        int x;
        cin >> x;
        for (int i=1; i<=n; i++) {
            a[i] -= x;
        }
        int ans = 0;

        // de(1) {
        //     for (int i=1; i<=n; i++)
        //         printf("%lld ", a[i]);
        //     printf("\n");
        // }
        for (int i=1; i<=n; i++) {
            if (a[i] >= 0) {
                ans ++;
            } else {
                if ((i == 1 || a[i] + a[i-1] >= 0) && (i == n || a[i] + a[i+1] >= 0)) {
                    ans++;
                    a[i-1] += a[i];
                    a[i+1] += a[i];
                }
            }
        }

        // de(1) {
        //     for (int i=1; i<=n; i++)
        //         printf("%lld ", a[i]);
        //     printf("\n");
        // }

        cerr << "ans = ";
        cout << ans << "\n";
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
