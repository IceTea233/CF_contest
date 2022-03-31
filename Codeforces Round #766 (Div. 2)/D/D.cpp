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

int a[maxn] = {};
bool exist[maxn] = {};

vector<int> prm;

void prepare() {
    prm.PB(2);
    for (int i=3; i<maxn; i++) {
        bool flag = false;
        for (int j=0; prm[j] * prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag)
            prm.PB(i);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    prepare();
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        exist[a[i]] = true;
    }

    int ans = 0;
    for (int i=1000000; i>=1; i--) {
        if (exist[i])
            continue;
        int gcd = 0;
        for (int j=2; i * j <= 1000000; j++) {
            if (exist[i * j]) {
                if (!gcd)
                    gcd = j;
                else
                    gcd = __gcd(gcd, j);
            }
        }
        if (gcd == 1) {
            exist[i] = true;
            ans ++;
        }
    }

    printf("%lld\n", ans);

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
