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
const int maxm = 1e6 + 7;

int a[maxn] = {};

bool isprm[maxm] = {};

void prepare() {
    for (int i=2; i < maxm; i++)
        isprm[i] = true;
    for (int i=2; i < maxm; i++) {
        if (isprm[i]) {
            for (int j = i * 2; j < maxm; j += i)
                isprm[j] = false;
        }
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    prepare();
    cin >> t;
    while (t--) {
        int n, e;
        scanf("%lld %lld", &n, &e);
        // cout << n << " " << e << "\n";
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }

        int ans = 0;
        for (int i = 1; i <= e; i++) {
            int add = 0;
            int cnt = 0;
            // printf(">>>");
            for (int j = i; j <= n; j += e) {
                // printf(" %lld", a[j]);
                // if (isprm[a[j]])
                //     printf("*");
                // if (a[j] == 1)
                //     printf("#");
                if (a[j] == 1) {
                    cnt++;
                    ans += add;
                } else if (isprm[a[j]]) {
                    add = cnt + 1;
                    cnt = 0;
                    ans += add - 1;
                } else {
                    add = 0;
                    cnt = 0;
                }
            }
            // printf("; ans = %lld\n", ans);
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
