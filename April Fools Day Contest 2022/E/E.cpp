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
const int maxn = 1e2 + 7;

string maze[maxn] = {};

// Minotaur

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;

    for (int i=0; i<n; i++)
        cin >> maze[i];

    bool ans = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j + 7 < n) {
                string S;
                for (int k = 0; k < 8; k++)
                S.PB(maze[i][j + k]);

                if (S == "minotaur")
                    ans = false;
            }

            if (i + 7 < n) {
                string S;
                for (int k = 0; k < 8; k++)
                S.PB(maze[i + k][j]);

                if (S == "minotaur")
                    ans = false;
            }

            if (j - 7 >= 0) {
                string S;
                for (int k = 0; k < 8; k++)
                S.PB(maze[i][j - k]);

                if (S == "minotaur")
                    ans = false;
            }

            if (i - 7 >= 0) {
                string S;
                for (int k = 0; k < 8; k++)
                S.PB(maze[i - k][j]);

                if (S == "minotaur")
                    ans = false;
            }
        }
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";

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
