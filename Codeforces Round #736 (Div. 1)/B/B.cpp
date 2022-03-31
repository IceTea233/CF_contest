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

struct SGT {
    int tree[maxn*4] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2 + 1;}
    void pull(int i) {
        tree[i] = __gcd(tree[LC(i)], tree[RC(i)]);
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        vector<int> tmp;
        if (x1 <= m)
            tmp.PB(query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            tmp.PB(query(x1, x2, m+1, r, RC(i)));
        int ret = tmp[0];
        for (auto &it : tmp)
            ret = __gcd(ret, it);
        return ret;
    }
}seg;

int n;
int arr[maxn] = {};
int d[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &arr[i]);
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        for (int i=1; i<=n-1; i++) {
            d[i] = abs(arr[i] - arr[i+1]);
        }
        seg.build(d, 1, n-1);
        int ans = 1;
        for (int l=1, r=1; l <= n-1; l++, r = max(r, l)) {
            int gcd = seg.query(l, r, 1, n-1);
            while (r < n-1 && __gcd(gcd, d[r+1]) > 1) {
                gcd = __gcd(gcd, d[++r]);
            }
            // printf("[%lld, %lld]\n", l, r);
            if (gcd > 1)
                ans = max(ans, r - l + 2);
        }
        printf("%lld\n", ans);
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
