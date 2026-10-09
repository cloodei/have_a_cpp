#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

using ll = long long;

struct thing {
    ll a, b, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<thing> a(n + 1), dp(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i].a >> a[i].b >> a[i].c;

    for (int i = 0; i < n; ++i) {
        dp[i + 1].a = max(dp[i].b + a[i].a, dp[i].c + a[i].a);
        dp[i + 1].b = max(dp[i].a + a[i].b, dp[i].c + a[i].b);
        dp[i + 1].c = max(dp[i].a + a[i].c, dp[i].b + a[i].c);
    }

    cout << max(max(dp[n].a, dp[n].b), dp[n].c);
    return 0;
}
