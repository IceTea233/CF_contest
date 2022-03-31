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


int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        vector<int> cnt(4,0);
        int x = 0;
        int y = 0;
        for (auto it : s) {
            if (it == 'U') {
                y++;
                cnt[0]++;
            }
            else if (it == 'D') {
                cnt[1]++;
                y--;
            }
            else if (it == 'R') {
                cnt[2]++;
                x++;
            } else if (it == 'L') {
                cnt[3]++;
                x--;
            }
        }

        bool ans = 1;
        if (x > px) {
            if (cnt[2] < x-px)
                ans = 0;
        }
        if (x < px) {
            if (cnt[3] < px-x)
                ans = 0;
        }
        if (y > py) {
            if (cnt[0] < y-py)
                ans = 0;
        }
        if (y < py) {
            if (cnt[1] < py-y)
                ans = 0;
        }

        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
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
