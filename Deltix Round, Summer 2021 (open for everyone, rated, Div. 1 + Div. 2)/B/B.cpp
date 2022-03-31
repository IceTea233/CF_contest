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
        // printf(">>> ");
        set<int> odd;
        set<int> even;
        for (int i=1; i<=n; i++) {
            if (a[i] % 2 == 0)
                even.insert(i);
            else
                odd.insert(i);
        }

        if (odd.size() == even.size() + 1) { // case 1
            int ans = 0;
            auto tmp1 = odd;
            auto tmp2 = even;
            for (int i=1; i<=n; i++) {
                if (i % 2 == 1 && a[i] % 2 == 0) {
                    int ptr = *tmp1.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans += ptr - i;
                    tmp1.erase(ptr);
                    tmp1.insert(i);
                    tmp2.erase(i);
                    tmp2.insert(ptr);
                } else if (i % 2 == 0 && a[i] % 2 == 1) {
                    int ptr = *tmp2.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans += ptr - i;
                    tmp2.erase(ptr);
                    tmp2.insert(i);
                    tmp1.erase(i);
                    tmp1.insert(ptr);
                }
            }
            printf("%lld\n", ans);
        } else if (even.size() == odd.size() + 1) { // case 2
            int ans = 0;
            auto tmp1 = odd;
            auto tmp2 = even;
            for (int i=1; i<=n; i++) {
                if ((i+1) % 2 == 1 && a[i] % 2 == 0) {
                    int ptr = *tmp1.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans += ptr - i;
                    tmp1.erase(ptr);
                    tmp1.insert(i);
                    tmp2.erase(i);
                    tmp2.insert(ptr);
                } else if ((i+1) % 2 == 0 && a[i] % 2 == 1) {
                    int ptr = *tmp2.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans += ptr - i;
                    tmp2.erase(ptr);
                    tmp2.insert(i);
                    tmp1.erase(i);
                    tmp1.insert(ptr);
                }
            }
            printf("%lld\n", ans);
        } else if (odd.size() == even.size()) { // case 3
            int ans1 = 0;
            auto tmp1 = odd;
            auto tmp2 = even;
            for (int i=1; i<=n; i++) {
                if (i % 2 == 1 && a[i] % 2 == 0) {
                    int ptr = *tmp1.lower_bound(i);
                    // printf("swap(%lld, %lld)\n", i, ptr);
                    swap(a[i], a[ptr]);
                    ans1 += ptr - i;
                    tmp1.erase(ptr);
                    tmp1.insert(i);
                    tmp2.erase(i);
                    tmp2.insert(ptr);
                } else if (i % 2 == 0 && a[i] % 2 == 1) {
                    int ptr = *tmp2.lower_bound(i);
                    // printf("swap(%lld, %lld)\n", i, ptr);
                    swap(a[i], a[ptr]);
                    ans1 += ptr - i;
                    tmp2.erase(ptr);
                    tmp2.insert(i);
                    tmp1.erase(i);
                    tmp1.insert(ptr);
                }
            }

            int ans2 = 0;
            tmp1 = odd;
            tmp2 = even;
            for (int i=1; i<=n; i++) {
                if ((i + 1) % 2 == 1 && a[i] % 2 == 0) {
                    int ptr = *tmp1.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans2 += ptr - i;
                    tmp1.erase(ptr);
                    tmp1.insert(i);
                    tmp2.erase(i);
                    tmp2.insert(ptr);
                } else if ((i + 1) % 2 == 0 && a[i] % 2 == 1) {
                    int ptr = *tmp2.lower_bound(i);
                    swap(a[i], a[ptr]);
                    ans2 += ptr - i;
                    tmp2.erase(ptr);
                    tmp2.insert(i);
                    tmp1.erase(i);
                    tmp1.insert(ptr);
                }
            }

            int ans = min(ans1, ans2);
            printf("%lld\n", ans);
        } else {
            printf("-1\n");
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
