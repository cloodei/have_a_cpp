#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;

    if (y >= x) {
        cout << y - x;
        return 0;
    }

    return 0;
}
