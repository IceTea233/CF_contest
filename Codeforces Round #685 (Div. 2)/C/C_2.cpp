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
const int maxn = 1e6 + 7;

int cnta[27] = {};
int cntb[27] = {};
char a[maxn] = {};
char b[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        scanf("%s", a+1);
        scanf("%s", b+1);

        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        for (int i=1; i<=n; i++) {
            cnta[a[i]-'a']++;
        }
        for (int i=1; i<=n; i++) {
            cntb[b[i]-'a']++;
        }
        // sort(a+1, a+n+1);
        // sort(b+1, b+n+1);

        bool ans = 1;
        for (int i=0; i<25; i++) {
            while(cnta[i] > cntb[i]) {
                cnta[i] -= k;
                cnta[i+1] += k;
            }
            if (cnta[i] != cntb[i]) {
                ans = 0;
                break;
            }
        }

        if (cnta[25] != cntb[25]) {
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
