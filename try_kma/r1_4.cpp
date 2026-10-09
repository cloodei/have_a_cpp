#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

constexpr ll MOD = 1'000'000'000;
ll g(ll x) {
    return ((x * x) % MOD) + ((2 * x) % MOD) + 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    for (ll i = 0; i < n; ++i)
        x = g(x) % MOD;

    cout << x % MOD;
    return 0;
}
