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

unmp_ll_ll  mp;

vec arrayCreation(ll n) {
    vec a(n);
    for (auto &x : a) {
        cin >> x;
        
        mp[x]++;
    }
    
    return a;
}

ll minSwaps(string s, char x) {
    vec pos;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == x)
            pos.pb(i);
    }
    
    if (sz(pos) <= 1)
        return 0;
    
    vec v;
    for (int i = 0; i < sz(pos); i++)
        v.pb(pos[i] - i);
    
    sort(all(v));
    
    ll median = v[sz(v) / 2];
    ll swaps = 0;
    for (auto& c : v)
        swaps += abs(median - c);
    
    return swaps;
}

void solve() {
    ll n;
    cin >> n;
    
    string s;
    cin >> s;
    
    ll costOfA = minSwaps(s, 'a');
    ll costOfB = minSwaps(s, 'b');
    
    cout << min(costOfA, costOfB) << nl;
}

int main() {
    ll t = 1;
    cin >> t;

    while (t--)
        solve();
}
