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
const int maxn = 1e6 + 7;

int n, c;
int a[maxn] = {};
int cnt[maxn] = {};

bool found(int cur, int k) {
    auto it = lower_bound(a + 1, a + n + 1, cur * k);
    de(1) {
        printf("checking (%lld, %lld)\n", cur, k);
    }
    if (it != a + n + 1 && *it < cur * (k + 1)) {
        de(1) printf("Okay\n");
        return true;
    } else {
        de(1) printf("Fail\n");
        return false;
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> c;
        memset(cnt, 0, sizeof(int) * (c + 1));
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            cnt[a[i]] ++;
        }
        sort(a + 1, a + n + 1);

        bool ans = true;
        for (int i=1; i<=n; i++) {
            if (a[i] == a[i-1])
                continue;
            int cur = a[i];
            for (int j = 1; cur * j <= c; j++) {
                if ((cnt[j] == 0) && found(cur, j)) {
                    ans = false;
                }
            }
        }

        if (ans)
            printf("Yes\n");
        else
            printf("No\n");
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
