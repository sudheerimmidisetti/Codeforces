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
    ll n;
    cin >> n;

    ll divisionCnt = 0, numCnt = 0;
    string str = "";
    while (n > 0) {
        if (n % 10 != 0) {
            str += to_string((n % 10) * (ll) pow(10, divisionCnt)) + " ";
            numCnt++;
        }

        n /= 10;
        divisionCnt++;
    }

    cout << numCnt << endl;
    cout << str << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        solve();
    }
}
