#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<LLI,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

LLI a[200007];
int l[200007];
int r[200007];

void link( int a, int b) {
    r[a] = b;
    l[b] = a;
}

int main() {

    int i,j;
    int n;

    cin >> n;
    for( i=0; i<n; i++) {
        cin >> a[i];
    }

    for( i=0; i<n; i++) {
        l[i] = ( i-1+n ) % n;
        r[i] = ( i+1 ) % n;
    }

    set<pii> st;
    for( i=0; i<n; i++)
        st.insert( { a[i], i});
    for( i=0; i<n/2; i++) {
        int now = st.begin() -> sec;
        int left = l[now];
        int right = r[now];

        st.erase( { a[now], now});
        st.erase( { a[left], left});
        st.erase( { a[right], right});

        a[now] = a[ left ] + a[ right ];
        a[ left ] = -1;
        a[ right] = -1;

        st.insert( { a[now], now});
        link( l[ left ], now);
        link( now, r[ right ]);
    }

    LLI ans = st.begin()->fst;
    cout << ans << "\n";

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
