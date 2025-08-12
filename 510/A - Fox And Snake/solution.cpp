#include <bits/stdc++.h>
using namespace std;

#define ll              long long
#define mod             1e9 + 7
#define inf             9223372036854775807
#define ninf            -9223372036854775808
#define vec             vector<ll>
#define vecStr          vector<string>
#define vecChr          vector<char>
#define vecBool         vector<bool>
#define vec2d           vector<vector<ll>>
#define vecP            vector<pair<ll, ll>>
#define queLl           queue<ll>
#define queP            queue<pair<ll, ll>>
#define unmp_ll_ll      unordered_map<ll, ll>
#define unmp_chr_ll     unordered_map<char, ll>
#define unmp_str_ll     unordered_map<string, ll>
#define pb              push_back
#define pp              pop_back
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define sz(x)           (int)(x).size()

void solve() {
    ll n, m;
    cin >> n >> m;

    ll oddCnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0)
                cout << "#";
            else if ((oddCnt % 2 == 0 && j == 0) || (oddCnt % 2 != 0 && j == m - 1))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
        oddCnt = i % 2 != 0 ? oddCnt + 1 : oddCnt;
    }
}

int main() {
    while (true) {
        solve();
        break;
    }
}
