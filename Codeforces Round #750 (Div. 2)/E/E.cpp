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

int a[maxn] = {};
int pre[maxn] = {};
int maxi[500][maxn] = {};
int sum(int l, int r) {
    return pre[r] - pre[l-1];
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i];
        }

        int ans = 0;
        int back = n;
        for (int i=1; i<=n+1; i++)
            maxi[0][i] = INF;
        for (int i=1; i<500; i++) {
            maxi[i][back+1] = 0;
            for (int j=back; j>=1; j--) {
                if (sum(j, j + i - 1) < maxi[i-1][j + i]) {
                    maxi[i][j] = max(maxi[i][j+1], sum(j, j + i - 1));
                } else {
                    maxi[i][j] = maxi[i][j+1];
                }
            }
            // for (int j=1; j<=back; j++) {
            //     printf("%lld ", maxi[i][j]);
            // }
            // printf("\n");

            back -= i+1;
            while (back >= 1 && sum(back, back + i) >= maxi[i][back + i + 1])
                back --;
            if (back < 1) {
                ans = i;
                break;
            }
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
