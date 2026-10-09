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

    int n;
    cin >> n;

    vector<int> a(n), dp(n + 2);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp[1] = abs(a[0] - a[1]);
    for (int i = 2; i < n; ++i)
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));

    cout << dp[n - 1];
    return 0;
}
