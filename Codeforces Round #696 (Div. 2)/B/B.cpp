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
const int maxn = 5e4 + 7;

vector<int> prm;

void prepare() {
    prm.PB(2);
    for (int i=3; i<=maxn; i+=2) {
        bool flag = 0;
        for (int j=0; prm[j]*prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            prm.PB(i);
    }
}

int32_t main() {
    int i,j;
    int t;

    prepare();
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        vector<int> keep;
        keep.PB(1);
        for (auto it : prm) {
            if (it - keep.back() >= d) {
                keep.PB(it);
            }
            if (keep.size() == 3)
                break;
        }
        int ans = keep[1] * keep[2];
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
