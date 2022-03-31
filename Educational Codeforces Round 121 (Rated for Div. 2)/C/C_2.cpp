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
const int maxn = 1e5 + 7;

struct event {
    int type;
    int pos;
};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> k(n + 1, 0);
        vector<int> h(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> k[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }

        vector<event> keep;
        for (int i=1; i<=n; i++) {
            keep.PB({1, k[i]});
            keep.PB({0, k[i] - h[i] + 1});
        }
        sort(all(keep), [](event a, event b) {
            if (a.pos == b.pos)
                return a.type < b.type;
            return a.pos < b.pos;
        });

        int ans = 0;
        int cnt = 0;
        int lastP = 0;
        int curP = 0;
        int curV = 0;
        for (auto it : keep) {
            de(1) {
                printf("now: (%lld, %lld)\n", it.type, it.pos);
            }
            if (it.type == 0) {
                if (cnt == 0) {
                    de(1) printf("set lastP = %lld\n", it.pos);
                    lastP = it.pos;
                }
                cnt++;
            } else if (it.type == 1) {
                cnt --;
                if (cnt == 0) {
                    int u = it.pos - lastP + 1;
                    int d = 1;
                    int len = it.pos - lastP + 1;
                    int add = (u + d) * len / 2;
                    de(1) printf("l = %lld, r = %lld, add = %lld\n", lastP, it.pos, add);
                    ans += add;
                }
            }
        }

        // cerr << "ans = ";
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
