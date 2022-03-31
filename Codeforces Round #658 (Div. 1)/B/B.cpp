#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int p[4007] = {};
bool dp[4007] = {};

int main() {

    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for( i=1; i<=2*n; i++) {
            cin >> p[i];
        }

        int cnt = 0;
        int maxi = p[1];
        vector<int> keep;
        for( i=1; i<=2*n; i++) {
            if( p[i] > maxi) {
                maxi = p[i];
                keep.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        keep.push_back(cnt);
        de(1) {
            cout << ">>> ";
            for( auto it: keep) {
                cout << it << " ";
            }
            cout << "\n";
        }

        memset( dp, 0, sizeof(int) * ( n*2 + 1) );
        dp[0] = 1;
        for( auto it: keep) {
            for( i=n; i>=it; i--) {
                if( dp[i-it])
                    dp[i] = 1;
            }
        }

        if( dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
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
