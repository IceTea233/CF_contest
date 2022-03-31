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

int a[maxn] = {};

vector<int> ans;
void op(int i) {
    int k = (a[i] ^ a[i+1] ^ a[i+2]);
    a[i] = a[i+1] = a[i+2] = k;
    ans.PB(i);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }

        ans.clear();
        for (int i=1; i<=n-2; i++) {
            if (a[i] == 1) {
                int j = i;
                vector<int> stk;
                while (j <= n-2 && a[j+1] == a[j+2]) {
                    if (a[j+1] == 0) {
                        op(j);
                    }
                    stk.PB(j);
                    j += 2;
                }
                if (j <= n-2)
                    op(j);
                while (stk.size()) {
                    op(stk.back());
                    stk.PP();
                }
            } else {
                if (a[i+1] == 1 && a[i+2] == 1) {
                    op(i);
                }
            }
        }
        for (int i=n; i>=3; i--) {
            if (a[i] == 1) {
                int j = i;
                vector<int> stk;
                while (j >= 3 && (a[j-1] ^ a[j-2]) == 0) {
                    if (a[j-1] == 0)
                        op(j-2);
                    stk.PB(j-2);
                    j -= 2;
                }
                if (j >= 3)
                    op(j);
                while (stk.size()) {
                    op(stk.back());
                    stk.PP();
                }
            } else {
                if (a[i-1] == 1 && a[i-2] == 1) {
                    op(i-2);
                }
            }
        }

        bool flag = false;
        for (int i=1; i<=n; i++) {
            if (a[i] == 1)
                flag = true;
        }
        if (flag)
            printf("NO\n");
        else {
            printf("YES\n");
            printf("%d\n", ans.size());
            for (auto &it : ans)
                printf("%lld ", it);
            printf("\n");
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
