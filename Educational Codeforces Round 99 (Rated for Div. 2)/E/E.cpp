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
#define x F
#define y S
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 10;

pii P[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        for (int i=1; i<=4; i++) {
            cin >> P[i].x >> P[i].y;
        }
        vector<int> X, Y;
        for (int i=1; i<=4; i++) {
            X.PB(P[i].x);
            Y.PB(P[i].y);
        }
        sort(all(X));
        sort(all(Y));
        int max_w = X[3] - X[0];
        int min_w = X[2] - X[1];
        int max_h = Y[3] - Y[0];
        int min_h = Y[2] - Y[1];
        printf("(%lld, %lld), (%lld, %lld)\n", max_w, min_w, max_h, min_h);
        vector<int> tmp;
        tmp.PB(max_w);
        tmp.PB(min_w);
        tmp.PB(max_h);
        tmp.PB(min_h);
        sort(all(tmp));

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
