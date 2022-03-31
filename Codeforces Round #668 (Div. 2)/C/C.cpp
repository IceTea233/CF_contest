#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 3e5 + 7;

char s[maxn] = {};
int cnt[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        scanf("%s", s+1);

        bool ans = 1;
        queue<pii> que;
        for (i=1; i<=n; i++) {
            if (s[i] == '1') {
                if (i-k >= 1) {
                    if (s[i-k] == '0')
                        ans = 0;
                    if (s[i-k] == '?')
                        que.push({i,'1'});
                }
                if (i+k <= n) {
                    if (s[i+k] == '0')
                        ans = 0;
                    if (s[i+k] == '?')
                        que.push({i,'1'});
                }
            }
            else if(s[i] == '0') {
                if (i-k >= 1) {
                    if (s[i-k] == '1')
                        ans = 0;
                    if (s[i-k] == '?')
                        que.push({i,'0'});
                }
                if (i+k <= n) {
                    if (s[i+k] == '1')
                        ans = 0;
                    if (s[i+k] == '?')
                        que.push({i,'0'});
                }
            }
        }

        while(!que.empty()) {
            pii now = que.front();
            que.pop();
            de(0) printf("now = (%lld, %lld)\n", now.F, now.S);
            de(0) system("PAUSE");
            if (s[now.F] == '?')
                s[now.F] = now.S;
            else if (s[now.F] != now.S)
                ans = 0;

            if (now.F - k >= 1) {
                if (s[now.F - k] == '?')
                    que.push({ now.F - k, now.S});
                else if(s[now.F - k] != now.S)
                    ans = 0;
            }
            if (now.F + k <= n) {
                if (s[now.F + k] == '?')
                    que.push({ now.F + k, now.S});
                else if(s[now.F + k] != now.S)
                    ans = 0;
            }
        }

        int one = 0;
        int zero = 0;
        for (int i=1; i<=k; i++) {
            if (s[i] == '1')
                one++;
            if (s[i] == '0')
                zero++;
        }
        if (one > k/2 || zero > k/2)
            ans = 0;

        de(1) printf("final = %s\n", s+1);
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
