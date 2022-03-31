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
const int maxn = 2e5 + 7;

// char x[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        string x;
        // scanf("%s", x + 1);
        cin >> x;
        // int N = strlen(x + 1);
        int N = x.size();
        string ans;
        for (int i = N - 2; i >= 0; i--) {
            // printf("i = %lld\n", i);
            int a = x[i] - '0';
            int b = x[i + 1] - '0';
            if (a + b >= 10) {
                for (int j = 0; j < i; j++) {
                    ans.PB(x[j]);
                }
                ans.PB((a + b) / 10 + '0');
                ans.PB((a + b) % 10 + '0');
                for (int j = i + 2; j < N; j++) {
                    ans.PB(x[j]);
                }
                break;
            }
        }

        if (!ans.empty()) {
            cout << ans << "\n";
            continue;
        }

        // printf("OK\n");

        ans.PB(x[0] - '0' + x[1] - '0' + '0');
        for (int i=2; i < N; i++) {
            ans.PB(x[i]);
        }
        cout << ans << "\n";
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
