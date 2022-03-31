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
const int maxn = 1e2 + 7;

char ans[maxn][maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        memset(ans, 0, sizeof(ans));

        bool flag = true;
        for (int i=1; i<=n; i++)
            ans[i][i] = 'X';
        for (int i=1; i<=n; i++) {
            if (s[i] == '1') {
                for (int j=1; j<=n; j++) {
                    if (i != j)
                        ans[i][j] = ans[j][i] = '=';
                }
            }
        }

        for (int i=1; i<=n; i++) {
            if (s[i] == '2') {
                bool win = false;
                for (int j=1; j<=n; j++) {
                    if (!ans[i][j]) {
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                        win = true;
                        break;
                    }
                }

                if (!win)
                    flag = false;
            }
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (!ans[i][j])
                    ans[i][j] = '=';
            }
        }

        if (flag) {
            printf("YES\n");
            for (int i=1; i<=n; i++)
                printf("%s\n", ans[i]+1);
        } else {
            printf("NO\n");
        }
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
