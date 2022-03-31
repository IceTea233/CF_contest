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
bool mark[maxn] = {};
vector<int> prm;

void prepare() {
    prm.PB(2);
    for(int i=3; i <= 32000; i++) {
        bool flag = true;
        for (int j=0; prm[j] * prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            prm.PB(i);
    }
}

bool illegal(int x, int d) {
    if (d <= 10000) {
        for (int i=0; prm[i] <= d; i++) {
            if (x % prm[i] != 0)
            return false;
        }
    } else {

    }
    return true;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    prepare();
    // printf("%d\n", prm.size());
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);

        memset(mark, 0, sizeof(bool) * (n+1));
        for (int i=0; prm[i] - 1 <= n; i++) {
            for (int j = prm[i] - 1; j <= n; j++) {
                // printf("num = %lld, d = %lld\n", a[j], prm[i]);
                if (a[j] % prm[i] != 0)
                    mark[j] = true;
            }
        }

        bool ans = true;
        for (int i=1; i<=n; i++) {
            if (!mark[i])
                ans = false;
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
