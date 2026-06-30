#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vec = vector<ll>;
 
#define nl '
'
 
vec arrayCreation(ll n) {
    vec a(n);
    for (auto &x : a) cin >> x;
    return a;
}
 
void solve() {
    ll n;
    cin >> n;
 
    vec a = arrayCreation(n), b = arrayCreation(n);
 
    ll currSum = 0;
    bool can = true;
 
    for (ll i = 0; i < n; i++) {
        currSum += (b[i] - a[i]);
 
        if (currSum < 0) {
            can = false;
            break;
        }
    }
 
    cout << (can ? "YES" : "NO") << nl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) solve();
}