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
const int maxn = 3e5 + 7;

int n,m;

struct SGT {
    int tree[maxn * 4] = {};
    int tag[maxn * 4] = {};
    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i] = min(tree[LC(i)], tree[RC(i)]);
    }
    void push(int l, int r, int i) {
        tag[LC(i)] += tag[i];
        tag[RC(i)] += tag[i];
        tree[LC(i)] += tag[i];
        tree[RC(i)] += tag[i];
        tag[i] = 0;
    }

    void build(int l, int r, int i=1) {
        if (l == r) {
            tree[i] = 0;
            tag[i] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(l, m, LC(i));
        build(m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        // printf("UPD(%lld, %lld)\n", l, r);
        if (x1 <= l && r <= x2) {
            tree[i] += d;
            tag[i] += d;
            // printf("[%lld, %lld] -> %lld\n", l, r, tree[i]);
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(l, r, i);
        // printf("[%lld, %lld] -> %lld\n", l, r, tree[i]);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = INF;
        push(l, r, i);
        if (x1 <= m)
            ret = min(ret, query(x1, x2, l, m, LC(i)));
        if (m+1 <= x2)
            ret = min(ret, query(x1, x2, m+1, r, RC(i)));
        return ret;
    }

}seg;

struct info {
    int l;
    int r;
    int w;
};
info arr[maxn] = {};

bool cmp(info a, info b) {
    return a.w < b.w;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> m;
    vector<info> keep;
    for (int i=1; i<=n; i++) {
        int l, r, w;
        scanf("%lld %lld %lld", &l, &r, &w);
        keep.PB({l, r, w});
    }
    sort(all(keep), cmp);
    for (auto &it : keep)
        printf("%lld %lld %lld\n", it.l, it.r, it.w);

    seg.build(1, m);
    for (int i=0, j=0; i<n; i++) {
        seg.upd(keep[i].l, keep[i].r-1, 1, 1, m);
        printf(">>> %lld\n", seg.query(1, m-1, 1, m));
    }

    // while (1) {
    //     int l, r;
    //     cin >> l >> r;
    //     printf("%lld\n", seg.query(l, r, 1, m));
    // }

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
