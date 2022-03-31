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


int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        for (int i=0; i < b - a; i++) {
            int B = b + i;
            int trie;
            int note = 20;
            for (j = 20; j >= 0; j--) {
                if (((a >> j) & 1) == 0 && ((B >> j) & 1) == 1) {
                    note = j;
                } else if (((a >> j) & 1) == 1 && ((B >> j) & 1) == 0) {
                    trie = (1 << note) - (a & ((1 << note) - 1)) + i + 1;
                    break;
                }
            }
            if (j < 0)
                trie = i + 1;

            // if (trie < 100)
            //     cerr << "i = " << i << ", trie = " << trie << "\n";
            ans = min(ans, trie);
        }
        // cerr << "ans = ";
        printf("%lld\n", ans);
    }

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
