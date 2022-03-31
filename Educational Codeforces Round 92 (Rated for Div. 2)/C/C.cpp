#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int main() {

    int i,j;
    int t;

    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int ans = ULTRA;
        for( i='0'; i<='9'; i++) {
            int cnt = 0;
            for( j=0; j<s.size(); j++) {
                if( s[j] != i)
                    cnt++;
            }
            ans = min( ans, cnt);
        }

        for( i='0'; i<='9'; i++) {
            for( j='0'; j<='9'; j++) {
                char c[2];
                c[0] = i;
                c[1] = j;
                bool now = 0;
                int cnt = 0;
                for( int k=0; k<s.size(); k++) {
                    if( s[k] == c[now])
                        now ^= 1;
                    else
                        cnt++;
                }
                if( now)
                    cnt++;
                ans = min( ans, cnt);
            }
        }

        cout << ans << "\n";
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
