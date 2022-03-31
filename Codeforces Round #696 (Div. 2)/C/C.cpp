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
const int maxn = 2e3 + 7;

int a[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=2*n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a+1, a+2*n+1);

        vector<pii> ans;
        int x = 0;
        for (int i=1; i<2*n; i++) {
            de(1) printf("roudn %lld\n", i);
            bool flag = 0;
            ans.clear();
            multiset<int, greater<int> > st;
            for (int j=1; j<=2*n; j++) {
                st.insert(a[j]);
            }
            x = a[i] + a[2*n];
            int goal = x;
            while (!st.empty()) {
                de(1) printf("goal = %lld\n", goal);
                int x1 = *st.begin();
                st.erase(st.begin());
                de(1) printf("x1 = %lld\n", x1);
                auto it = st.find(goal-x1);
                if (it == st.end()) {
                    flag = 1;
                    break;
                } else {
                    int x2 = *it;
                    st.erase(it);
                    ans.PB({x1, x2});
                    goal = x1;
                }
            }
            if (!flag) {
                break;
            }
            ans.clear();
        }
        if (ans.empty())
            printf("NO\n");
        else {
            printf("YES\n");
            printf("%lld\n", x);
            for (auto it: ans)
                printf("%lld %lld\n", it.F, it.S);
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
