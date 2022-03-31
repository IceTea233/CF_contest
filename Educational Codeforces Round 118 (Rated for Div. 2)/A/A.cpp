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

int dgt(int x) {
    int ret = 0;
    while (x) {
        ret++;
        x /= 10;
    }
    return ret;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int x1, p1;
        cin >> x1 >> p1;
        int x2, p2;
        cin >> x2 >> p2;
        if (dgt(x1) + p1 > dgt(x2) + p2) {
            printf(">\n");
        } else if (dgt(x1) + p1 < dgt(x2) + p2) {
            printf("<\n");
        } else {
            int d = p1 - p2;
            if (d > 0) {
                for (i=0; i<d; i++)
                    x1 *= 10;
            } else {
                for (i=0; i<-d; i++)
                    x2 *= 10;
            }
            // printf(">>> %lld %lld\n", x1, x2);
            if (x1 > x2)
                printf(">\n");
            else if (x1 < x2)
                printf("<\n");
            else
                printf("=\n");
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
