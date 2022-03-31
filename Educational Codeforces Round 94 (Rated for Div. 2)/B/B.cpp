#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int p,f;
        cin >> p >> f;
        int cnt_s, cnt_w;
        cin >> cnt_s >> cnt_w;
        int s, w;
        cin >> s >> w;
        if (s > w) {
            swap( cnt_s, cnt_w);
            swap( s, w);
        }

        int ans = 0;
        for (i=0; i<=cnt_s; i++) {
            if (s*i > p)
                break;
            int tt = i;
            int rem_s = cnt_s - i;
            tt += min( ( p - s*i ) / w, cnt_w);
            int rem_w = cnt_w - min( ( p - s*i ) / w, cnt_w);
            de(1) printf("i = %lld >>> ( %lld, %lld)\n", i, rem_s, rem_w);

            tt += min( f/s, rem_s);
            int rem_f = f - s * min( f/s, rem_s);
            tt += min( rem_f / w, rem_w);

            de(1) printf("i = %lld >>> %lld\n", i, tt);
            ans = max( tt, ans);
        }
        printf("%lld\n", ans);

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
