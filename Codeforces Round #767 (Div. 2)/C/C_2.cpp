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
const int maxn = 2e5 + 7;

int a[maxn] = {};
int cnt[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(int) * (n + 1));
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            cnt[a[i]] ++;
        }

        vector<int> ans;
        set<int, greater<int>> st;
        int x = 0;
        for (int i=0; i <= n + 1; i++) {
            if (cnt[i] == 0) {
                x = i;
                break;
            }
        }
        int cur = x - 1;
        for (int i=1; i<=n; i++) {
            de(2) printf("i = %lld, x = %lld, cur = %lld\n", i, x, cur);
            cnt[a[i]]--;
            if (a[i] <= cur)
                st.insert(a[i]);

            while (cur >= 0 && *st.begin() == cur) {
                st.erase(st.begin());
                cur--;
            }
            // de(2) printf("cur = %lld, st top = %lld\n", cur, *st.begin());
            if (cur == -1) {
                ans.PB(x);
                for (int j=0; j<=n; j++) {
                    if (cnt[j] == 0) {
                        x = j;
                        cur = x - 1;
                        break;
                    }
                }
                de(2) printf("new x = %lld\n", x);
            }
        }

        de(2) printf("ans = ");
        printf("%d\n", ans.size());
        for (auto it : ans) {
            printf("%lld ", it);
        }
        printf("\n");
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
