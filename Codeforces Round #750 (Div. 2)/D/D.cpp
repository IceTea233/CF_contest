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

int a[maxn] = {};
int ans[maxn] = {};
bool neg[maxn] = {};

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
            if (a[i] < 0) {
                a[i] *= -1;
                neg[i] = true;
            } else {
                neg[i] = false;
            }
        }

        int glb = 0;
        for (int i=2; i<=n; i++) {
            glb += a[i];
        }

        int tt = 1;
        int sum = glb;
        int tune = 0;
        while (sum) {
            // printf("sum = %lld\n", sum);
            if (sum > 0) {
                int d = sum / a[1] + (sum % a[1] != 0);
                tune += d;
                sum -= a[1] * d;
            } else if (sum < 0) {
                int d = (-sum) / glb + (sum % glb != 0);
                tt +=  d;
                sum += glb * d;
            }
        }

        ans[1] = tune * -1 * (neg[1] ? 1 : -1);
        for (int i=2; i<=n; i++)
            ans[i] = tt * (neg[i] ? 1 : -1);

        for (int i=1; i<=n; i++)
            printf("%lld ", ans[i]);
        printf("\n");
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
