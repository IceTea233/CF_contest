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
const int maxn = 5e2 + 7;


int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        deque<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        int idx = 0;
        vector<int> ans;
        vector<pii> op;
        while (a.size()) {
            int r = -1;
            vector<int> keep;
            for (int i=1; i<a.size(); i++) {
                if (a[i] == a[0]) {
                    r = i;
                    break;
                }
                keep.PB(a[i]);
            }

            if (r == -1) {
                ans = {-1};
                break;
            }

            for (int i=1; i<r; i++) {
                op.PB({idx + r + i, a[i]});
            }
            idx += r * 2;

            ans.PB(a[0]);
            for (auto it : keep) {
                ans.PB(it);
            }
            ans.PB(a[r]);
            for (auto it : keep) {
                ans.PB(it);
            }
            ans.PB(-1);

            for (int i=0; i<=r; i++) {
                a.pop_front();
            }
            for (auto it : keep) {
                a.push_front(it);
            }


            de(1) {
                printf(">>> ");
                for (auto it : a) {
                    printf("%lld ", it);
                }
                printf("\n");
            }
        }

        if (ans[0] == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", op.size());
            for (auto it : op) {
                printf("%lld %lld\n", it.F, it.S);
            }

            vector<int> t;
            int cnt = 0;
            for (auto it : ans) {
                if (it == -1) {
                    t.PB(cnt);
                    cnt = 0;
                } else {
                    cnt++;
                }
            }

            printf("%d\n", t.size());
            for (auto it : t) {
                printf("%lld ", it);
            }
            printf("\n");

            // printf(">>> ");
            // for (auto it : ans) {
            //     printf("%lld ", it);
            // }
            // printf("\n");
        }


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
