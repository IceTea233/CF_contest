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

vector<vector<int>> keep;
vector<vector<int>> cand;

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n > m) {
            printf("0\n");
            continue;
        }

        keep.clear();
        cand.clear();
        for (i=0; (1<<(i+1)) <= m; i++);
        int k = i;
        // printf("k = %lld\n", k);

        vector<int> cur;
        for (; i>=0; i--) {
            if ((m>>i) & 1) {
                cur.PB(!((n>>i) & 1));
                keep.PB(cur);
                keep.back().back() ^= 1;
            } else {
                cur.PB(((n>>i) & 1));
                cand.PB(cur);
                cand.back().back() ^= 1;
            }
        }
        keep.PB(cur);

        // for (auto &it : keep) {
        //     for (auto &it2: it)
        //         printf("%lld", it2);
        //     printf("\n");
        // }
        // printf("===\n");
        // for (auto &it : cand) {
        //     for (auto &it2: it)
        //         printf("%lld", it2);
        //     printf("\n");
        // }

        int ans = INF;
        for (auto &it : cand) {
            int num = 0;
            for (int i=0; i<=k; i++) {
                num <<= 1;
                if (i < it.size())
                    num |= it[i];
            }
            ans = min(num, ans);
        }

        if (ans == INF)
            ans = m + 1;

        printf("%lld\n", ans);
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
