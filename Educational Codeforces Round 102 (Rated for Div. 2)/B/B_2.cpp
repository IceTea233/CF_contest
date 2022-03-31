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
const int maxn = 20 + 7;

char s[maxn] = {};
char t[maxn] = {};

int32_t main() {
    int i,j;
    int q;

    cin >> q;
    while(q--) {
        scanf("%s", s);
        scanf("%s", t);
        int n = strlen(s);
        int m = strlen(t);
        int k = 0;
        for (int i=1; i<=min(n, m); i++) {
            if (s[i-1] != t[i-1])
                break;
            if (n % i == 0 && m % i == 0) {
                bool flag = 0;
                for (int j=0; j<n; j++) {
                    if (s[j] != s[j%i])
                        flag = 1;
                }
                for (int j=0; j<m; j++) {
                    if (t[j] != t[j%i])
                        flag = 1;
                }
                if (!flag)
                    k = i;
            }
        }

        if (k == 0)
            printf("-1\n");
        else {
            string ans;
            for (int i=0; i<n*m/k; i++) {
                ans.PB(s[i%k]);
            }
            cout << ans << "\n";
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
