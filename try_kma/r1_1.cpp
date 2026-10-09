#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, sum = 0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); ++i)
        if (n % i == 0)
            sum += (i * i == n) ? 1 : 2;

    cout << sum;
    return 0;
}
