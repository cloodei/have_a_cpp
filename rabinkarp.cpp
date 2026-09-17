#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

const ll base = 257, MOD = 1'000'000'003;
ll hb = 0, ha[1'048'576], powow[1'048'576];

ll gha(ll l, ll r) {
    return (ha[r] - ha[l - 1] * powow[r - l + 1] + MOD * MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 0; i < 1'048'576; ++i)
        ha[i] = powow[i] = 0;

    powow[0] = 1;
    for (ll i = 1; i <= b.length() - 1; ++i)
        hb = (hb * base + b[i] - 'a' + 1) % MOD;
    for (ll i = 1; i <= a.length() - 1; ++i) {
        powow[i] = (powow[i - 1] * base) % MOD;
        ha[i] = (ha[i - 1] * base + a[i] - 'a' + 1) % MOD;
    }

    for (ll i = 1; i <= (a.length() - b.length()) + 1; ++i)
        if (hb == gha(i, i + b.length() - 2))
            cout << i << " ";

    return 0;
}
