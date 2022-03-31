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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 3e5 + 7;

int n, m;
int arr[maxn] = {};
int cnt[maxn] = {};
int to[maxn] = {};
bool v[maxn] = {};

bool chk(int k) {
    memset(v, 0, n+1);
    for (int i=0; i<n; i++) {
        to[i] = (i + k) % n;
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (!v[i]) {
            int now = i;
            cnt ++;
            while (!v[now]) {
                v[now] = 1;
                now = to[arr[now]];
            }
        }
    }
    de(1) {
        printf("CHK (%lld):", k);
        for (int i=0; i<n; i++)
            printf(" %lld", to[i]);
        printf("\n");
        printf("cnt = %lld\n", cnt);
    }
    return (n - cnt <= m);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            scanf("%lld", &arr[i]);
            arr[i] -= 1;
        }

        for (int i=0; i<n; i++) {
            de(1) printf("k = %lld\n", ((i - arr[i]) % n + n) % n);
            cnt[((i - arr[i]) % n + n) % n] ++;
        }

        de(1) {
            printf("bump: ");
            for (int i=0; i<n; i++)
                printf("%lld ", cnt[i]);
            printf("\n");
        }

        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (cnt[i] >= n - 2*m) {
                if (chk(i))
                    ans.PB(i);
            }
        }

        printf("%d", ans.size());
        for (auto &it : ans)
            printf(" %lld", it);
        printf("\n");

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
