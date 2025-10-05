#include <bits/stdc++.h>
using namespace std;

using ll                = long long;
using vec               = vector<ll>;
using vec2d             = vector<vec>;
using vecStr            = vector<string>;
using vecStr2d          = vector<vecStr>;
using vecChr            = vector<char>;
using vecChr2d          = vector<vecChr>;
using vecBool           = vector<bool>;
using vecP_ll_ll        = vector<pair<ll, ll>>;
using vecP_ll_str       = vector<pair<ll, string>>;
using unmp_ll_ll        = unordered_map<ll, ll>;
using unmp_chr_ll       = unordered_map<char, ll>;
using unmp_str_ll       = unordered_map<string, ll>;
using st_ll             = set<ll>;
using st_chr            = set<char>;
using st_str            = set<string>;
using que_ll            = queue<ll>;
using queP              = queue<pair<ll, ll>>;

#define pb              push_back
#define pp              pop_back
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define sm(x, y, z)     (x).begin() + y, (x).begin() + z
#define sz(x)           (int)(x).size()
#define nl              endl

const ll MOD            = 1e9 + 7;
const ll INF            = LLONG_MAX;
const ll NINF           = LLONG_MIN;

vecBool isPrime(1e6 + 10, true);

void generatePrimes() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= (ll)(1e6 + 10); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= (ll)(1e6 + 10); j += i)
                isPrime[j] = false;
        }
    }
}

vec arrayCreation(ll n) {
    vec a(n);
    for (auto& x: a)
        cin >> x;

    return a;
}

unmp_str_ll months = {{"01", 31}, {"02", 28}, {"03", 31}, {"04", 30}, {"05", 31}, {"06", 30}, {"07", 31}, {"08", 31}, {"09", 30}, {"10", 31}, {"11", 30}, {"12", 31}};

void solve() {
    string s;
    cin >> s;
    
    unmp_str_ll mp;
    for (int i = 0; i <= sz(s) - 10; i++) {
        string dt = s.substr(i, 10);
        
        if(dt[2] == '-' and dt[5] == '-') {
            string dd = dt.substr(0, 2), mm = dt.substr(3, 2), yy = dt.substr(6, 4);
            
            if (dd[0] == '-' or dd[1] == '-')
                continue;
            
            if (mm[0] == '-' or mm[1] == '-')
                continue;
            
            if (yy[0] == '-' or yy[1] == '-' or yy[2] == '-' or yy[3] == '-')
                continue;
            
            if (months[mm] >=  stoi(dd) && stoi(dd) > 0) {
                if (yy[0] == '2' && yy[1] == '0' && yy[2] == '1' && yy[3] >= '3' && yy[3] <= '5')
                    mp[dt]++;
            }
        }
    }
    
    ll maxCnt = NINF;
    string date;
    for (auto const& [c, cnt] : mp) {
        if (maxCnt < cnt) {
            maxCnt = cnt;
            date = c;
        }
    }
    
    cout << date << nl;
}

int main() {
    ll t = 1;
    // cin >> t;

    // generatePrimes();
    while (t--)
        solve();
}
