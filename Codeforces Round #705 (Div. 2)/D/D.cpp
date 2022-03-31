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
const int MOD = 1e9 + 7;

int a[maxn] = {};
vector<int> prm;

void prepare() {
    prm.PB(2);
    for (int i=3; i<maxn; i++) {
        bool flag = 0;
        for (int j=0; prm[j]*prm[j] <= i; j++) {
            if (i % prm[j] == 0)
                flag = 1;
        }
        if (!flag)
            prm.PB(i);
    }
}

multiset<int> st[maxn];
map<int,int> info[maxn];

int32_t main() {
    int i,j;
    int n,q;

    prepare();
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        int num = a[i];
        for (int j=0; prm[j]*prm[j] <= a[i]; j++) {
            int d = prm[j];
            if (a[i] % d == 0) {
                while (num % d == 0) {
                    info[i][d]++;
                    num /= d;
                }
            }
        }
        if (num > 1)
            info[i][num]++;
    }
    for (int i=1; i<=n; i++) {
        de(0) printf("%lld >>> ", i);
        for (auto it : info[i]) {
            de(0) printf("(%lld, %lld) ", it.F, it.S);
            st[it.F].insert(it.S);
        }
        de(0) printf("\n");
    }
    int ans = 1;
    for (int i=1; i<maxn; i++) {
        if (st[i].size() >= n) {
            for (int j=1; j<= *st[i].begin(); j++) {
                ans *= i;
                ans %= MOD;
            }
        }
    }
    de(1) {
        for (int i=1; i<maxn; i++) {
            if (st[i].size()) {
                printf("st[%lld] >>> ", i);
                for (auto it : st[i])
                printf("%lld ", it);
                printf("\n");
            }
        }
    }
    de(1) printf("origin >>> %lld\n", ans);

    while (q--) {
        int id, x;
        cin >> id >> x;
        vector<pii> tmp;
        for (int i=0; prm[i]*prm[i] <= x; i++) {
            int d = prm[i];
            if (x % d == 0) {
                pii p = {d, 0};
                while (x % d == 0) {
                    x /= d;
                    p.S++;
                }
                tmp.PB(p);
            }
        }
        if (x > 1)
            tmp.PB({x, 1});

        de(1) {
            printf("tmp >>> ");
            for (auto it : tmp) {
                printf("(%lld, %lld) ", it.F, it.S);
            }
            printf("\n");
        }

        for (auto it : tmp) {
            // printf("info : %lld has %lld of %lld\n", id, info[id][it.F], it.F);
            // printf("size of st before upd = %d\n", st[it.F].size());

            int pre = st[it.F].size() < n ? 0 : *st[it.F].begin();
            auto it2 = st[it.F].find(info[id][it.F]);
            if (it2 != st[it.F].end())
                st[it.F].erase( st[it.F].find(info[id][it.F]) );

            info[id][it.F] += it.S;
            // printf("upd. info : %lld has %lld of %lld\n", id, info[id][it.F], it.F);
            st[it.F].insert(info[id][it.F]);
            // printf("size of st after upd = %d\n", st[it.F].size());
            int nxt = st[it.F].size() < n ? 0 : *st[it.F].begin();

            // printf("pre = %lld, nxt = %lld\n", pre, nxt);
            for (int i=0; i < nxt-pre; i++) {
                ans *= it.F;
                ans %= MOD;
            }
        }

        de(1) printf("ans >>> ");
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
