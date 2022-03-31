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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int r = 1, c = 1;
        int cnt = 0;
        for (auto it : s) {
            if (it == 'R') {
                c ++;
            } else if (it == 'D') {
                r ++;
            }
        }

        int r_2 = 1, c_2 = 1;
        bool flag_r = false, flag_d = false;
        for (auto it : s) {
            if (it == 'R') {
                flag_r = true;
                c_2 ++;
                if (!flag_d)
                    cnt += n - 1;
                else {
                    cnt += (n - r_2) - (n - r);
                }
            } else if (it == 'D') {
                flag_d = true;
                r_2 ++;
                if (!flag_r)
                    cnt += n - 1;
                else {
                    cnt += (n - c_2) - (n - c);
                }
            }
            // printf("cnt >>> %lld\n", cnt);
        }

        if (!flag_r || !flag_d)
            cnt = (n - 1) * n;

        int ans = n * n - cnt;
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
