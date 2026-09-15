#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;

    while (b) {
        long long q = a / b;
        int t = x1;
        x1 = x - q * x1;
        x = t;
        t = y1;
        y1 = y - q * y1;
        y = t;
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 47, b = 18, x, y;
    cout << gcd(a, b, x, y) << " and x y = " << x << " " << y;
    return 0;
}
