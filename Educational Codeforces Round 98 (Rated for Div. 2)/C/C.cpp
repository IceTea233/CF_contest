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
const int maxn = 2e5 + 7;

char s[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        scanf("%s", s);
        int n = strlen(s);
        int a = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                if (cnt > 0) {
                    cnt--;
                    a++;
                }
            }
        }
        int b = 0;
        cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '[') {
                cnt++;
            } else if (s[i] == ']') {
                if (cnt > 0) {
                    cnt--;
                    a++;
                }
            }
        }
        printf("%lld\n", a+b);
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
