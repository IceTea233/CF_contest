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
const int maxn = 600;
const int MOD = 998244353;

int k,A,h;
int cht[6][600] = {};
int l[6] = {};
int r[6] = {};

int pwr(int x, int k) {
    int ret = 1;
    for (int i=1; i<=k; i++)
        ret = ret * x % MOD;
    return ret;
}

void prepare() {
    for (int i=0; i<=k; i++) {
        int mul = pwr(A, i == 0 ? 1 : (1LL<<(i-1)) + 1);
        de(1) printf("pwr(%lld, %lld)\n", A, i == 0 ? 1 : (1LL<<(i-1)) + 1);
        cht[i][0] = 0;
        for (int j=1; j<maxn; j++) {
            cht[i][j] = (cht[i][j-1] + mul) % MOD;
        }
    }

    l[0] = 1;
    r[0] = (1<<k);
    for (int i=1; i<=k; i++) {
        de(1) printf("%lld: ", i);
        for (int j=0; j < (1<<(i-1)); j++) {
            l[i] += (1 << (k - i + 1)) * j + 1;
            r[i] += (1 << (k - i + 1)) * (j+1);
            de(1) printf("(%lld, %lld) ", (1 << (k - i + 1)) * j + 1, (1 << (k - i + 1)) * (j+1));
        }
        de(1) printf("\n");
    }
}

bool flag = false;
vector<int> keep;
vector<vector<int>> cand;

int step = 0;
void solve(int cur=0, int sum=0) {
    step++;
    de(0) printf("solve(%lld, %lld)\n", cur, sum);
    if (cur > k) {
        if (sum == h) {
            cand.PB(keep);
        }
        return;
    }

    for (int i=l[cur]; i<=r[cur]; i++) {
        keep.PB(i);
        solve(cur+1, (sum + cht[cur][i]) % MOD);
        keep.PP();
    }
}

int ans[50] = {};
void solve2(vector<int> &keep, int cur, int lev, int sum) {
    if (flag)
        return;
    if (cur > (1 << lev)) {
        if (sum == keep[lev]) {
            lev ++;
            sum = 0;
        } else {
            return;
        }
    }

    de(2) {
        for (int i=1; i<=(1<<k); i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    if (cur > (1<<k)) {
        flag = true;
        return;
    }

    int len = (lev == 0 ? (1<<k) : (1 << (k - lev + 1)));
    int num = (lev == 0 ? 0 : cur - (1 << (lev-1)) - 1);
    de(0) printf("solve2(%lld, %lld, %lld)\n", cur, lev, sum);
    de(0) printf("len = %lld, num = %lld\n", len, num);
    // printf("range[%lld, %lld]\n", len * num + 1, len * (num + 1));
    for (int i = len * num + 1; i <= len * (num + 1); i++) {
        if (ans[i])
            continue;
        ans[i] = (lev == 0 ? 1 : (1 << (lev - 1)) + 1);
        solve2(keep, cur+1, lev, sum + i);
        if (flag)
            return;
        ans[i] = 0;
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> k >> A >> h;


    prepare();
    de(1) {
        for (int i=0; i<=k; i++)
            printf("%lld: [%lld, %lld]\n", i, l[i], r[i]);
    }
    solve();
    printf("%lld steps used\n", step);

    de(1) {
        for (auto it : cand) {
            printf("Sum Array: ");
                for (auto it2 : it)
            printf("%lld ", it2);
            printf("\n");
        }
    }

    for (auto &it : cand)
        solve2(it, 1, 0, 0);
    if (flag) {
        de(2) printf("ans: ");
        for (int i=1; i<=(1<<k); i++)
            printf("%lld ", ans[i]);
        printf("\n");
    } else {
        printf("-1\n");
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
