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
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        int a = 10, b = 10;
        for (int i=0; i<10; i++) {
            if (s[i] == '1')
                cnt += i % 2 == 0 ? 1 : -1;
            else if (s[i] == '?' && i % 2 == 0)
                cnt += 1;

            if (cnt > (10 - i) / 2) {
                a = i+1;
                break;
            }
        }

        cnt = 0;
        for (int i=0; i<10; i++) {
            if (s[i] == '1')
                cnt += i % 2 == 1 ? 1 : -1;
                else if (s[i] == '?' && i % 2 == 1)
                    cnt += 1;

            if (cnt > (10 - i - 1) / 2) {
                b = i+1;
                break;
            }
        }

        int ans = min(a, b);
        // printf("(%lld, %lld)\n", a, b);
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
