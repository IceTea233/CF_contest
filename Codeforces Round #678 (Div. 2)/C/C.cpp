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
const int maxn = 1e5 + 7;
const int MOD = 1e9 + 7;

int n, x, pos;

vector<int> keep;
bool BinarySearch(int x) {
    int left = 0;
    int right = n;

    de(1) printf("(%lld, %lld)\n", left, right);
    while(left < right) {
        int middle = (left + right) / 2;
        de(1) printf("middle = %lld\n", middle);
        if ( middle <= x) {
            left = middle + 1;
            keep.push_back(1);
        }
        else {
            right = middle;
            keep.push_back(0);
        }

        de(1) printf("(%lld, %lld)\n", left, right);
    }

    if (left > 0 && left == x)
        return 1;
    else
        return 0;
}

int P(int a, int b) {
    if (a < b || a < 0 || b < 0)
        return 0;
    int ret = 1;
    for (int i=0; i<b; i++) {
        ret *= (a-i);
        ret %= MOD;
    }
    return ret;
}

main() {
    int i,j;

    cin >> n >> x >> pos;
    BinarySearch(pos);
    // for (auto it: keep)
    //     printf("%lld", it);
    // printf("\n");
    int lock_0 = 0;
    int lock_1 = 0;

    for (auto it: keep) {
        if (it == 0)
            lock_0++;
        else
            lock_1++;
    }
    lock_1--;

    int ans = P(n-x, lock_0) % MOD * P(x-1, lock_1) % MOD * P(n-SZ(keep), n-SZ(keep)) % MOD;
    printf("%lld\n", ans);

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
