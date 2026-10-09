#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

constexpr int n = 10'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> primes(n + 3);
    primes[0] = primes[1] = false;
    for (int i = 2; i < n; ++i)
        primes[i] = true;

    for (int i = 2; i * i <= n; ++i)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;

    int sum = 0;
    for (int i = 1; i < n; ++i)
        if (primes[i] == true)
            sum++;

    cout << sum;
    return 0;
}
