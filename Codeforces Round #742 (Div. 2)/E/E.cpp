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
        int inc_l;
        int inc_r;
        bool beauty;
        int cnt;
    };
    node tree[maxn*4] = {};
    int arr[maxn] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void pull(int l, int r, int i) {
        int m = (l + r) / 2;
        if (arr[m] <= arr[m+1]) {
            tree[i].inc_l = tree[LC(i)].inc_l + (tree[LC(i)].beauty ? tree[RC(i)].inc_l : 0);
            tree[i].inc_r = tree[RC(i)].inc_r + (tree[RC(i)].beauty ? tree[LC(i)].inc_r : 0);
            tree[i].beauty = tree[LC(i)].beauty && tree[RC(i)].beauty;
            tree[i].cnt = tree[LC(i)].cnt + tree[RC(i)].cnt + tree[LC(i)].inc_r * tree[RC(i)].inc_l;
        } else {
            tree[i].inc_l = tree[LC(i)].inc_l;
            tree[i].inc_r = tree[RC(i)].inc_r;
            tree[i].beauty = false;
            tree[i].cnt = tree[LC(i)].cnt + tree[RC(i)].cnt;
        }
    }
    void build(int *a, int l, int r, int i=1) {
        if (l == r) {
            arr[l] = a[l];
            tree[i] = {1, 1, true, 1};
            return;
        }
        int m = (l + r) / 2;
        build(a, l, m, LC(i));
        build(a, m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l == r) {
            arr[x] = d;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(l, r ,i);
    }
    node query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        node q1 = {0, 0, 0};
        node q2 = {0, 0, 0};
        if (x1 <= m) {
            q1 = query(x1, x2, l, m, LC(i));
        }
        if (m+1 <= x2) {
            q2 = query(x1, x2, m+1, r, RC(i));
        }

        node ret = {0, 0, 0};
        if (q1.cnt == 0) {
            ret = q2;
        } else if (q2.cnt == 0) {
            ret = q1;
        } else {
            ret = {q1.inc_l, q2.inc_r, false, q1.cnt + q2.cnt};
            if (arr[m] <= arr[m+1]) {
                de(1) printf("qry(%lld, %lld, %lld, %lld)\n", x1, x2, l, r);
                ret.beauty = q1.beauty && q2.beauty;
                if (q1.beauty) {
                    de(1) printf("connect from %lld to %lld\n", m, m+1);
                    ret.inc_l += q2.inc_l;
                }
                if (q2.beauty) {
                    de(1) printf("connect from %lld to %lld\n", m+1, m);
                    ret.inc_r += q1.inc_r;
                }
                ret.cnt += q1.inc_r * q2.inc_l;
            }
        }
        return ret;
    }
}seg;

int a[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n, q;

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    seg.build(a, 1, n);

    while (q--) {
        int t;
        scanf("%lld", &t);
        if (t == 1) {
            int x, y;
            scanf("%lld %lld", &x, &y);
            seg.upd(x, y, 1, n);
        } else if (t == 2) {
            int l, r;
            scanf("%lld %lld", &l, &r);
            auto qry = seg.query(l, r, 1, n);
            de(1) printf("(%lld, %lld, %lld)\n", qry.inc_l, qry.inc_r, qry.cnt);
            printf("%lld\n", qry.cnt);
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
