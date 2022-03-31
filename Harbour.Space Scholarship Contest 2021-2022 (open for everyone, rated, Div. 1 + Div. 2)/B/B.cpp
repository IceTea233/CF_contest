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

string s, t;
int ans = 0;
void guess(int idx, int now, int state) {
    if (ans)
        return;
    if (now == t.size()) {
        ans = 1;
        return;
    }

    if (0 <= idx && idx < s.size() && s[idx] == t[now]) {
        if (state == 0)
            guess(idx+1, now+1, 0);
        guess(idx-1, now+1, 1);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int q;

    cin >> q;
    while (q--) {
        cin >> s;
        cin >> t;
        ans = 0;
        for (int i=0; i<s.size(); i++) {
            guess(i, 0, 0);
            // if (ans)
            //     printf("i = %lld, success\n", i);
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
