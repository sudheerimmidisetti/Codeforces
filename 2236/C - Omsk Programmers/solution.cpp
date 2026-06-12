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
using mp_ll_ll          = map<ll, ll>;
using mp_chr_ll         = map<char, ll>;
using mp_str_ll         = map<string, ll>;
using st_ll             = set<ll>;
using st_chr            = set<char>;
using st_strh            = set<string>;
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
    ll a, b, x;
    cin >> a >> b >> x;
 
    vector<pair<ll, ll>> v1, v2;
 
    ll curr = a, cnt = 0;
    while (1) {
        v1.pb({curr, cnt});
        if (curr == 0) break;
        curr /= x;
        cnt++;
    }
 
    curr = b, cnt = 0;
    while (1) {
        v2.pb({curr, cnt});
        if (curr == 0) break;
        curr /= x;
        cnt++;
    }
 
    ll minCnt = INF;
 
    for (auto &[x1, cnt1] : v1) {
        for (auto &[x2, cnt2] : v2)
            minCnt = min(minCnt, cnt1 + cnt2 + abs(x1 - x2));
    }
 
    cout << minCnt << nl;
}
 
int main() {
    ll t = 1;
    cin >> t;
 
    while (t--)
        solve();
}