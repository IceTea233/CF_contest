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
const int maxn = 5e5 + 7;

struct link {
    int id;
    int l;
    int r;
    int val;
};

struct info {
    int id;
    int l;
    int r;
    int val;
    int type;
    list<link>::iterator ptr;
    int ver;
};

bool operator<(info a, info b) {
    return a.val < b.val;
}

void insert_info(list<link> &keep, list<link>::iterator &it, priority_queue<info> &pq, vector<int> &tag) {
    if (it != keep.begin()) {
        pq.push({it->id, it->l, it->r, prev(it)->val + it->val, 1,
                 it, tag[it->id]});
        tag[prev(it)->id] = tag[it->id];
    }
    if (next(it) != keep.end()) {
        pq.push({it->id, it->l, it->r, next(it)->val + it->val, 2,
                 it, tag[it->id]});
        tag[next(it)->id] = tag[it->id];
    }
    // if (it != keep.begin() && next(it) != keep.end()) {
    //     pq.push({it->id, it->l, it->r, prev(it)->val + next(it)->val + it->val, 3,
    //              it, tag[it->id]});
    //     tag[prev(it)->id] = tag[it->id];
    //     tag[next(it)->id] = tag[it->id];
    // }
}

int eval(link &x) {
    if (x.val > 0)
        return x.r - x.l + 1;
    else if (x.val < 0)
        return -(x.r - x.l + 1);
    else
        return 0;
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1, 0);
        vector<int> tag(n + 1, 0);

        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        list<link> keep;
        priority_queue<info> pq;

        int clk = 0;
        for (int i=1; i<=n; i++) {
            keep.PB({i, i, i, a[i]});
            tag[i] = ++clk;
        }

        int tt = 0;
        for (auto it = keep.begin(); it != keep.end(); it++) {
            tt += eval(*it);
            insert_info(keep, it, pq, tag);
        }

        int ans = tt;
        while (!pq.empty()) {
            info cur = pq.top();
            pq.pop();
            if (cur.ver != tag[cur.id])
                continue;

            auto it = cur.ptr;
            tt -= eval(*it);

            it->val = cur.val;
            tag[it->id] = ++clk;

            de(1) printf(">>> type %lld\n", cur.type);
            if (cur.type == 1) {
                tt -= eval(*prev(it));
                it->l = prev(it)->l;
                tag[prev(it)->id] = -1;
                keep.erase(prev(it));
            } else if (cur.type == 2) {
                tt -= eval(*next(it));
                it->r = next(it)->r;
                tag[next(it)->id] = -1;
                keep.erase(next(it));
            }
            // } else if (cur.type == 3) {
            //     tt -= eval(*prev(it));
            //     tt -= eval(*next(it));
            //     it->l = prev(it)->l;
            //     it->r = next(it)->r;
            //     tag[prev(it)->id] = -1;
            //     keep.erase(prev(it));
            //     tag[next(it)->id] = -1;
            //     keep.erase(next(it));
            // }
            insert_info(keep, it, pq, tag);
            tt += eval(*it);
            de(1) {
                for (auto it : keep) {
                    printf("(%lld, %lld, %lld, %lld) ", it.id, it.l, it.r, it.val);
                }
                printf(">>> %lld\n", tt);
            }

            ans = max(tt, ans);

        }

        printf("%lld\n", ans);
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
