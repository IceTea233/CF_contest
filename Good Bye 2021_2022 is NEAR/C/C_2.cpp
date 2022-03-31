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
const int maxn = 70 + 7;

int a[maxn] = {};


int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        int ans = n - 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int cnt = n - 1;
                int d = (a[j] - a[i]);
                int step = j - i;
                if (d == 0) {
                    step = 1;
                } else {
                    int gcd = __gcd(abs(d), step);
                    d /= gcd;
                    step /= gcd;
                }
                for (int k = 1; i + k * step <= n; k ++) {
                    // cerr << "k = " << k << "\n";
                    if (a[i + k * step] == a[i] + d * k)
                        cnt --;
                }
                for (int k = 1; i - k * step >= 1; k ++) {
                    if (a[i - k * step] == a[i] - d * k)
                        cnt --;
                }
                // cerr << "cnt = " << cnt << "\n";
                ans = min(ans, cnt);
            }
        }

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
