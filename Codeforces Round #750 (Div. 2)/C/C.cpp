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

int n;
char s[maxn] = {};

int solve(char c) {
    int l=0;
    int r=n-1;
    int ret = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l ++;
            r --;
            continue;
        } else {
            while (l < r && s[l] == c) {
                l++;
                ret++;
            }
            while (l < r && s[r] == c) {
                r--;
                ret++;
            }

            if (l < r && s[l] != s[r])
                return -1;
        }
    }
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        cin >> n;
        scanf("%s", s);
        int ans = INF;
        for (char c='a'; c<='z'; c++) {
            int ret = solve(c);
            if (ret != -1) {
                ans = min(ans, ret);
            }
        }

        if (ans == INF)
            cout << -1 << "\n";
        else
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
