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

bool isprm(int x) {
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool isBase(int b, int x) {
    while (x % b == 0) {
        x /= b;
    }
    if (x == 1)
        return true;
    else
        return false;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int x, d;
        cin >> x >> d;

        bool ans = false;
        int cnt = 0;

        int y = x;
        while (y % d == 0) {
            y /= d;
            cnt ++;
        }

        if (cnt < 2) {
            ans = false; // OK
        } else { // cnt >= 2
            if (y == 1 || isprm(y)) { // there is a "d" taken to contain y.
                if (!isprm(d) && cnt > 2) {
                    if (y != 1 && isBase(y, d) && y * y == d && cnt == 3) {
                        ans = false;
                    } else {
                        ans = true;
                    }
                } else {
                    ans = false; // OK
                }
            } else { // y > 1 and is not prime. (product of at least 2 num)
                ans = true; // OK
            }
        }

        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
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
