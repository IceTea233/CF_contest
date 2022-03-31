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

int trans(int x) {
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == 2)
        return 5;
    if (x == 5)
        return 2;
    if (x == 8)
        return 8;
    return -1;
}

int32_t main() {
    int i,j;
    int T;

    cin >> T;
    while (T--) {
        int h, m;
        cin >> h >> m;
        int H, M;
        scanf("%lld:%lld", &H, &M);
        while (1) {
            int h2 = 0;
            int m2 = 0;
            bool flag = 0;
            if (trans(M % 10) == -1)
                flag = 1;
            else
                h2 = trans(M % 10) * 10;

            if (trans(M / 10) == -1)
                flag = 1;
            else
                h2 += trans(M / 10);

            if (trans(H % 10) == -1)
                flag = 1;
            else
                m2 = trans(H % 10) * 10;

            if (trans(H / 10) == -1)
                flag = 1;
            else
                m2 += trans(H / 10);

            // printf(">>> %lld : %lld\n", h2, m2);
            if (!flag && h2 < h && m2 < m)
                break;

            M++;
            if (M == m) {
                H++;
                M = 0;
            }
            if (H == h)
                H = 0;
        }
        printf("%02lld:%02lld\n", H, M);
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
