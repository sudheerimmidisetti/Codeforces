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
#define sz(x)           (int)(x).size()

vec arrayCreation(ll n) {
    vec a(n);
    for (auto &x: a) cin >> x;

    return a;
}

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;
    
    unmp_chr_ll mp, mp2;
    for (auto &c: s) 
        mp[c]++;
    
    ll maxDistincts = 0;
    for (auto &c: s)  {
        mp[c]--;
        mp2[c]++;
        
        if(mp[c] == 0)
            mp.erase(c);
        
        maxDistincts = max(maxDistincts, (ll)(sz(mp) + sz(mp2)));
    }
    
    cout << maxDistincts << endl;
}

int main() {
    ll t = 1;
    cin >> t;

    while (t--)
        solve();
}
