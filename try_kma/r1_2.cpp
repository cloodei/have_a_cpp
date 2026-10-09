#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

using ll = long long;

unordered_map<ll, ll> marp;

ll thing(ll n) {
    if (n < 3)
        return n;

    if (marp.find(n) != marp.end())
        return marp[n];

    ll k = n / 3;
    if (n % 3 == 0)
        return marp[n] = thing(k * 2);
    if (n % 3 == 1)
        return marp[n] = thing(k * 2) + thing(k * 2 + 1);

    return marp[n] = thing(k * 2) + thing(k * 2 + 1) + thing(k * 2 + 2);
}

int main() {
    ll asdf;
    cout << "Nhap n = ";
    cin  >> asdf;
    ll ans = thing(asdf);
    cout << "f(" << asdf << ") = " << ans;

    return 0;
}
