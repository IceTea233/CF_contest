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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int cnt[27] = {};

int32_t main() {
    int i,j;
    int T;

    cin >> T;
    while (T--) {
        memset(cnt, 0 ,sizeof(cnt));
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i=0; i<n; i++)
            cnt[s[i]-'a']++;

        de(1) {
            for (int i=0; i<26; i++)
                printf("%lld ", cnt[i]);
            printf("\n");
        }

        bool flag = 0;
        int fix = 0;
        for (i=n-1; i>=0; i--) {
            if (i < n-1) {
                cnt[s[i]-'a']--;
                cnt[s[i]-'a'+1]++;
                s[i]++;
            }
            // printf("i = %lld\n", i);
            while (s[i] <= 'z') {
                de(1) cout << s << "\n";
                int tt = 0;
                for (int j=0; j<26; j++) {
                    tt += (k - cnt[j] % k) % k;
                }
                de(2) printf("i = %lld\n", i);
                de(2) printf("tt = %lld\n", tt);
                if (tt <= n-1-i && (n-1-i - tt) % k == 0) {
                    // de(1) printf("win\n");
                    flag = 1;
                    fix = n-1-i - tt;
                    break;
                }
                cnt[s[i]-'a']--;
                if (s[i] + 1 <= 'z') {
                    cnt[s[i]-'a'+1]++;
                    s[i]++;
                } else {
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag) {
            cout << "-1\n";
            continue;
        }

        while (fix--) {
            s[++i] = 'a';
        }
        for (i++, j=0; i<=n; i++) {
            while (cnt[j] % k == 0 && j < 26) {
                j++;
            }
            // printf("j = %lld\n", j);
            if (j == 26)
                break;
            s[i] = 'a' + j;
            cnt[j]++;
        }
        cout << s << "\n";
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
