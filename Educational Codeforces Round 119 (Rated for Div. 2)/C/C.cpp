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
const int maxn = 2e3 + 7;


int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;

        x -= 1;
        vector<int> keep;
        int cnt = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '*')
                cnt += k;
            else {
                keep.PB(cnt);
                cnt = 0;
            }
        }
        keep.PB(cnt);

        vector<int> tool(keep.size(), 0);
        tool.back() = 1;
        for (int i=keep.size()-1; i > 0; i--) {
            if (x / tool[i] + 1 >= keep[i] + 1) {
                tool[i-1] = tool[i] * (keep[i] + 1);
            } else {
                break;
            }
        }

        // for (auto it : keep)
        //     printf("%lld ", it);
        // printf("\n");
        // for (auto it : tool)
        //     printf("%lld ", it);
        // printf("\n");

        string ans;
        for (int i=0; i < keep.size(); i++) {
            int cnt = 0;
            if (tool[i] != 0) {
                cnt = min(x / tool[i], keep[i]);
                for (int j=0; j<cnt; j++)
                    ans.PB('b');
            }

            if (i + 1 < keep.size())
                ans.PB('a');

            x -= tool[i] * cnt;
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
