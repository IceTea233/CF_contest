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
const int maxn = 1e6 + 7;

int AND(int i, int j) {
    printf("AND %lld %lld\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}
int OR(int i, int j) {
    printf("OR %lld %lld\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}
int XOR(int i, int j) {
    printf("XOR %lld %lld\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

int d[maxn] = {};
int ans[maxn] ={};

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    int AxorB = XOR(1, 2);
    int AxorC = XOR(1, 3);
    int AandB = AND(1, 2);
    int AandC = AND(1, 3);
    int BandC = AND(2, 3);
    for (int i=0; i<n; i++) {
        if ((AxorB >> i)&1) {
            if ((AxorC >> i)&1) {
                if ((BandC >> i)&1) {
                    ans[2] |= 1<<i;
                    ans[3] |= 1<<i;
                    if ((AandB >> i)&1)
                        ans[1] |= 1<<i;
                } else {
                    if ((AxorB >> i)&1)
                        ans[1] |= 1<<i;
                }
            } else {
                if ((AandC >> i)&1) {
                    ans[1] |= 1<<i;
                    ans[3] |= 1<<i;
                    if ((AandB >> i)&1)
                        ans[2] |= 1<<i;
                } else {
                    if ((AxorB >> i)&1)
                        ans[2] |= 1<<i;
                }
            }
        } else {
            if ((AandB >> i)&1) {
                ans[1] |= 1<<i;
                ans[2] |= 1<<i;
                if ((AandC >> i)&1)
                    ans[3] |= 1<<i;
            } else {
                if ((AxorC >> i)&1)
                    ans[3] |= 1<<i;
            }
        }
    }
    for (int i=4; i<=n; i++) {
        ans[i] = ans[i-1] ^ XOR(i-1, i);
    }

    printf("!");
    for (int i=1; i<=n; i++) {
        printf(" %lld", ans[i]);
    }
    printf("\n");

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
