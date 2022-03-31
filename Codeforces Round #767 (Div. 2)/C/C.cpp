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
#define MODE 2

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

        deque<int> keep;
        vector<int> ans;
        for (int i=1; i<=n; i++) {
            keep.PB(a[i]);
        }

        bool stop = false;
        while (!stop && cnt[0] > 0) {
            stop = true;
            int x = 0;
            for (int i=0; i <= n + 1; i++) {
                if (cnt[i] == 0) {
                    x = i;
                    break;
                }
            }
            de(1) printf("x = %lld\n", x);

            set<int, greater<int>> st;
            int cur = x - 1;
            for (i=0; i<keep.size(); i++) {
                if (keep[i] <= cur)
                    st.insert(keep[i]);
                while (cur >= 0 && *st.begin() == cur) {
                    cur--;
                    st.erase(st.begin());
                }
                // de(1) printf(">>> cur = %lld\n", cur);
                if (cur == -1) {
                    for (j=0; j<=i; j++) {
                        cnt[keep[0]]--;
                        keep.pop_front();
                    }
                    keep.PB(x);
                    cnt[keep.back()]++;
                    stop = false;
                    break;
                }
            }
            // printf("%d\n", keep.size());
            // for (auto it : keep) {
            //     printf("%lld ", it);
            // }
            // printf("\n");
            // system("PAUSE");
        }
        de(2) printf("ans = ");
        printf("%d\n", keep.size());
        for (auto it : keep) {
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
