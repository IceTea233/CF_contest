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

int dis(int x, int y) {
    return x*x + y*y;
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int d, k;
        cin >> d >> k;
        int x = 0;
        int y = 0;
        for (x=0; dis( (x+1)*k, 0) <= d*d; x++);
        for (y=0; dis( x*k, (y+1)*k) <= d*d; y++);

        while(x > y) {
            x--;
            while ( dis( x*k, (y+1)*k) <= d*d )
                y++;
        }
        // printf("(%lld, %lld)\n", x, y);
        if ((x + y ) % 2 == 0)
            printf("Utkarsh\n");
        else
            printf("Ashish\n");
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
