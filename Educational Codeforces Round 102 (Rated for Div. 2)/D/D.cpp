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
const int maxn = 2e5 + 7;

struct SGT {
    struct node {
        int maxi;
        int mini;
    };
    node tree[maxn*4];

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i].maxi = max(tree[LC(i)].maxi, tree[RC(i)].maxi);
        tree[i].mini = min(tree[LC(i)].mini, tree[RC(i)].mini);
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l == r) {
            tree[i] = { arr[l], arr[l]};
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
    }
    node query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        node ret = {-INF, INF};
        if (x1 <= m) {
            node q = query(x1, x2, l, m, LC(i));
            ret = {max(ret.maxi, q.maxi), min(ret.mini, q.mini)};
        }
        if (m+1 <= x2) {
            node q = query(x1, x2, m+1, r, RC(i));
            ret = {max(ret.maxi, q.maxi), min(ret.mini, q.mini)};
        }
        return ret;
    }
}seg;

char s[maxn];
int pre[maxn] = {};
int bit[maxn] = {};
int n,m;

void upd(int x, int d) {
    while(x <= n) {
        bit[x] += d;
        x += x & (-x);
    }
}

int query(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

int tt(int l, int r) {
    return query(r) - query(l-1);
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(bit, 0, sizeof(int) * (n+7));
        scanf("%s", s);
        for (int i=1; i<=n; i++) {
            if (s[i-1] == '+') {
                pre[i] = pre[i-1]+1;
                upd(i, 1);
            }
            else {
                pre[i] = pre[i-1]-1;
                upd(i, -1);
            }
        }
        // for (int i=1; i<=n; i++) {
        //     printf("%lld ", pre[i]);
        // }
        // printf("\n");
        seg.build(pre, 1, n);
        // while(1) {
        //     int l, r;
        //     cin >> l >> r;
        //     printf("(%lld, %lld)\n", seg.query(l, r, 1, n).maxi, seg.query(l, r, 1, n).mini);
        // }
        while(m--) {
            int l,r;
            scanf("%lld %lld", &l, &r);
            int sum = tt(l, r);
            de(1) printf("sum = %lld\n", sum);

            int maxi = 0, mini = 0;
            if (l > 1) {
                maxi = seg.query(1, l-1, 1, n).maxi;
                mini = seg.query(1, l-1, 1, n).mini;
                de(1) printf("L >>> %lld, %lld\n", maxi, mini);
            }
            if (r < n) {
                maxi = max(maxi, seg.query(r+1, n, 1, n).maxi - sum);
                mini = min(mini, seg.query(r+1, n, 1, n).mini - sum);
                de(1) printf("R >>> %lld, %lld\n", seg.query(r+1, n, 1, n).maxi, seg.query(r+1, n, 1, n).mini);
            }
            int ans = maxi - mini + 1;
            if (0 < mini || 0 > maxi)
                ans++;
            printf("%lld\n", ans);
        }
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
