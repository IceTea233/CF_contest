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

string s[maxn] = {};

bool isPalin(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> s[i];
        }

        bool ans = false;

        set<string> st2;
        set<string> st3;
        for (int i=1; i<=n; i++) {
            if (isPalin(s[i]))
                ans = true;
            if (s[i].size() == 2) {
                string x = s[i];
                reverse(all(x));
                if (st2.find(x) != st2.end() || st3.find(x) != st3.end()) {
                    ans = true;
                }
                st2.insert(s[i]);
            } else if (s[i].size() == 3) {
                string x = s[i];
                reverse(all(x));
                if (st3.find(x) != st3.end() || st2.find(x.substr(0, 2)) != st2.end()) {
                    ans = true;
                }
                st3.insert(s[i]);
                st3.insert(s[i].substr(0, 2));
            }
        }
        // de(1) {
        //     printf("--- set ---\n");
        //     for (auto it : st)
        //         cout << it << "\n";
        //     printf("--- --- ---\n");
        // }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
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
