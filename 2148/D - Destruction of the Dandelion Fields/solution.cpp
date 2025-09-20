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
#define vecP_ll_ll      vector<pair<ll, ll>>
#define vecP_ll_str     vector<pair<ll, string>>
#define queLl           queue<ll>
#define queP            queue<pair<ll, ll>>
#define unmp_ll_ll      unordered_map<ll, ll>
#define unmp_ll_chr     unordered_map<ll, char>
#define unmp_chr_ll     unordered_map<char, ll>
#define unmp_str_ll     unordered_map<string, ll>
#define unmp_str_str    unordered_map<string, string>
#define stChr           set<char>
#define pb              push_back
#define pp              pop_back
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define rev(x)          (x).begin(), (x).end()
#define sz(x)           (int)(x).size()

vec arrayCreation(ll n) {
    vec a(n);
    for (auto &x : a) cin >> x;

    return a;
}

void solve() {
    ll n;
    cin >> n;

    vec even, odd;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (x % 2 == 0)
            even.pb(x);
        else
            odd.pb(x);
    }

    if (sz(odd) == 0)
        cout << 0 << endl;
    else {
        sort(rall(odd));

        ll maxCuts = 0;
        for (auto & x: even)
            maxCuts += x;

        if(sz(odd) == 1) {
            maxCuts += odd[0];
        } else {
            if (sz(odd) % 2 == 0) {
                for (int i = 0; i < sz(odd) / 2; i++) {
                    maxCuts += odd[i];
                }
            } else {
                for (int i = 0; i < (sz(odd) + 1) / 2; i++) {
                    maxCuts += odd[i];
                }
            }
        }

        cout << maxCuts << endl;
    }
}

int main() {
    ll t = 1;
    cin >> t;

    while (t--)
        solve();
}
