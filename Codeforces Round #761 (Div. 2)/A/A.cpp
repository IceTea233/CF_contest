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
        string S;
        cin >> S;
        string T;
        cin >> T;

        vector<int> cnt(26, 0);
        for (auto it : S) {
            cnt[it - 'a'] ++;
        }

        string ans;
        if (T == "abc" && cnt[0] && cnt[1] && cnt[2]) {
            for (int i=0; i<cnt[0]; i++)
                ans.PB('a');
            for (int i=0; i<cnt[2]; i++)
                ans.PB('c');
            for (int i=0; i<cnt[1]; i++)
                ans.PB('b');
            for (int i=3; i<26; i++) {
                for (int j=0; j < cnt[i]; j++)
                    ans.PB('a' + i);
            }

        } else {
            for (int i=0; i<26; i++) {
                for (int j=0; j < cnt[i]; j++)
                    ans.PB('a' + i);
            }
        }
        // cout << ">>> ";
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
