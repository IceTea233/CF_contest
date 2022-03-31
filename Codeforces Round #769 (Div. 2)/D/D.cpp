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

int a[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    deque<int> keep;
    int ans = 0;
    for  (int i=1; i<=n; i++) {
        keep.PB(a[i]);
        int gcd = keep.back();
        for (int j = 0; j < keep.size(); j++) {
            gcd = __gcd(keep[keep.size() - j - 1], gcd);
            if (gcd == j + 1) {
                ans ++;
                keep.clear();
            } else if (gcd < j + 1) {
                keep.erase(keep.begin(), keep.end() - j);
            }

            de(1) {
                printf(">>> ");
                for (auto it : keep) {
                    printf("%lld ", it);
                }
                printf("\n");
            }
        }
        printf("%lld ", ans);
    }
    printf("\n");

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
