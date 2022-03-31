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

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        vector<int> u, d, l, r;
        int k;
        cin >> k;
        for (int i=0; i<k; i++) {
            int x;
            cin >> x;
            d.push_back(x);
        }
        cin >> k;
        for (int i=0; i<k; i++) {
            int x;
            cin >> x;
            u.push_back(x);
        }

        cin >> k;
        for (int i=0; i<k; i++) {
            int y;
            cin >> y;
            l.push_back(y);
        }

        cin >> k;
        for (int i=0; i<k; i++) {
            int y;
            cin >> y;
            r.push_back(y);
        }

        sort(all(u));
        sort(all(d));
        sort(all(l));
        sort(all(r));
        int ans = 0;
        ans = max(ans, (d.back() - d.front()) * max(l.back(), r.back()));
        ans = max(ans, (u.back() - u.front()) * (h - min(l.front(), r.front())));
        ans = max(ans, (l.back() - l.front()) * max(u.back(), d.back()));
        ans = max(ans, (r.back() - r.front()) * (w - min(u.front(), d.front())));

        printf("%lld\n", ans);
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
