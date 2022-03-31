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

int a[maxn] = {};
set<int> st1[maxn], st2[maxn];

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        st1[0].insert(x);
        st2[0].insert(x + 3);
        for (int i=1; i<=n; i++) {
            st1[i].clear();
            st2[i].clear();
            for (auto it : st1[i - 1]) {
                st1[i].insert(it + a[i]);
                st1[i].insert(it ^ a[i]);
            }
            for (auto it : st2[i - 1]) {
                st2[i].insert(it + a[i]);
                st2[i].insert(it ^ a[i]);
            }

            vector<int> rmv;
            for (auto it : st1[i]) {
                if (st2[i].find(it) != st2[i].end()) {
                    rmv.PB(it);
                }
            }
            for (auto it : rmv) {
                st1[i].erase(it);
                st2[i].erase(it);
            }
        }

        // for (int i=0; i<=n; i++) {
        //     printf("%lld: ", i);
        //     for (auto it : st1[i]) {
        //         printf("%lld ", it);
        //     }
        //     printf("\n");
        // }

        if (st1[n].find(y) != st1[n].end()) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
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
