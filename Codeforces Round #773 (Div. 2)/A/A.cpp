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
#define x F
#define y S
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

double dis(pii a, pii b) {
    return sqrt(pow(a.F - b.F, 2) + pow(a.S - b.S, 2));
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        vector<pii> keep;
        for (int i=0; i<3; i++) {
            int x, y;
            cin >> x >> y;
            keep.PB({y, x});
        }
        sort(all(keep));
        double ans = dis(keep[0], keep[1]);
        if (keep[2].x <= keep[0].x && keep[2].x <= keep[1].x) {
            if  (keep[0].x <= keep[1].x)
                ans += dis(keep[0], keep[2]);
            else
                ans += dis(keep[1], keep[2]);
        } else if (keep[2].x >= keep[0].x && keep[2].x >= keep[1].x) {
            if  (keep[0].x >= keep[1].x)
                ans += dis(keep[0], keep[2]);
            else
                ans += dis(keep[1], keep[2]);
        }

        printf("%.6f\n", ans);
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
