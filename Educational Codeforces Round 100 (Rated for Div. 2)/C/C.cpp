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

struct info {
    int type;
    int idx;
    int val;
};
bool operator<(info a, info b) {
    if (a.idx == b.idx)
        return a.idx > b.idx;
    return a.idx > b.idx;
}

int t[maxn] = {};
int x[maxn] = {};

int32_t main() {
    int i,j;
    int T;

    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        priority_queue<info> pq;
        for (int i=1; i<=n; i++) {
            scanf("%lld %lld", &t[i], &x[i]);
            pq.push({1, t[i], x[i]});
        }
        t[n+1] = INF;
        multiset<int> st;
        int now_pos = 0;
        int nxt_time = 0;
        int nxt_pos = 0;
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (t[i] >= nxt_time) {
                nxt_time = t[i] + abs(x[i] - now_pos);
                nxt_pos = x[i];
            }

            int src = now_pos;
            int des;
            if (nxt_pos > now_pos) {
                des = min(nxt_pos, now_pos + (t[i+1] - t[i]));
            } else {
                des = max(nxt_pos, now_pos - (t[i+1] - t[i]));
            }
            de(1) printf("cmd %lld -> from %lld to %lld\n", i, src, des);
            if (src <= x[i] && x[i] <= des
             || src >= x[i] && x[i] >= des) {
                 de(1) printf("cmd %lld is good\n", i);
                 ans++;
            }
            now_pos = des;
        }
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
