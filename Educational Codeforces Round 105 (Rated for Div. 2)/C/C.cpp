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

int a[maxn] = {};
int b[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;

        int base_pos = 0;
        int base_neg = 0;
        int neg1 = 0;
        set<int> st;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            if (a[i] < 0)
                neg1 = i;
            st.insert(a[i]);
        }
        int neg2 = 0;
        for (int i=1; i<=m; i++) {
            cin >> b[i];
            if (b[i] < 0) {
                neg2 = i;
            }
        }
        for (int i=1; i<=m; i++) {
            if (st.find(b[i]) != end(st)) {
                if (b[i] < 0)
                    base_neg++;
                else
                    base_pos++;
            }
        }

        int ans1 = 0;
        int cnt = 0;
        int idx = neg1+1;
        int len = 0;
        for (int i=neg2+1, j=neg2+1; i<=m; i++) {
            while (idx <= n && a[idx] <= b[i] + len - 1) {
                idx++;
                len++;
            }
            while (j <= m && b[j] <= b[i]+len-1) {
                if (st.find(b[j]) != end(st))
                    base_pos--;
                j++;
            }
            de(1) printf("len = %lld\n", len);
            de(1) printf("(%lld, %lld)\n", i, j-1);
            de(1) printf("base = %lld\n", base_pos);
            de(1) printf("cnt = %lld\n", base_pos + j - i);
            ans1 = max(ans1, base_pos + (j-1) - i + 1);
        }

        de(1) printf("\n");
        int ans2 = 0;
        cnt = 0;
        idx = neg1;
        len = 0;
        for (int i=neg2, j=neg2; i>=1; i--) {
            while (idx >= 1 && a[idx] >= b[i] - len + 1) {
                idx--;
                len++;
            }
            while (j >= 1 && b[j] >= b[i]-len+1) {
                if (st.find(b[j]) != end(st))
                    base_neg--;
                j--;
            }
            de(1) printf("len = %lld\n", len);
            de(1) printf("(%lld, %lld)\n", j+1, i);
            de(1) printf("base = %lld\n", base_neg);
            de(1) printf("cnt = %lld\n", base_neg + i - (j+1) + 1);
            ans2 = max(ans2, base_neg + i - (j+1) + 1);

        }

        int ans = ans1 + ans2;
        de(2) printf("ans1 = %lld, ans2 = %lld\n", ans1, ans2);
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
