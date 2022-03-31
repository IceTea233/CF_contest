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

int a[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool mark[11] = {};
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] <= 10)
                mark[a[i]] = true;
        }
        sort(a, a+n);

        if (a[n-1] == 1) {
            printf("1\n");
        } else if (a[n-1] == 2) {
            if (mark[1])
                printf("2\n");
            else
                printf("1\n");
        } else if (a[n-1] == 3) {
            if (mark[1] || mark[2])
                printf("2\n");
            else
                printf("1\n");
        } else if (a[n-1] == 4) {
            if ((mark[1] || mark[3]) && mark[2])
                printf("3\n");
            else
                printf("2\n");
        } else if (a[n-1] == 5) {
            if (mark[1] || mark[4])
                printf("3\n");
            else
                printf("2\n");
        } else if (a[n-1] == 6) {
            if (mark[1] || mark[2] || mark[4] || mark[5])
                printf("3\n");
            else
                printf("2\n");
        } else if (a[n-1] == 7) {
            if ((mark[1] || mark[6]) && (mark[2] || mark[5]))
                printf("4\n");
            else
                printf("3\n");
        } else {
            int ans = a[n-1] / 3 - (a[n-1] % 3 == 0) + 1;

            if (a[n-1] % 3 == 0) {
                for (int i=0; i<n; i++) {
                    if (a[i] % 3 != 0) {
                        ans = ans + 1;
                        break;
                    }
                }
            } else if (a[n-1] % 3 == 1) {
                bool one = false;
                bool r2 = false;
                for (int i=0; i<n; i++) {
                    if (a[i] == 1) {
                        one = true;
                    }
                    if (a[i] % 3 == 2) {
                        r2 = true;
                    }
                }

                if (one && r2)
                    ans = ans + 1;
            } else if (a[n-1] % 3 == 2) {
                bool r1 = false;
                for (int i=0; i<n; i++) {
                    if (a[i] % 3 == 1)
                        r1 = true;
                }
                if (r1) {
                    ans = ans + 1;
                }
            }

            printf("%lld\n", ans);
        }

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
