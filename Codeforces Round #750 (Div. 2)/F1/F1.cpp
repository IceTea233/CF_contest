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
const int maxn = 1e5 + 7;

int a[maxn] = {};
set<int> dp[maxn] = {};

bool cmp(pii a, pii b) {
    if (a.F == b.F)
        return a.S > b.S;
    return a.F < b.F;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    vector<pii> keep;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        keep.PB({a[i], i});
    }
    sort(all(keep), cmp);

    set<int> st;
    set<int> ans;
    dp[0].insert(0);
    st.insert(0);
    ans.insert(0);
    for (int i=1; i<=n; i++) {
        int val = a[i];
        int pos = i;
        int pre = *prev(st.lower_bound(val));
        // printf("pre = %lld\n", pre);
        dp[val] = dp[pre];
        for (auto &it2 : dp[pre]) {
            // printf(">>> %lld ", it2);
            int x = (it2 ^ val);
            dp[val].insert(x);
            ans.insert(x);
        }
        // printf("\n");
        st.insert(val);
    }

    // for (int i=1; i<=n; i++) {
    //     printf("i = %lld >>>", i);
    //     for (auto it2 : dp[i])
    //         printf(" %lld", it2);
    //     printf("\n");
    // }

    printf("%d\n", ans.size());
    for (auto it : ans)
        printf("%lld ", it);
    printf("\n");

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
