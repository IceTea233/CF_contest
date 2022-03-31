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

void display(vector<int> &arr) {
    for (auto it : arr)
        printf("%lld", it);
    printf("\n");
}

int32_t main() {
    int i,j;
    int a,b,k;

    cin >> a >> b >> k;
    if (a == 0) {
        if (k == 0) {
            printf("Yes\n");
            for (int i=0; i<b; i++)
                printf("1");
            printf("\n");
            for (int i=0; i<b; i++)
                printf("1");
            printf("\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
    else if (b == 1) {
        if (k == 0) {
            printf("Yes\n");
            printf("1");
            for (int i=0; i<a-1; i++) {
                printf("0");
            }
            printf("\n");
            printf("1");
            for (int i=0; i<a-1; i++) {
                printf("0");
            }
            printf("\n");
        } else {
            printf("No\n");
        }
        return 0;
    }
    if (k == 0) {
        printf("Yes\n");
        for (int i=0; i<b; i++)
            printf("1");
        for (int i=0; i<a; i++)
            printf("0");
        printf("\n");
        for (int i=0; i<b; i++)
            printf("1");
        for (int i=0; i<a; i++)
            printf("0");
        printf("\n");
        return 0;
    }

    if (k == a+b || k == a+b-1)
        printf("No\n");
    else {
        vector<int> x;
        for (int i=0; i<b; i++)
            x.PB(1);
        for (int i=0; i<a; i++)
            x.PB(0);

        vector<int> y(a+b, 0);
        if (k == 0) {
            y = x;
        } else {
            int now = b-1;
            if (now >= k) {
                y[0] = 1;
                int idx = 1;
                for (int i=0; i<now-k; i++, idx++) {
                    y[idx] = 1;
                }
                y[idx++] = 0;
                while (idx <= b) {
                    y[idx++] = 1;
                }
                while (idx < a + b) {
                    y[idx++] = 0;
                }
            } else {
                y[0] = 1;
                int idx = b + (k - now);
                y[idx] = 1;
                for (int i=1; idx+i < a+b; i++)
                    y[idx+i] = 0;
                for (int i=1; i <= b-2; i++) {
                    y[b-i] = 1;
                }
            }

            printf("Yes\n");
            display(x);
            display(y);
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
