#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

int a[300007] = {};

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for( i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }

        vector<int> stk;
        int ans = 1;
        for( i=1; i<=n; i++) {
            if( stk.empty() )
                stk.push_back( a[i]);
            else {
                if( a[i] <= stk.back() )
                    stk.push_back( a[i]);
                else {
                    int tmp;
                    while( !stk.empty() && stk.back() < a[i])
                    {
                        tmp = stk.back();
                        stk.pop_back();
                    }
                    stk.push_back(tmp);
                }
            }
        }

        if( stk.size() <= 1)
            printf("YES\n");
        else
            printf("NO\n");
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
