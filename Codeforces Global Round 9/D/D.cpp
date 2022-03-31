#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
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

int main() {

    int i,j;
    int t;

    scanf("%d", &t);
    while(t--) {

        memset( v, 0, sizeof(v));
        ans.clear();
        scanf("%d", &n);

        vector<item> keep;
        for( i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            cht[ a[i] ] = 1;
            keep.push_back({ i, a[i]});
        }
        sort( begin(keep), end(keep) );

        for( i=0; i<n; i++) {
            bool flag = 0;
            memset(cht,0, sizeof(cht));
            for( j=1; j<=n; j++) {
                cht[ a[j] ] = 1;
            }
            for( j=0; j<n; j++) {
                if( !cht[j])
                    flag = 1;
            }
            if(flag)
                op( keep[i].pos);
            else
                break;

            de(1) {
                printf(">>> ");
                for( j=1; j<=n; j++)
                    printf("%d ", a[j]);
                printf("\n");
            }
        }

        de(1) printf("\n");


        int idx = n;
        v[n] = 1;
        for( i=n; i>=1; i--) {
            if( a[idx] == 0) {
                op(idx);
                v[idx] = 1;
                idx = gen();
            }
            else {
                if( a[idx] == idx) {
                    de(1) printf("YEE\n");
                    idx = gen();
                }
                int tmp = a[idx];
                op(idx);
                v[idx] = 1;
                idx = tmp;
            }



            de(1) {
                printf(">>> ");
                for( j=1; j<=n; j++)
                    printf("%d ", a[j]);
                printf("\n");
            }
        }

        for( i=1; i<=n; i++) {
            if( a[i] == 0) {
                op(i);
                de(1) {
                    printf(">>> ");
                    for( j=1; j<=n; j++)
                        printf("%d ", a[j]);
                    printf("\n");
                }
            }
        }

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
