#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int n;
int a[1007] = {};
int cht[1007] = {};
bool v[1007] = {};
vector<int> ans;

struct item {
    int pos;
    int val;

    bool operator<( item b) {
        if( val == b.val)
            return pos < b.pos;
        return val > b.val;
    }
};

int op( int idx) {
    memset( cht, 0, sizeof(cht));
    ans.push_back(idx);
    for( int i=1; i<=n; i++) {
        cht[ a[i] ] = 1;
    }

    for( int i=0; i<=n; i++) {
        if( !cht[i]) {
            a[idx] = i;
            return i;
        }
    }

    return -1;
}

int gen() {
    int i;
    for( i=n; i>=1; i--) {
        if( !v[i])
            return i;
    }
    return -1;
}

int query() {
    memset( cht, 0, sizeof( cht));
    for( int i=1; i<=n; i++) {
        cht[ a[i] ] = 1;
    }
    for( int i=0; i<=n; i++) {
        if( !cht[i])
            return i;
    }
    return -1;
}

void show() {
    printf(">>> ");
    for( int i=1; i<=n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {

        memset( v, 0, sizeof(v));
        ans.clear();
        scanf("%d", &n);
        for( i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        bool flag;
        do {

            de(1) show();
            flag = 1;
            int idx = query();
            if( idx == n) {
                flag = 0;
                for( i=1; i<=n; i++) {
                    if( a[i] != i-1) {
                        op(i);
                        flag = 1;
                        break;
                    }
                }
            }
            else
                op(idx+1);
        } while( flag);

        printf("%d\n", ans.size());
        for( auto it:ans) {
            printf("%d ", it);
        }
        printf("\n");
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
