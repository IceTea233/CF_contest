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

int query(int a, int b, int c) {
    printf("? %lld %lld %lld\n", a, b, c);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    return ret;
}

void answer(int ans, vector<int> &keep) {
    printf("! %lld", ans);
    for (auto it : keep) {
        printf(" %lld", it);
    }
    printf("\n");
    fflush(stdout);
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    scanf("%lld", &t);
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector<int> good_cand;
        vector<int> bad_cand;
        for (int i=0; i < n / 3; i++) {
            int a = i * 3 + 1;
            int b = i * 3 + 2;
            int c = i * 3 + 3;
            int q = query(a, b, c);
            if (q == 1) {
                good_cand.PB(i);
            } else {
                bad_cand.PB(i);
            }
        }

        int good = 0;
        int bad = 0;
        vector<int> keep;
        if (good_cand.size() > bad_cand.size()) {
            for (int i = 0; i < bad_cand.size(); i++) { // hold 2 good to test bad
                for (int j=1; j<=3; j++) {
                    int q = query(good_cand[0] * 3 + 1, good_cand[0] * 3 + 2, bad_cand[i] * 3 + j);
                    if (q == 0) {
                        bad = bad_cand[i] * 3 + j;
                        break;
                    }
                }
                if (!bad)
                    break;
            }

            if (bad) {
                good = good_cand[0] * 3 + 3;
            } else {
                good = good_cand[0] * 3 + 1;
                set<int> tmp;
                if (       query(good, bad_cand[0] * 3 + 2, bad_cand[0] * 3 + 3) == 1) {
                    bad = bad_cand[0] * 3 + 1;
                } else if (query(good, bad_cand[0] * 3 + 1, bad_cand[0] * 3 + 3) == 1) {
                    bad = bad_cand[0] * 3 + 2;
                } else if (query(good, bad_cand[0] * 3 + 1, bad_cand[0] * 3 + 2) == 1) {
                    bad = bad_cand[0] * 3 + 3;
                } else {
                    bad = bad_cand[0] * 3 + 1;
                }
            }
        } else {
            for (int i = 0; i < good_cand.size(); i++) { // hold 2 bad to test bad
                for (int j=1; j<=3; j++) {
                    int q = query(bad_cand[0] * 3 + 1, bad_cand[0] * 3 + 2, good_cand[i] * 3 + j);
                    if (q == 0) {
                        good = good_cand[i] * 3 + j;
                        break;
                    }
                }
                if (!good)
                    break;
            }

            if (good) {
                bad = bad_cand[0] * 3 + 3;
            } else {
                bad = bad_cand[0] * 3 + 1;
                set<int> tmp;
                if (       query(bad, good_cand[0] * 3 + 2, good_cand[0] * 3 + 3) == 1) {
                    good = good_cand[0] * 3 + 1;
                } else if (query(bad, good_cand[0] * 3 + 1, good_cand[0] * 3 + 3) == 1) {
                    good = good_cand[0] * 3 + 2;
                } else if (query(bad, good_cand[0] * 3 + 1, good_cand[0] * 3 + 2) == 1) {
                    good = good_cand[0] * 3 + 3;
                } else {
                    good = good_cand[0] * 3 + 1;
                }
            }
        }
        // printf("bad = %lld\n", bad);
        // printf("bad = %lld\n", bad);
        for (int i=1; i<=n; i++) {
            if (i == bad) {
                keep.PB(i);
            } else if (i == bad) {
                // ignore
            } else {
                int q = query(bad, bad, i);
                if (q == 0)
                    keep.PB(i);
            }
        }

        answer(keep.size(), keep);
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
