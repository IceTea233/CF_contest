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
#define l F
#define r S
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e5 + 7;

struct SGT {
    int tree[maxn*4];
    int tag[maxn*4];

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}

    void push(int l, int r, int i) {
        int m = (l + r) / 2;
        if (tag[i] == -1)
            return;
        tree[LC(i)] = (m - l + 1) * tag[i];
        tree[RC(i)] = (r - m) * tag[i];
        tag[LC(i)] = tag[i];
        tag[RC(i)] = tag[i];
        tag[i] = -1;
    }
    void pull(int l, int r, int i) {
        tree[i] = tree[LC(i)] + tree[RC(i)];
        if (tag[LC(i)] == tag[RC(i)])
            tag[i] = tag[LC(i)];
    }
    void build(int arr[], int l, int r, int i=1) {
        tag[i] = -1;
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] = (r-l+1) * d;
            tag[i] = d;
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
        pull(l, r, i);
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = 0;
        push(l, r, i);
        if (x1 <= m)
            ret += query(x1, x2, l, m, LC(i));
        if (m+1 <= x2)
            ret += query(x1, x2, m+1, r, RC(i));
        pull(l, r, i);
        return ret;
    }
}seg;

char s[maxn];
char f[maxn];
int a1[maxn] = {};
int a2[maxn] = {};
int chk[maxn] = {};
pii b[maxn];

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        scanf("%s", s);
        scanf("%s", f);
        for (int i=1; i<=q; i++) {
            scanf("%lld %lld", &(b[i].l), &(b[i].r));
        }

        for (int i=1; i<=n; i++) {
            a1[i] = (s[i-1] == '1');
            a2[i] = (f[i-1] == '1');
        }

        bool ans = 1;
        seg.build(a2, 1, n);
        for (int i=q; i>=1; i--) {
            de(1) printf("i = %lld\n", i);
            de(1) {
                printf("chk = ");
                for (int i=1; i<=n; i++)
                    printf("%lld", seg.query(i, i, 1, n));
                printf("\n");
            }
            int len = b[i].r - b[i].l + 1;
            int one = seg.query(b[i].l, b[i].r, 1, n);
            int zero = len - one;
            if (one < zero) {
                seg.upd(b[i].l, b[i].r, 0, 1, n);
            } else if (one > zero) {
                seg.upd(b[i].l, b[i].r, 1, 1, n);
            } else if (one > 0 && zero > 0) {
                de(1) printf("stop\n");
                ans = 0;
                break;
            }
        }
        for (int i=1; i<=n; i++) {
            chk[i] = seg.query(i, i, 1, n);
        }
        de(1) {
            printf("chk = ");
            for (int i=1; i<=n; i++)
                printf("%lld", chk[i]);
            printf("\n");
        }
        for (int i=1; i<=n; i++) {
            if (chk[i] != a1[i])
                ans = 0;
        }

        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
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
