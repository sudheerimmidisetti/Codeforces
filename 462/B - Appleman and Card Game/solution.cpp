#include <bits/stdc++.h>
using namespace std;

using ll            = long long;
using vec           = vector<ll>;
using vecStr        = vector<string>;
using vecChr        = vector<char>;
using vecBool       = vector<bool>;
using vec2d         = vector<vec>;
using vecP_ll_ll    = vector<pair<ll, ll>>;
using vecP_ll_str   = vector<pair<ll, string>>;
using unmp_ll_ll    = unordered_map<ll, ll>;
using unmp_chr_ll   = unordered_map<char, ll>;
using unmp_str_ll   = unordered_map<string, ll>;
using st_ll         = set<ll>;
using st_chr        = set<char>;
using st_str        = set<string>;
using que_ll        = queue<ll>;
using queP          = queue<pair<ll, ll>>;

#define pb          push_back
#define pp          pop_back
#define ff          first
#define ss          second
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define rev(x)      (x).begin(), (x).end()
#define sz(x)       (int)(x).size()
#define nl          endl

const ll MOD        = 1e9 + 7;
const ll INF        = LLONG_MAX;
const ll NINF       = LLONG_MIN;

vec arrayCreation(ll n) {
    vec a(n);
    for (auto &x : a)
        cin >> x;
    
    return a;
}
 
void solve() {
    ll n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    unmp_chr_ll mp;
    for (auto& c : s)
        mp[c]++;
    
    vec v;
    for (auto& x : mp)
        v.pb(x.ss);
    
    sort(rall(v));
    
    ll maxCoins = 0;
    for (int i = 0; i < sz(v); i++) {
        if (v[i] >= k) {
            maxCoins += k * k;
            break;
        }
        
        k -= v[i];
        maxCoins += (v[i] * v[i]);
    }
    
    cout << maxCoins << nl;
}

int main() {
    ll t = 1;
    // cin >> t;

    while (t--)
        solve();
}
