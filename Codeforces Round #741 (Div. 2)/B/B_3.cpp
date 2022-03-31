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
const int maxn = 1e4 + 7;

vector<int> prm;
bool isprm[maxn] = {};
void prepare() {
    prm.PB(2);
    isprm[2] = true;
    for (int i=3; i<maxn; i++) {
        bool flag = false;
        for (int j=0; prm[j] * prm[j] <= i; j++) {
            if (i % prm[j] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            isprm[i] = true;
            prm.PB(i);
        }
    }
}

bool chk(string &s, int x) {
    for (int i=s.size()-1; i>=0 && x; i--) {
        if (s[i]-'0' == x % 10) {
            x /= 10;
        }
    }

    return x == 0;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    prepare();
    while (t--) {
        int k;
        cin >> k;
        string n;
        cin >> n;

        string ans;
        for (int i=1; i<maxn; i++) {
            if (!isprm[i] && chk(n, i)) {
                ans = to_string(i);
                break;
            }
        }

        // printf("ans : ");
        printf("%d\n", ans.size());
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
