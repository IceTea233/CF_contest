#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define sec second
#define INF 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

char s[100007] = {};
int ans[100007] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        scanf("%s", s+1);
        int x;
        cin >> x;
        int N = strlen(s+1);
        memset(ans, 0, sizeof(ans));
        for (i=1; i<=N; i++) {
            if ( s[i] == '0') {
                if (i-x >= 1)
                    ans[i-x] = 1;
                if (i+x <= N)
                    ans[i+x] = 1;
            }
        }

        bool flag = 0;
        for (i=1; i<=N; i++) {
            if ( s[i] == '1') {
                if (i-x >= 1 && ans[i-x] != 1)
                    ans[i-x] = 2;
                else if (i+x <= N && ans[i+x] != 1)
                    ans[i+x] = 2;
                else
                    flag = 1;
            }
        }

        de(1) printf(">>> ");
        if (flag) {
            printf("-1\n");
        } else {
            for (i=1; i<=N; i++) {
                ans[i] = max( 0LL, ans[i]-1);
            }
            for (i=1; i<=N; i++) {
                printf("%lld", ans[i]);
            }
            printf("\n");
        }
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
