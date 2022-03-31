#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 3e5 + 7;

int a[maxn] = {};
int l[maxn] = {};
int r[maxn] = {};

struct SGT{
    int tree[maxn*4][2][2] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void pull(int l, int r, int i) {
        tree[i][0][0] = max( {tree[LC(i)][0][0] + tree[RC(i)][1][0], tree[LC(i)][0][1] + tree[RC(i)][0][0], tree[LC(i)][0][0], tree[RC(i)][0][0]});
        tree[i][0][1] = max( {tree[LC(i)][0][0] + tree[RC(i)][1][1], tree[LC(i)][0][1] + tree[RC(i)][0][1], tree[LC(i)][0][1], tree[RC(i)][0][1]});
        tree[i][1][0] = max( {tree[LC(i)][1][0] + tree[RC(i)][1][0], tree[LC(i)][1][1] + tree[RC(i)][0][0], tree[LC(i)][1][0], tree[RC(i)][1][0]});
        tree[i][1][1] = max( {tree[LC(i)][1][0] + tree[RC(i)][1][1], tree[LC(i)][1][1] + tree[RC(i)][0][1], tree[LC(i)][1][1], tree[RC(i)][1][1]});
    }
    void build(int arr[], int l, int r, int i=1) {
        if (l==r) {
            tree[i][0][0] = arr[l];
            tree[i][1][1] = -arr[l];
            tree[i][0][1] = -INF;
            tree[i][1][0] = -INF;
            return;
        }

        int m = (l+r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l,r,i);
    }
    void upd(int x, int d, int l, int r, int i=1) {
        if (l==r) {
            tree[i][0][0] = d;
            tree[i][1][1] = -d;
            tree[i][0][1] = -INF;
            tree[i][1][0] = -INF;
            return;
        }

        int m = (l+r) / 2;
        if (x <= m)
            upd(x, d, l, m, LC(i));
        if (m+1 <= x)
            upd(x, d, m+1, r, RC(i));
        pull(l,r,i);
    }

    int query() {
        return max(tree[1][0][0], tree[1][0][1]);
    }
}seg;

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n,q;
        scanf("%lld %lld", &n, &q);
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);

        seg.build(a, 1, n);
        // while(1) {
        //     int l,r;
        //     cin >> l >> r;
        //     printf("%lld\n", );
        // }
        de(1) printf(">>> ");
        printf("%lld\n", seg.query());
        while(q--) {
            int l,r;
            scanf("%lld %lld", &l, &r);
            seg.upd(l, a[r], 1, n);
            seg.upd(r, a[l], 1, n);
            swap(a[l], a[r]);
            de(1) printf(">>> ");
            printf("%lld\n", seg.query());
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
