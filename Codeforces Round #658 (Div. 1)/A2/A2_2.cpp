#include<bits/stdc++.h>
#define LLI long long int
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 1
using namespace std;

string a, b;

bool flag = 0;
int idx1;
int idx2;
int head() {
    if( flag) {
        return a[idx2] == '0' ? '1' : '0';
    }
    else {
        return a[idx1];
    }
}
int rear() {
    if( flag) {
        return a[idx1] == '0' ? '1' : '0';
    }
    else {
        return a[idx2];
    }
}

void move() {
    if( flag)
        idx1++;
    else
        idx2--;
}

int main() {

    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        idx1 = 0;
        idx2 = n-1;
        cin >> a;
        cin >> b;

        vector<int> ans;
        for( i=n-1; i>=0; i--) {
            if( rear() == b[i])
                continue;
            if( head() == b[i]) {
                ans.push_back(1);
            }
            ans.push_back(i+1);
            move();
            flag ^= 1;
        }
        cout << ans.size() << " ";
        for( auto it:ans) {
            cout << it << " ";
        }
        cout << "\n";
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
