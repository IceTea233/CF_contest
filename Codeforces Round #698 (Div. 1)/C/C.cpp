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

#define TP int
#define pos complex<TP>
#define vec complex<TP>
#define x real()
#define y imag()

#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 5e3 + 7;

TP operator &(const vec a, const vec b) { // inner product
  return a.x * b.x + a.y * b.y;
}
TP operator |(const vec a, const vec b) { // outer product
  return a.x * b.y - a.y * b.x;
}

int to[maxn] = {};
pos p[maxn];

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        int px, py;
        scanf("%lld %lld", &px, &py);
        p[i] = {px, py};
    }
    for (int i=1; i<=n; i++) {
        to[i] = i+1;
    }

    int now = 1;
    for (int i=1; i<=n-2; i++) {
        int nxt = to[i];
        int nnxt = to[nxt];
        vec v1 = p[i] - p[nxt];
        vec v2 = p[nnxt] - p[nxt];
        if ((v1 & v2) >= 0) {
            to[i] = nnxt;
            to[nxt] = to[nnxt];
            to[nnxt] = nxt;
        }
    }

    now = 1;
    do {
        printf("%lld ", now);
        now = to[now];
    } while (now != n+1);
    printf("\n");

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
