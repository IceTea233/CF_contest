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

char s[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n,q;

    cin >> n >> q;
    scanf("%s", s+1);
    int ans = 0;
    for (int i=1; i<=n-2; i++) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
            ans++;
    }
    while (q--) {
        int i;
        char c;
        scanf("%lld %c", &i, &c);
        for (int j=i-2; j<=i; j++) {
            if (j <= 0 || j + 2 > n)
                continue;
            if (s[j] == 'a' && s[j+1] == 'b' && s[j+2] == 'c')
                ans --;
        }
        s[i] = c;
        for (int j=i-2; j<=i; j++) {
            if (j <= 0 || j + 2 > n)
                continue;
            if (s[j] == 'a' && s[j+1] == 'b' && s[j+2] == 'c')
                ans ++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
