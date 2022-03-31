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
const int maxn = 1e4 + 7;

int q[maxn] = {};

int query(int x) {
    printf("? %lld\n", x);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        memset(q, 0, sizeof(int) * (n+1));
        for (int i=1; i<=n; i++) {
            if (q[i])
                continue;
            int start = query(i);
            int last = start;
            int idx = query(i);
            while (idx != start) {
                q[last] = idx;
                // cerr << "q[" << last << "]" << " = " << idx << "\n";
                last = idx;
                idx = query(i);
            }
            q[last] = idx;
            // cerr << "q[" << last << "]" << " = " << idx << "\n";
        }

        printf("!");
        for (int i=1; i<=n; i++) {
            printf(" %lld", q[i]);
        }
        printf("\n");
        fflush(stdout);
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
