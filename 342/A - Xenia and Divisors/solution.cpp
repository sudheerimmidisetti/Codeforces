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

unmp_ll_ll mp;

vec arrayCreation(ll n) {
    vec a(n);
    for (auto& x: a) {
        cin >> x;
        
        mp[x]++;
    }
    
    return a;
}

void solve() {
    ll n;
    cin >> n;
    
    vec a = arrayCreation(n);
    
    ll x = mp[4];
    ll y = mp[2] - mp[4];
    ll z = mp[3];
    if (y < 0 or (y + z) != mp[6] or (x + y + z) != mp[1] or mp[1] != (n / 3) or mp[5] or mp[7])
        cout << -1 << nl;
    else {
        for (int i = 0; i < x; i++)
            cout << "1 2 4" << nl;
        
        for (int i = 0; i < y; i++)
            cout << "1 2 6" << nl;
        
        for (int i = 0; i < z; i++)
            cout << "1 3 6" << nl;
    }
    
    mp.clear();
}

int main() {
    ll t = 1;
    // cin >> t;

    // generatePrimes();
    // getDivisors();
    while (t--)
        solve();
}
