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
#define ppb             pop_back
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define sm(x, y, z)     (x).begin() + y, (x).begin() + z
#define mx(x)           *max_element(all(x))
#define mn(x)           *min_element(all(x))
#define accum(x)        accumulate(all(x), 0LL)
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

ll nextPrime(ll n) {
    while (!isPrime[n])
        n++;
    
    return n;
}

vec divisorsCnt(1e6 + 1, 0);

void getDivisors() {
    for (ll i = 1; i <= (ll)(1e6 + 1); i++)
        for (ll j = i; j <= (ll)(1e6 + 1); j += i)
            divisorsCnt[j]++;
}

bool isPalindrome(string s) {
    int i = 0, j = sz(s) - 1;
    while (i < j)
        if (s[i++] != s[j--]) return false;
    
    return true;
}

vec arrayCreation(ll n) {
    vec a(n);
    for (auto& x: a)
        cin >> x;
    
    return a;
}

void solve() {
    ll n;
    cin >> n;
    
    ll sumA = 0, sumG = 0;
    string s = "";
    while (n--) {
        ll x, y;
        cin >> x >> y;
        
        if (abs((sumA + x) - sumG) <= 500) {
            s += "A";
            sumA += x;
        } else if (abs((sumG + y) - sumA) <= 500) {
            s += "G";
            sumG += y;
        } else {
            cout << -1 << nl;
            return;
        }
    }
    
    cout << s << nl;
}

int main() {
    ll t = 1;
    // cin >> t;

    generatePrimes();
    // getDivisors();
    while (t--)
        solve();
}
