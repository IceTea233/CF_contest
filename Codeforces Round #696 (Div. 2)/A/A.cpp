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

char a[maxn] = {};
char b[maxn] = {};
int num[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        scanf("%s", b);
        a[0] = '1';
        num[0] = (b[0]-'0') + (a[0]-'0');
        for (int i=1; i<n; i++) {
            if (num[i-1] == 0) {
                a[i] = '1';
            } else if (num[i-1] == 1) {
                if (b[i] == '0')
                    a[i] = '0';
                else
                    a[i] = '1';
            } else if (num[i-1] == 2) {
                if (b[i] == '0')
                    a[i] = '1';
                else
                    a[i] = '0';
            }
            num[i] = (b[i]-'0') + (a[i]-'0');
        }
        a[n] = 0;
        printf("%s\n", a);
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
