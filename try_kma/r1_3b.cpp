#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

using ll = long long;

ll n;

unordered_set<ll> thing1, thing2, thing3, thing5;
ll P357(ll x, unordered_set<ll>& thing) {
    if (x >= n || thing.count(x))
        return 0;

    thing.insert(x);
    return x + P357(x * 3 + 1, thing) + P357(x * 5 + 1, thing) + P357(x * 7 + 1, thing);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n < 4) {
        cout << n;
        return 0;
    }

    cout << max(max(max(P357(1, thing1), P357(2, thing2)), P357(3, thing3)), P357(5, thing5));
    return 0;
}
