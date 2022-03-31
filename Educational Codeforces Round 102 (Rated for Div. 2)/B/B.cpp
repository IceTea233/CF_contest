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
        int ans = INF;
        for (int i=200; i>0; i--) {
            if (n * i % m != 0)
                continue;
            string s1;
            for (int j=0; j<i; j++) {
                for (int k=0; k<n; k++)
                    s1.PB(s[k]);
            }
            bool flag = 0;
            for (int j=0; j<s1.size(); j++) {
                if (s1[j] != t[j%m])
                    flag = 1;
            }

            if (!flag)
                ans = i;
        }

        if (ans == INF)
            printf("-1\n");
        else {
            string output;
            for (int i=0; i<ans; i++) {
                for (int j=0; j<n; j++)
                    output.PB(s[j]);
            }
            cout << output << "\n";
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
