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
const int maxn = 1e3 + 7;

struct DS {
    int p[maxn];
    int sz[maxn];

    DS(int n) {
        for (int i=0; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int clan(int x) {
        return x == p[x] ? x : (p[x] = clan(p[x]));
    }
    void join(int x, int y) {
        x = clan(x);
        y = clan(y);
        if (x == y)
            return;
        p[y] = x;
        sz[x] += sz[y];
    }
    int size(int x) {
        return sz[clan(x)];
    }
};

int n, d;

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> d;

    DS ds(n);
    multiset<int> st;
    for (int i=1; i<=n; i++)
        st.insert(1);
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        int x, y;
        cin >> x >> y;
        if (ds.clan(x) == ds.clan(y)) {
            cnt ++;
        } else {
            st.erase(st.find(ds.size(x)));
            st.erase(st.find(ds.size(y)));
            ds.join(x, y);
            st.insert(ds.size(x));
        }

        int goal = cnt + 1;
        auto it = st.end();
        int ans = 0;
        while (goal--) {
            it = prev(it);
            ans += *it;
        }
        printf("%lld\n", ans - 1);
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
